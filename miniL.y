%{
    /* C declarations */ 
    #include <stdio.h> 
    #include <stdlib.h> 
    #include <iostream>
    #include <string>
    #include <string.h>
    #include <fstream>
    #include <sstream>
    #include <map>
    #include <stack>

    using namespace std;

    enum symbol_type {INT, INTARRAY, FUNC};

    struct Func {
      string name;
      Func(): name() {}
      Func(string n) : name(n){}
    };

    struct Sym {
      int val;
      int size;
      string name;
      symbol_type type; 
      Sym():val(0),size(0),name(),type() {}
      Sym(int v, int s, string n, symbol_type t) :val(v), size(s), name(n), type(t) {}
  };

    void yyerror(const char *msg); 
    int yylex(void);
    extern int currLine; 
    extern int currPos; /* variables defined in .lex file */ 
    extern FILE * yyin; 

    stack<string> param_stack; 
    stack<string> ident_stack;
    stack<string> var_stack;
    stack<string> exp_stack; 
    stack<string> label_stack;
    int param_cnt = 0;
    int temp_tot = 0;
    int label_tot = 0;

    void add_symbol_to_symbol_table(Sym sym);
    void add_function_to_func_table(Func func);
    void check_symbol(string name);
    void check_func(string name);
    string makeTemp();
    string makeLabel();

    stringstream string_codes;
    ostringstream file_codes;

    map<string, Sym> symbol_table;
    map<string, Func> func_table;
    
    bool main_exists = 0;
    bool error_exists = 0;
%}

%union{ 
    char * identVal; 
    int numVal; 
    struct attributes {
      char name[255];
      char index[255];
      int type; //0 = int, 1 = int array, 2 = function
      int val;
    } attrVal;
} 

%error-verbose 
%start Program /* begin processing top-level component */ 
%token FUNCTION
%token BEGIN_PARAMS END_PARAMS 
%token BEGIN_LOCALS END_LOCALS
%token BEGIN_BODY END_BODY 
%token INTEGER ARRAY OF 
%token IF THEN ELSE ENDIF
%token WHILE DO BEGINLOOP ENDLOOP CONTINUE
%token READ WRITE
%token AND OR NOT TRUE FALSE RETURN
%token SUB ADD MULT DIV MOD 
%token EQ NEQ LT GT LTE GTE
%token COMMA COLON SEMICOLON 
%token  L_SQUARE_BRACKET R_SQUARE_BRACKET L_PAREN R_PAREN  
%token  ASSIGN 

%left  MULT DIV MOD ADD SUB
%left  GT GTE LT LTE EQ NEQ
%right NOT
%left AND OR
%right ASSIGN

%token <numVal> NUMBER
%token <identVal> IDENT

%type <attrVal> Var Expression Term Declaration Statement Multi_Expr Bool_Expr Relation_And_Expr Relation_Expr Rel_Expr_Ex_Not
%type <identVal> Comp

%% 
/* Program */
Program:            FunctionList 
                    {if(!main_exists){yyerror("Main function not declared");}}

FunctionList:       Function FunctionList
                    |  /*epsilon*/ 
                    ;

Function:           FUNCTION IDENT 
                    {
                      string_codes << "func " << string($2) << endl;
                      Func f($2);
                      add_function_to_func_table(f);
                    } SEMICOLON BEGIN_PARAMS 
                    DeclarationList {
                        while (!param_stack.empty()){
                          string_codes << "= " << param_stack.top() << ", " << "$" << param_cnt++ << endl;
                          param_stack.pop();
                        }
                    }
                    END_PARAMS 
                    BEGIN_LOCALS DeclarationList END_LOCALS 
                    BEGIN_BODY StatementList END_BODY 
                    {
                      file_codes << "endfunc\n\n";
                      symbol_table.clear();
                      if (strcmp($2, "main")==0) {
                        main_exists = 1;      
                      }
                      while (!param_stack.empty()) {
                        param_stack.pop();
                      }
                    }
                    ;

DeclarationList:    Declaration SEMICOLON DeclarationList 
                    | /*epsilon*/ 
                    ;    

