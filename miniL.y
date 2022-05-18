%{
    /* C declarations */ 
    #include <stdio.h> 
    #include <stdlib.h> 
    void yyerror(const char *msg); 
    extern int currLine; 
    extern int currPos; /* variables defined in .lex file */ 
    FILE * yyin; 
%}

%union{ 
    char * identVal; 
    int numVal; 
} 


%error-verbose 
%start Program /* begin processing top-level component */ 
%token FUNCTION SEMICOLON BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY COMMA COLON INTEGER ARRAY L_SQUARE_BRACKET R_SQUARE_BRACKET OF L_PAREN R_PAREN ADD SUB MULT DIV MOD ASSIGN IF THEN ELSE WHILE BEGINLOOP ENDLOOP AND OR TRUE FALSE EQ NEQ LT GT LTE GTE DO READ WRITE CONTINUE RETURN NOT ENUM ENDIF FOR

%token <numVal> NUMBER
%token <identVal> IDENT



%% 
Program:            FunctionList 
                    {printf("Program -> FunctionList \n");}
                    | error {yyerrok; yyclearin;}
                    ;

FunctionList:       Function FunctionList 
                    {printf("FunctionList ->  Function FunctionList \n");}
                    | /*epsilon*/ 
                      {printf("FunctionList -> empty \n");}
                    ;

Function:           FUNCTION Identifier SEMICOLON BEGIN_PARAMS DeclarationList END_PARAMS BEGIN_LOCALS DeclarationList END_LOCALS BEGIN_BODY StatementList END_BODY 
                    {printf("Function ->  FUNCTION Identifier ; BEGIN_PARAMS DeclarationList END_PARAMS BEGIN_LOCALS DeclarationList END_LOCALS BEGIN_BODY StatementList END_BODY \n");}
                    ;

DeclarationList:    Declaration SEMICOLON DeclarationList 
                    {printf("DeclarationList -> Declaration SEMICOLON DeclarationList \n");}
                    | /*epsilon*/ 
                      {printf("DeclarationList -> empty \n");}
                    | Declaration error {yyerrok;}
                    ;    

Declaration:        IdentifierList COLON INTEGER
                    {printf("Declaration -> IdentifierList : INTEGER \n");}
                    | IdentifierList COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
                      {printf("Declaration -> IdentifierList : ARRAY [ NUMBER ] of INTEGER \n");}
                    | IdentifierList COLON ENUM L_PAREN IdentifierList R_PAREN 
                      {printf("Declaration -> IdentifierList : ENUM ( IdentifierList ) \n");}
                    ;

IdentifierList:     Identifier 
                    {printf("IdentifierList -> Identifier \n");}
                    | Identifier COMMA IdentifierList  
                      {printf("IdentifierList -> Identifier , IdentifierList \n");}
                    ;	

Identifier:         IDENT
                    {printf("Identifier -> IDENTIFIER %s\n", $1);}
                    ;

StatementList:      Statement SEMICOLON StatementList 
                    {printf("StatementList -> Statement; StatementList \n");} 
                    | Statement SEMICOLON 
                      {printf("StatementList -> Statement; \n");}        
                    ;

Statement:          Statement_Var
                    {printf("STATMENT -> Statement_Var \n");}
                    | Statement_If
                      {printf("STATMENT -> Statement_If \n");}
                    | Statement_For
                      {printf("STATMENT -> Statement_For \n");}
                    | Statement_While
                      {printf("STATMENT -> Statement_While \n");}
                    | Statement_Do
                      {printf("STATMENT -> Statement_Do \n");}
                    | Statement_Read
                      {printf("STATMENT -> Statement_Read \n");}
                    | Statement_Write
                      {printf("STATMENT -> Statement_Write \n");}
                    | CONTINUE
                      {printf("STATMENT -> CONTINUE \n");}
                    | RETURN Expression
                      {printf("STATMENT -> RETURN Expression\n");}
                    ;

Statement_Var:      Var ASSIGN Expression
                    {printf("Statement_Var -> Var ASSIGN Expression \n");}
                    ;

Statement_If:       IF Bool_Expr THEN StatementList ENDIF
                    {printf("Statement_If -> Bool_Expr THEN StatementList ENDIF \n");}
                    | IF Bool_Expr THEN StatementList ELSE StatementList ENDIF
                    {printf("Statement_If -> Bool_Expr THEN StatementList ELSE StatementList ENDIF \n");}
                    ;

Statement_For:      FOR Var ASSIGN NUMBER SEMICOLON Bool_Expr SEMICOLON Var ASSIGN Expression BEGINLOOP StatementList ENDLOOP
                    {printf("Statement_For -> FOR VAR ASSIGN NUMBER SEMICOLON Bool_Expr SEMICOLON Var ASSIGN Expression BEGINLOOP StatementList ENDLOOP \n");}    
                    ;

Statement_While:	  WHILE Bool_Expr BEGINLOOP StatementList ENDLOOP
                    {printf("Statement_While -> WHILE Bool_Expr BEGINLOOP StatementList ENDLOOP \n");}
                    ;