Declaration:        IDENT IdentifierList COLON INTEGER {
                        ident_stack.push($1);
                        param_stack.push($1);
                        while(!ident_stack.empty()) {
                          string temp = ident_stack.top();
                          Sym sym(0,0,temp,INT); 
                          add_symbol_to_symbol_table(sym);
                          string_codes << ". " << temp << endl;
                        ident_stack.pop(); 
                        }
                    }
                    | IDENT IdentifierList COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
                        ident_stack.push($1);
                        param_stack.push($1);
                        while(!ident_stack.empty()) {
                          string temp = ident_stack.top();
                          Sym sym(0,$6,temp,INTARRAY);
                          add_symbol_to_symbol_table(sym);
                          string_codes << ".[] " << temp << ", " << $6 << endl;
                          ident_stack.pop(); 
                        }
                      }
                    ;
                    
IdentifierList:     /*epsilon*/
                    | COMMA IDENT  IdentifierList{
                        ident_stack.push($2);
                        param_stack.push($2);
                      }
                    ;	

StatementList:      Statement SEMICOLON StatementList 
                    |  /*epsilon*/ 
                    ;

Statement:          Statement_Var {}
                    | Statement_If {}
                    | Statement_While {}
                    | Statement_Do {}
                    | Statement_Read {}
                    | Statement_Write {}
                    | CONTINUE{
                      if (!label_stack.empty()) {
                          string_codes << ":= " << label_stack.top() << endl;
                          file_codes << string_codes.rdbuf();
                          string_codes.clear();
                          string_codes.str(" ");
                        }
                        else {
                          yyerror("Cannot use continue outside a loop");
                        }
                      }
                    | RETURN Expression{
                          $$.val = $2.val;
                          strcpy($$.name,$2.name);
                          string_codes << "ret " << $2.name << endl;
                          file_codes << string_codes.rdbuf();
                          string_codes.clear();
                          string_codes.str(" ");
                      }
                    ;

Statement_Var:      Var ASSIGN Expression{
                      if ($1.type == 0) { 
                        //Check if Var is an int
                          string_codes << "= " << $1.name << ", " << $3.name << endl;
                        
                      }
                      else { //Check if Var is an int array
                          string_codes << "[]= " << $1.name << ", " << $1.index << ", " << $3.name << endl;
                      } 
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
                    ;

Statement_If:       IF Bool_Expr THEN {
                      string start = makeLabel();
                      string endif = makeLabel();
                      label_stack.push(endif); 
                      string_codes << "?:= " << start << ", " << ($2.name) << endl;
                      string_codes << ":= " << endif << endl;
                      string_codes << ": " << start << endl;
                    } 
                    Statement SEMICOLON StatementList ElseStatement ENDIF{
                      string_codes << ": " << label_stack.top() << endl;
                      label_stack.pop();
                      
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
                    ;

ElseStatement:      /*epsilon*/ 
                    | ELSE {
                      string label = makeLabel(); 
                      string_codes << ":= " << label << endl;
                      string_codes << ": " << label_stack.top() << endl;
                      label_stack.pop();
                      label_stack.push(label);
                    } 
                    Statement SEMICOLON StatementList           
                    ;

Statement_While:    WHILE Bool_Expr BEGINLOOP{
                      string conditional = makeLabel();
                      string endlabel = makeLabel();
                      string start = makeLabel();
                      file_codes << ": " << start << endl;

                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    
                      string_codes << "?:= " << conditional << ", " << ($2.name) << endl;
                      string_codes << ":= " << endlabel << endl;
                      string_codes << ": " << conditional << endl;

                      label_stack.push(start);
                      label_stack.push(endlabel);
                    }
                    Statement SEMICOLON StatementList ENDLOOP{
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");

                      string endlabel = label_stack.top();
                      label_stack.pop();
                      string start = label_stack.top();
                      label_stack.pop();

                      string_codes << ":= " << start << endl;
                      string_codes << ": " << endlabel << endl;
      
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
                    ;

Statement_Do:       DO BEGINLOOP {
                      string start = makeLabel();
                      label_stack.push(start);
                      file_codes << ": " << start << endl;
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
                    Statement SEMICOLON StatementList ENDLOOP WHILE Bool_Expr{
                      string start = label_stack.top();
                      string_codes << "?:= " << start << ", " << $9.name << endl;
                      label_stack.pop(); 
                      
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
                    ;

Statement_Read:     READ Var VarList{
                      var_stack.push($2.name);
                      while (!var_stack.empty()) {
                          if ($2.type == 0) {
                              string_codes << ".< " << var_stack.top() << endl;
                              var_stack.pop();
                          }
                          else {
                              string_codes << ".[]< " << var_stack.top() << ", "  <<  $2.index << endl;
                              var_stack.pop();
                          }
                      }
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    } 
                    ;

Statement_Write:    WRITE Var VarList{
                      var_stack.push($2.name);
                      while (!var_stack.empty()) {
                          if ($2.type == 0) {
                              string_codes << ".> " << var_stack.top() << endl;
                              var_stack.pop();
                          }
                          else {
                              string_codes << ".[]> " << var_stack.top() << ", "  <<  $2.index << endl;
                              var_stack.pop();
                          }
                      }
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
                    ;

Var:		            IDENT {
                      check_symbol($1);
                      if(symbol_table[$1].type == INTARRAY) {
                        yyerror("Use an array variable as an integer variable");
                      }
                      else {
                        strcpy($$.name,$1);
                        $$.type = 0;
                      }
                    }
                    | IDENT L_SQUARE_BRACKET Expression R_SQUARE_BRACKET{
                        check_symbol($1);
                        if(symbol_table[$1].type == INT) {
                          yyerror("Use an integer variable as an array variable");
                        }
                        else {
                          if ($3.type == 1) {
                            string temp = makeTemp();
                            $$.type = 1;
                            strcpy($$.index, temp.c_str());
                            strcpy($$.name, $1);

                            string_codes << ". " << temp << endl; 
                            string_codes << "=[] " << temp << ", " << $3.name << ", " << $3.index << endl;
                          }
                          else {
                            strcpy($$.name, $1);
                            $$.type = 1;
                            //$$.val = symbol_table[$1].val;
                            strcpy($$.index, $3.name);
                          }
                        }
                     }
		                ;

VarList:            /*epsilon*/
                    | COMMA Var VarList{
                      var_stack.push($2.name);
                    } 
                    ;

Expression:         Multi_Expr{
                      strcpy($$.name,$1.name);
                      $$.type = $1.type;
                    }
                    | Expression ADD Multi_Expr {
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "+ " << temp << ", " << $1.name << ", " << $3.name << endl;
                        strcpy($$.name, temp.c_str());
                      }
                    | Expression SUB Multi_Expr {
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "- " << temp << ", " << $1.name << ", " << $3.name << endl;
                        strcpy($$.name, temp.c_str());
                      }
                    ;

Multi_Expr:         Term{
                       strcpy($$.name,$1.name);
                       $$.type = $1.type;
                      }
                      | 
                    Multi_Expr MULT Term {
                       string temp = makeTemp();
                       string_codes << ". " << temp << endl;
                       string_codes << "* " << temp << ", " << $1.name << ", " << $3.name << endl;
                       strcpy($$.name, temp.c_str());
                     }
                    | Multi_Expr DIV Term {
                       string temp = makeTemp();
                       string_codes << ". " << temp << endl;
                       string_codes << "/ " << temp << ", " << $1.name << ", " << $3.name << endl;
                       strcpy($$.name, temp.c_str());
                      }
                    | Multi_Expr MOD Term  {
                       string temp = makeTemp();
                       string_codes << ". " << temp << endl;
                       string_codes << "% " << temp << ", " << $1.name << ", " << $3.name << endl;
                       strcpy($$.name, temp.c_str());
                      }

                    ;

Term:               Var {
                      $$.val = $1.val;
                      $$.type = $1.type;
                      if ($1.type != 1) {
                        strcpy($$.name,makeTemp().c_str());
                        strcpy($$.index,$$.name);
                        string_codes << ". " << $$.name << endl;
                        string_codes << "= " << $$.name <<  ", " << $1.name << endl;
                      }
                      else if ($1.type == 1) { 
                        //b = makeTemp();
                        strcpy($$.name,makeTemp().c_str());
                        string_codes << ". " <<  $$.name<< endl;
                        string_codes << "=[] " << $$.name << ", " << $1.name << ", " << $1.index << endl;
                      }
                    }
                    | SUB Var {
                        $$.val = $2.val*-1;
                        $$.type = $2.type;
                        if ($2.type != 1) {
                          // if int
                          string zero = makeTemp();
                          string num = makeTemp();
                          string_codes << ". " << zero << endl;
                          string_codes << "= " << zero << ", " << "0" << endl;
                          string_codes << ". " << num << endl;
                          string_codes << "= " << num << ", " << $2.name << endl;
                          strcpy($$.name,makeTemp().c_str());
                          string_codes << ". " << $$.name << endl;
                          string_codes << "- " << $$.name <<  ", " << zero << ", " << num << endl;
                        }        
                        else if ($2.type == 1) { 
                          // if array
                          string zero = makeTemp();
                          string num = makeTemp();
                          string_codes << ". " << zero << endl;
                          string_codes << "= " << zero << ", " << "0" << endl;
                          string_codes << ". " << num << endl;
                          string_codes << ". " << num << endl;
                          string_codes << "=[] " << num << ", " << $2.name <<  ", " << $2.index << endl;
                          strcpy($$.name,makeTemp().c_str());
                          string_codes << ". " <<  $$.name<< endl;
                          string_codes << "- " << $$.name << ", " << zero <<  ", " << num << endl;
                        }
                      }
                    | NUMBER{
                        $$.val = $1;
                        $$.type = 0;
                        strcpy($$.name, makeTemp().c_str());
                        strcpy($$.index,$$.name);
                        string_codes << ". " << $$.name << endl;
                        string_codes << "= " << $$.name <<  ", " << $$.val << endl;
                      }
                    | SUB NUMBER{
                          $$.val = $2 * (-1);
                          $$.type = 0;
                          string zero = makeTemp();
                          string num = makeTemp();
                          string_codes << ". " << zero << endl;
                          string_codes << "= " << zero << ", " << "0" << endl;
                          string_codes << ". " << num << endl;
                          string_codes << "= " << num << ", " << $2 << endl;
                          strcpy($$.name, makeTemp().c_str());
                          string_codes << ". " << $$.name << endl;
                          string_codes << "- " << $$.name <<  ", " << zero << ", "<< num << endl;
                      }
                    | L_PAREN Expression R_PAREN {
                        strcpy($$.name, $2.name);
                      }
                    | SUB  L_PAREN Expression R_PAREN {
                        string zero = makeTemp();
                        string_codes << ". " << zero << endl;
                        string_codes << "= " << zero << ", " << "0"<< endl;
                        strcpy($$.name, makeTemp().c_str());
                        string_codes << ". " << $$.name << endl;
                        string_codes << "- " << $$.name <<  ", " << zero << ", "<< $3.name << endl;
                      }
                    | IDENT L_PAREN Expression ExpressionList R_PAREN {
                        check_func($1);
                        exp_stack.push($3.name); 
                        while (!exp_stack.empty()){
                          string_codes << "param " << exp_stack.top() << endl;
                          exp_stack.pop();
                        }
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "call " << ($1) << ", " << temp << endl;
                        strcpy($$.name,temp.c_str());
                      }
                    | IDENT L_PAREN R_PAREN {
                        check_func($1);
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "call " << $1 << ", " << temp << endl;
                        strcpy($$.name,temp.c_str());
                      }
                    ;

ExpressionList:     /*epsilon*/
                    | COMMA  Expression ExpressionList{
                        exp_stack.push($2.name); 
                      }
                    ;

Bool_Expr:	        Relation_And_Expr {
                      strcpy($$.name, $1.name);
                    }
                    | Relation_And_Expr OR Bool_Expr{
                      string temp = makeTemp();
                      strcpy($$.name, temp.c_str());
                      string_codes << ". " << temp << endl;
                      string_codes << "|| " << temp << ", " << $1.name << ", " << $3.name << endl;
                    }
                    ;

Relation_And_Expr:  Relation_Expr{
                       strcpy($$.name, $1.name);
                    }
                    | Relation_Expr AND Relation_And_Expr {
                        string temp = makeTemp();
                        strcpy($$.name, temp.c_str());
                        string_codes << ". " << temp << endl;
                        string_codes << "&& " << temp << ", " << $1.name << ", " <<  $3.name << endl;
                      }
                    ;

Relation_Expr:      Rel_Expr_Ex_Not {
                    strcpy($$.name, $1.name);
                    } 
                    | NOT Rel_Expr_Ex_Not{
                      string temp = makeTemp();
                      strcpy($$.name, temp.c_str());
                      string_codes << "! " << temp << $2.name << endl;
                      }
                    ;

Rel_Expr_Ex_Not:   Expression Comp Expression{
                    string temp = makeTemp();
                    strcpy($$.name, temp.c_str());
                    string_codes << ". " << temp << endl;
                    string_codes << $2 << " " << temp << ", " << $1.name << ", " << $3.name << endl;
                   }
                   | TRUE {
                      string temp = makeTemp();
                      strcpy($$.name, temp.c_str());
                      string_codes << ". " << temp << endl;
                      string_codes << "= " << temp << ", " << "1" << endl;
                    }
                  | FALSE {
                      string temp = makeTemp();
                      strcpy($$.name, temp.c_str());
                      string_codes << ". " << temp << endl;
                      string_codes << "= " << temp << ", " << "0" << endl;
                    }
                  | L_PAREN Bool_Expr R_PAREN {
                     strcpy($$.name, $2.name);
                    }
                  ;
                  
Comp:             EQ { $$ = const_cast<char*>("=="); } 
                  | NEQ { $$ = const_cast<char*>("!="); }
                  | LT { $$ = const_cast<char*>("<"); }
                  | GT { $$ = const_cast<char*>(">"); }
                  | LTE { $$ = const_cast<char*>("<="); }
                  | GTE { $$ = const_cast<char*>(">="); }
                  ;

%%

int main(int argc, char **argv) {
    if (argc > 1) {
         yyin = fopen(argv[1], "r"); 
         if (yyin == NULL){ 
             printf("syntax: %s filename\n", argv[0]); 
        }//end if 
    }//end if
    else
    {
      yyin = stdin;
    } 
    yyparse(); 
    if (error_exists == 0){
        ofstream file;
        file.open("mil_code.mil");
        file << file_codes.str();
        file.close();
    }
    return 0;
}


void yyerror(const char *msg) {
     printf("Error Line %d, position %d: %s\n", currLine, currPos, msg);
     error_exists = 1;
}

void yyerror(string message) {
    cout << "Error Line " << currLine << ", position " << currPos << ": " << message <<endl;
    error_exists = 1;
}


void add_function_to_func_table(Func f) {
  if (func_table.find(f.name) == func_table.end()) {
    func_table[f.name] = f;
  }
  else {
    string error = "Function already declared: " + f.name;
    yyerror(error);
  }
}
  
void add_symbol_to_symbol_table(Sym s) {
  if (symbol_table.find(s.name) == symbol_table.end()) {
    symbol_table[s.name] = s;
  }
  else {
    string error = "Symbol already declared: " + s.name;
    yyerror(error);
  }
}

void check_symbol(string name) {
  if(symbol_table.find(name) == symbol_table.end()) {
    string error = "Symbol not declared: " + name;
    yyerror(error);
  }
}

void check_func(string name) {
  if(func_table.find(name) == func_table.end()) {
    string error = "Function not declared: " + name;
    yyerror(error);
  }
}

string makeTemp() {
  stringstream ss;
  ss << temp_tot++;
  string temp = "__temp__" + ss.str();
  return temp;
}

string makeLabel() {
  stringstream ss;
  ss << label_tot++;
  string temp = "__label__" + ss.str();
  return temp;
}


/*  
To be addressed:
1. Using a variable without having first declared it.     # done
2. Calling a function which has not been defined.         # done
3. Not defining a main function.                          # done 
4. Defining a variable more than once (it should also be an error to declare a variable with the same name as the MINI-L program itself).     # done
5. Trying to name a variable with the same name as a reserved keyword.  # done
6. Forgetting to specify an array index when using an array variable (i.e., trying to use an array variable as a regular integer variable). # done
7. Specifying an array index when using a regular integer variable (i.e., trying to use a regular integer variable as an array variable). # done
8. Declaring an array of size <= 0.   # done
9. Using continue statement outside a loop.   # done
*/