Statement_Do:       DO BEGINLOOP StatementList ENDLOOP WHILE Bool_Expr
                    {printf("Statement_Do -> DO BEGINLOOP StatementList ENDLOOP WHILE Bool_Expr \n");}
                    ;

Statement_Read:     READ Var VarList
                    {printf("Statement_Read -> Read Var VarList \n");}
                    ;

Statement_Write:    WRITE Var VarList
                    {printf("Statement_Write -> Var VarList \n");}
                    ;


Var:		            Identifier
   		              {printf("Var -> Identifier \n");}
                    | Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET
		                {printf("Var -> Identifier L_SQSUARE_BRACKET Expression R_SQUARE_BRACKET \n");}
		                ;

VarList:            /*epsilon*/
                    {printf("VarList -> empty \n");}
                    | COMMA Var VarList
                    {printf("VarList -> COMMA Var VarList \n");}
                    ;

Expression:         Multi_Expr AddExpr
	  	              {printf("Expression -> Multi_Expr AddExpr \n");}
                    ;

AddExpr:            /*epsilon*/
                    {printf("AddExpr -> empty \n");}
                    | ADD Expression
                      {printf("AddExpr -> ADD Expression \n");}
                    | SUB Expression
                      {printf("AddExpr -> SUB Expression \n");}
                    ;

Multi_Expr:         Term
                    {printf("Multi_Expr -> Term \n");}
                    | Term MULT Multi_Expr
                      {printf("Multi_Expr -> Term MULT Multi_Expr \n");}
                    | Term DIV Multi_Expr
                      {printf("Multi_Expr -> Term DIV Multi_Expr \n");}
                    | Term MOD Multi_Expr 
                      {printf("Multi_Expr -> Term MOD Multi_Expr \n");}
                    ;

Term:               Var
                    {printf("Term -> VAR \n");}
                    | SUB Var
                      {printf("Term -> SUB VAR \n");}
                    | NUMBER
                      {printf("Term -> NUMBER \n");}
                    | SUB NUMBER
                      {printf("Term -> SUB NUMBER \n");}
                    | L_PAREN Expression R_PAREN
                      {printf("Term -> L_PAREN Expression R_PAREN \n");}
                    | SUB  L_PAREN Expression R_PAREN
                      {printf("Term -> SUB L_PAREN Expression R_PAREN \n");}
                    | Identifier L_PAREN ExpressionList R_PAREN
                      {printf("Term -> Identifier L_PAREN ExpressionList R_PAREN \n");}
                    ;

ExpressionList:     /*epsilon*/
                    {printf("ExpressionList -> empty \n");}
                    | Expression
                      {printf("ExpressionList -> Expression \n");}
                    | Expression COMMA ExpressionList
                      {printf("ExpressionList -> Expression COMMA ExpressionList \n");}
                    ;

Bool_Expr:	        Relation_And_Expr
                    {printf("Bool_Expr ->  Relation_And_Expr \n");}
                    | Relation_And_Expr OR Bool_Expr
                    {printf("Bool_Expr ->  Relation_And_Expr OR Bool_Expr \n");}
                    ;

Relation_And_Expr:  Relation_Expr
                    {printf("Relation_And_Expr ->  Relation_Expr\n");}
                    | Relation_Expr AND Relation_And_Expr
                    {printf("Relation_And_Expr ->  Relation_Expr AND Relation_And_Expr \n");}
                    ;

Relation_Expr:      NOT Expression Comp Expression
                    {printf("Relation_Expr -> NOT Expression Comp Expression \n");}
                    | Expression Comp Expression
                    {printf("Relation_Expr -> Expression Comp Expression \n");}
                    | NOT TRUE
                    {printf("Relation_Expr -> NOT TRUE \n");}
                    | TRUE
                    {printf("Relation_Expr -> TRUE \n");}
                    | NOT FALSE
                    {printf("Relation_Expr -> NOT FALSE \n");}
                    | FALSE
                    {printf("Relation_Expr -> FALSE \n");}
                    | NOT L_PAREN Bool_Expr R_PAREN
                    {printf("Relation_Expr -> NOT L_PAREN Bool_Expr R_PAREN \n");}
                    | L_PAREN Bool_Expr R_PAREN
                    {printf("Relation_Expr -> L_PAREN Bool_Expr R_PAREN \n");}
                    ;

Comp:               EQ
                    {printf("Comp -> EQ \n");}
                    | NEQ
                    {printf("Comp -> NEQ \n");}
                    | LT
                    {printf("Comp -> LT \n");}
                    | GT
                    {printf("Comp -> GT \n");}
                    | LTE
                    {printf("Comp -> LTE \n");}
                    | GTE
                    {printf("Comp -> GTE \n");}
                    ;

%%

int main(int argc, char **argv) {
    if (argc > 1) 
    {
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
    // Calls yylex() for tokens.
    return 0;
}


void yyerror(const char *msg) {
     printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}

