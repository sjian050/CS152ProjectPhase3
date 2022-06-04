/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "miniL.y" /* yacc.c:339  */

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

#line 129 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGIN_PARAMS = 259,
    END_PARAMS = 260,
    BEGIN_LOCALS = 261,
    END_LOCALS = 262,
    BEGIN_BODY = 263,
    END_BODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ELSE = 270,
    ENDIF = 271,
    WHILE = 272,
    DO = 273,
    BEGINLOOP = 274,
    ENDLOOP = 275,
    CONTINUE = 276,
    READ = 277,
    WRITE = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    TRUE = 282,
    FALSE = 283,
    RETURN = 284,
    SUB = 285,
    ADD = 286,
    MULT = 287,
    DIV = 288,
    MOD = 289,
    EQ = 290,
    NEQ = 291,
    LT = 292,
    GT = 293,
    LTE = 294,
    GTE = 295,
    COMMA = 296,
    COLON = 297,
    SEMICOLON = 298,
    L_SQUARE_BRACKET = 299,
    R_SQUARE_BRACKET = 300,
    L_PAREN = 301,
    R_PAREN = 302,
    ASSIGN = 303,
    NUMBER = 304,
    IDENT = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "miniL.y" /* yacc.c:355  */
 
    char * identVal; 
    int numVal; 
    struct attributes {
      char name[255];
      char index[255];
      int type; //0 = int, 1 = int array, 2 = function
      int val;
    } attrVal;

#line 231 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   109,   110,   114,   119,   113,   140,   141,
     144,   155,   168,   169,   175,   176,   179,   180,   181,   182,
     183,   184,   185,   196,   206,   221,   221,   239,   240,   240,
     250,   250,   286,   286,   305,   323,   341,   351,   376,   377,
     382,   386,   392,   400,   405,   411,   417,   426,   442,   471,
     479,   492,   495,   503,   515,   524,   525,   530,   533,   541,
     544,   552,   555,   562,   568,   574,   580,   585,   586,   587,
     588,   589,   590
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "COMMA", "COLON", "SEMICOLON", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "L_PAREN", "R_PAREN", "ASSIGN", "NUMBER", "IDENT",
  "$accept", "Program", "FunctionList", "Function", "$@1", "$@2",
  "DeclarationList", "Declaration", "IdentifierList", "StatementList",
  "Statement", "Statement_Var", "Statement_If", "$@3", "ElseStatement",
  "$@4", "Statement_While", "$@5", "Statement_Do", "$@6", "Statement_Read",
  "Statement_Write", "Var", "VarList", "Expression", "Multi_Expr", "Term",
  "ExpressionList", "Bool_Expr", "Relation_And_Expr", "Relation_Expr",
  "Rel_Expr_Ex_Not", "Comp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    -4,    42,   -95,     7,   -95,   -95,   -95,    16,    63,
      20,    33,   -95,    57,    26,    43,    96,    20,    33,     3,
     101,   -95,   -95,   -95,    64,    20,    60,   103,    67,   105,
     107,     8,   116,    45,    45,   108,   -95,    80,    80,    -2,
      73,   122,    97,   -95,   -95,   -95,   -95,   -95,   -95,    91,
     -95,    56,   -95,   -95,   -38,    45,   -95,    -5,   -95,    98,
      48,   -95,   127,   117,   119,   -95,   125,   -95,   104,   104,
      -2,    31,    -2,   -95,     8,    -2,   -95,    -2,   -95,   -95,
      85,    99,     6,    -2,    -2,   -95,   -95,   -95,   -95,   -95,
     -95,    -2,    -2,    -2,    -2,   -95,    45,    45,   -95,     8,
      80,   -95,   -95,   -15,   -11,   -95,    31,    19,   -95,   -95,
     -95,    47,    48,    48,    31,   -95,   -95,   -95,     8,   -95,
     -95,     8,   106,   104,   -95,   -95,    -2,   100,   109,   110,
       8,   -95,    47,   -95,     8,     8,   128,   -95,   135,   131,
     137,   -95,   139,   -95,    45,     8,   -95,   -95,   113,     8,
     -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     4,     5,     1,     3,     0,     0,
       9,    12,     6,     0,     0,     0,     0,     9,    12,     0,
       0,     8,    13,    10,     0,     9,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    22,     0,     0,     0,
      36,     0,     0,    16,    17,    18,    19,    20,    21,     0,
      11,     0,    64,    65,     0,     0,    49,    36,    47,     0,
      40,    43,     0,    57,    59,    61,     0,    32,    38,    38,
       0,    23,     0,     7,    15,     0,    62,     0,    50,    48,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
      72,     0,     0,     0,     0,    25,     0,     0,    30,     0,
       0,    34,    35,     0,     0,    14,    24,     0,    51,    66,
      54,    55,    42,    41,    63,    44,    45,    46,     0,    58,
      60,     0,     0,    38,    37,    52,     0,     0,     0,     0,
      15,    39,    55,    53,    15,    15,     0,    56,    27,     0,
       0,    28,     0,    31,     0,     0,    26,    33,     0,    15,
      29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   153,   -95,   -95,   -95,    -8,   -95,   140,   -70,
     -94,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -31,   -66,   -37,     9,     4,    27,   -33,    65,
     -95,   112,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    16,    12,    13,    15,    41,
      42,    43,    44,   118,   142,   145,    45,   121,    46,    99,
      47,    48,    58,   101,    59,    60,    61,   127,    62,    63,
      64,    65,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    66,    71,   102,   105,   122,    68,    69,    77,    21,
       1,    78,    40,    23,    24,    83,    84,    27,    80,    83,
      84,    33,    81,    79,   128,    34,    35,   129,    54,    36,
      37,    38,   108,   103,   124,   104,    54,    39,   106,    72,
     107,    82,     6,    49,    70,   111,     5,    56,    57,    83,
      84,   148,    70,   110,   114,    56,    57,   131,    40,     9,
     136,    83,    84,   119,   138,   139,   125,    10,    49,   123,
      11,    51,    52,    53,    14,    54,    18,    83,    84,   150,
      92,    93,    94,    52,    53,    19,    54,    49,   126,   132,
      49,    55,   112,   113,    56,    57,   115,   116,   117,    49,
      17,    20,    55,    49,    49,    56,    57,    25,    26,    28,
      29,   147,    30,    31,    49,    83,    84,    72,    49,    32,
      85,    86,    87,    88,    89,    90,    50,    67,    83,    84,
      40,    73,   108,    85,    86,    87,    88,    89,    90,    75,
      74,    95,    96,    97,    98,   100,   109,   133,   140,   130,
     141,   143,   134,   135,   144,   146,   149,     7,    22,   137,
       0,     0,   120,    76
};

static const yytype_int16 yycheck[] =
{
      31,    34,    39,    69,    74,    99,    37,    38,    46,    17,
       3,    49,    50,    10,    11,    30,    31,    25,    55,    30,
      31,    13,    55,    54,   118,    17,    18,   121,    30,    21,
      22,    23,    47,    70,    45,    72,    30,    29,    75,    44,
      77,    46,     0,    74,    46,    82,    50,    49,    50,    30,
      31,   145,    46,    47,    91,    49,    50,   123,    50,    43,
     130,    30,    31,    96,   134,   135,    47,     4,    99,   100,
      50,    26,    27,    28,    41,    30,    50,    30,    31,   149,
      32,    33,    34,    27,    28,    42,    30,   118,    41,   126,
     121,    46,    83,    84,    49,    50,    92,    93,    94,   130,
      43,     5,    46,   134,   135,    49,    50,     6,    44,    49,
       7,   144,    45,     8,   145,    30,    31,    44,   149,    12,
      35,    36,    37,    38,    39,    40,    10,    19,    30,    31,
      50,     9,    47,    35,    36,    37,    38,    39,    40,    48,
      43,    14,    25,    24,    19,    41,    47,    47,    20,    43,
      15,    20,    43,    43,    17,    16,    43,     4,    18,   132,
      -1,    -1,    97,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    53,    54,    50,     0,    53,    55,    43,
       4,    50,    57,    58,    41,    59,    56,    43,    50,    42,
       5,    57,    59,    10,    11,     6,    44,    57,    49,     7,
      45,     8,    12,    13,    17,    18,    21,    22,    23,    29,
      50,    60,    61,    62,    63,    67,    69,    71,    72,    73,
      10,    26,    27,    28,    30,    46,    49,    50,    73,    75,
      76,    77,    79,    80,    81,    82,    79,    19,    73,    73,
      46,    75,    44,     9,    43,    48,    82,    46,    49,    73,
      75,    79,    46,    30,    31,    35,    36,    37,    38,    39,
      40,    83,    32,    33,    34,    14,    25,    24,    19,    70,
      41,    74,    74,    75,    75,    60,    75,    75,    47,    47,
      47,    75,    76,    76,    75,    77,    77,    77,    64,    79,
      80,    68,    61,    73,    45,    47,    41,    78,    61,    61,
      43,    74,    75,    47,    43,    43,    60,    78,    60,    60,
      20,    15,    65,    20,    17,    66,    16,    79,    61,    43,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    55,    56,    54,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    64,    63,    65,    66,    65,
      68,    67,    70,    69,    71,    72,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     0,    14,     3,     0,
       4,     9,     0,     3,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     0,     9,     0,     0,     5,
       0,     8,     0,     9,     3,     3,     1,     4,     0,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       2,     3,     4,     5,     3,     0,     3,     1,     3,     1,
       3,     1,     2,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 107 "miniL.y" /* yacc.c:1646  */
    {if(!main_exists){yyerror("Main function not declared");}}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 114 "miniL.y" /* yacc.c:1646  */
    {
                      string_codes << "func " << string((yyvsp[0].identVal)) << endl;
                      Func f((yyvsp[0].identVal));
                      add_function_to_func_table(f);
                    }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "miniL.y" /* yacc.c:1646  */
    {
                        while (!param_stack.empty()){
                          string_codes << "= " << param_stack.top() << ", " << "$" << param_cnt++ << endl;
                          param_stack.pop();
                        }
                    }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 128 "miniL.y" /* yacc.c:1646  */
    {
                      file_codes << "endfunc\n\n";
                      symbol_table.clear();
                      if (strcmp((yyvsp[-12].identVal), "main")==0) {
                        main_exists = 1;      
                      }
                      while (!param_stack.empty()) {
                        param_stack.pop();
                      }
                    }
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "miniL.y" /* yacc.c:1646  */
    {
                        ident_stack.push((yyvsp[-3].identVal));
                        param_stack.push((yyvsp[-3].identVal));
                        while(!ident_stack.empty()) {
                          string temp = ident_stack.top();
                          Sym sym(0,0,temp,INT); 
                          add_symbol_to_symbol_table(sym);
                          string_codes << ". " << temp << endl;
                        ident_stack.pop(); 
                        }
                    }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "miniL.y" /* yacc.c:1646  */
    {
                        ident_stack.push((yyvsp[-8].identVal));
                        param_stack.push((yyvsp[-8].identVal));
                        while(!ident_stack.empty()) {
                          string temp = ident_stack.top();
                          Sym sym(0,(yyvsp[-3].numVal),temp,INTARRAY);
                          add_symbol_to_symbol_table(sym);
                          string_codes << ".[] " << temp << ", " << (yyvsp[-3].numVal) << endl;
                          ident_stack.pop(); 
                        }
                      }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 169 "miniL.y" /* yacc.c:1646  */
    {
                        ident_stack.push((yyvsp[-1].identVal));
                        param_stack.push((yyvsp[-1].identVal));
                      }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 179 "miniL.y" /* yacc.c:1646  */
    {}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 180 "miniL.y" /* yacc.c:1646  */
    {}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "miniL.y" /* yacc.c:1646  */
    {}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 182 "miniL.y" /* yacc.c:1646  */
    {}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 183 "miniL.y" /* yacc.c:1646  */
    {}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 184 "miniL.y" /* yacc.c:1646  */
    {}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "miniL.y" /* yacc.c:1646  */
    {
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
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 196 "miniL.y" /* yacc.c:1646  */
    {
                          (yyval.attrVal).val = (yyvsp[0].attrVal).val;
                          strcpy((yyval.attrVal).name,(yyvsp[0].attrVal).name);
                          string_codes << "ret " << (yyvsp[0].attrVal).name << endl;
                          file_codes << string_codes.rdbuf();
                          string_codes.clear();
                          string_codes.str(" ");
                      }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 206 "miniL.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-2].attrVal).type == 0) { 
                        //Check if Var is an int
                          string_codes << "= " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                        
                      }
                      else { //Check if Var is an int array
                          string_codes << "[]= " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[-2].attrVal).index << ", " << (yyvsp[0].attrVal).name << endl;
                      } 
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 221 "miniL.y" /* yacc.c:1646  */
    {
                      string start = makeLabel();
                      string endif = makeLabel();
                      label_stack.push(endif); 
                      string_codes << "?:= " << start << ", " << ((yyvsp[-1].attrVal).name) << endl;
                      string_codes << ":= " << endif << endl;
                      string_codes << ": " << start << endl;
                    }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 229 "miniL.y" /* yacc.c:1646  */
    {
                      string_codes << ": " << label_stack.top() << endl;
                      label_stack.pop();
                      
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 240 "miniL.y" /* yacc.c:1646  */
    {
                      string label = makeLabel(); 
                      string_codes << ":= " << label << endl;
                      string_codes << ": " << label_stack.top() << endl;
                      label_stack.pop();
                      label_stack.push(label);
                    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 250 "miniL.y" /* yacc.c:1646  */
    {
                      string conditional = makeLabel();
                      string endlabel = makeLabel();
                      string start = makeLabel();
                      file_codes << ": " << start << endl;

                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    
                      string_codes << "?:= " << conditional << ", " << ((yyvsp[-1].attrVal).name) << endl;
                      string_codes << ":= " << endlabel << endl;
                      string_codes << ": " << conditional << endl;

                      label_stack.push(start);
                      label_stack.push(endlabel);
                    }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 267 "miniL.y" /* yacc.c:1646  */
    {
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
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 286 "miniL.y" /* yacc.c:1646  */
    {
                      string start = makeLabel();
                      label_stack.push(start);
                      file_codes << ": " << start << endl;
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 294 "miniL.y" /* yacc.c:1646  */
    {
                      string start = label_stack.top();
                      string_codes << "?:= " << start << ", " << (yyvsp[0].attrVal).name << endl;
                      label_stack.pop(); 
                      
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 305 "miniL.y" /* yacc.c:1646  */
    {
                      var_stack.push((yyvsp[-1].attrVal).name);
                      while (!var_stack.empty()) {
                          if ((yyvsp[-1].attrVal).type == 0) {
                              string_codes << ".< " << var_stack.top() << endl;
                              var_stack.pop();
                          }
                          else {
                              string_codes << ".[]< " << var_stack.top() << ", "  <<  (yyvsp[-1].attrVal).index << endl;
                              var_stack.pop();
                          }
                      }
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "miniL.y" /* yacc.c:1646  */
    {
                      var_stack.push((yyvsp[-1].attrVal).name);
                      while (!var_stack.empty()) {
                          if ((yyvsp[-1].attrVal).type == 0) {
                              string_codes << ".> " << var_stack.top() << endl;
                              var_stack.pop();
                          }
                          else {
                              string_codes << ".[]> " << var_stack.top() << ", "  <<  (yyvsp[-1].attrVal).index << endl;
                              var_stack.pop();
                          }
                      }
                      file_codes << string_codes.rdbuf();
                      string_codes.clear();
                      string_codes.str(" ");
                    }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 341 "miniL.y" /* yacc.c:1646  */
    {
                      check_symbol((yyvsp[0].identVal));
                      if(symbol_table[(yyvsp[0].identVal)].type == INTARRAY) {
                        yyerror("Use an array variable as an integer variable");
                      }
                      else {
                        strcpy((yyval.attrVal).name,(yyvsp[0].identVal));
                        (yyval.attrVal).type = 0;
                      }
                    }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 351 "miniL.y" /* yacc.c:1646  */
    {
                        check_symbol((yyvsp[-3].identVal));
                        if(symbol_table[(yyvsp[-3].identVal)].type == INT) {
                          yyerror("Use an integer variable as an array variable");
                        }
                        else {
                          if ((yyvsp[-1].attrVal).type == 1) {
                            string temp = makeTemp();
                            (yyval.attrVal).type = 1;
                            strcpy((yyval.attrVal).index, temp.c_str());
                            strcpy((yyval.attrVal).name, (yyvsp[-3].identVal));

                            string_codes << ". " << temp << endl; 
                            string_codes << "=[] " << temp << ", " << (yyvsp[-1].attrVal).name << ", " << (yyvsp[-1].attrVal).index << endl;
                          }
                          else {
                            strcpy((yyval.attrVal).name, (yyvsp[-3].identVal));
                            (yyval.attrVal).type = 1;
                            //$$.val = symbol_table[$1].val;
                            strcpy((yyval.attrVal).index, (yyvsp[-1].attrVal).name);
                          }
                        }
                     }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 377 "miniL.y" /* yacc.c:1646  */
    {
                      var_stack.push((yyvsp[-1].attrVal).name);
                    }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 382 "miniL.y" /* yacc.c:1646  */
    {
                      strcpy((yyval.attrVal).name,(yyvsp[0].attrVal).name);
                      (yyval.attrVal).type = (yyvsp[0].attrVal).type;
                    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "miniL.y" /* yacc.c:1646  */
    {
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "+ " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                        strcpy((yyval.attrVal).name, temp.c_str());
                      }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "miniL.y" /* yacc.c:1646  */
    {
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "- " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                        strcpy((yyval.attrVal).name, temp.c_str());
                      }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 400 "miniL.y" /* yacc.c:1646  */
    {
                       strcpy((yyval.attrVal).name,(yyvsp[0].attrVal).name);
                       (yyval.attrVal).type = (yyvsp[0].attrVal).type;
                      }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 405 "miniL.y" /* yacc.c:1646  */
    {
                       string temp = makeTemp();
                       string_codes << ". " << temp << endl;
                       string_codes << "* " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                       strcpy((yyval.attrVal).name, temp.c_str());
                     }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 411 "miniL.y" /* yacc.c:1646  */
    {
                       string temp = makeTemp();
                       string_codes << ". " << temp << endl;
                       string_codes << "/ " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                       strcpy((yyval.attrVal).name, temp.c_str());
                      }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "miniL.y" /* yacc.c:1646  */
    {
                       string temp = makeTemp();
                       string_codes << ". " << temp << endl;
                       string_codes << "% " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                       strcpy((yyval.attrVal).name, temp.c_str());
                      }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 426 "miniL.y" /* yacc.c:1646  */
    {
                      (yyval.attrVal).val = (yyvsp[0].attrVal).val;
                      (yyval.attrVal).type = (yyvsp[0].attrVal).type;
                      if ((yyvsp[0].attrVal).type != 1) {
                        strcpy((yyval.attrVal).name,makeTemp().c_str());
                        strcpy((yyval.attrVal).index,(yyval.attrVal).name);
                        string_codes << ". " << (yyval.attrVal).name << endl;
                        string_codes << "= " << (yyval.attrVal).name <<  ", " << (yyvsp[0].attrVal).name << endl;
                      }
                      else if ((yyvsp[0].attrVal).type == 1) { 
                        //b = makeTemp();
                        strcpy((yyval.attrVal).name,makeTemp().c_str());
                        string_codes << ". " <<  (yyval.attrVal).name<< endl;
                        string_codes << "=[] " << (yyval.attrVal).name << ", " << (yyvsp[0].attrVal).name << ", " << (yyvsp[0].attrVal).index << endl;
                      }
                    }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 442 "miniL.y" /* yacc.c:1646  */
    {
                        (yyval.attrVal).val = (yyvsp[0].attrVal).val*-1;
                        (yyval.attrVal).type = (yyvsp[0].attrVal).type;
                        if ((yyvsp[0].attrVal).type != 1) {
                          // if int
                          string zero = makeTemp();
                          string num = makeTemp();
                          string_codes << ". " << zero << endl;
                          string_codes << "= " << zero << ", " << "0" << endl;
                          string_codes << ". " << num << endl;
                          string_codes << "= " << num << ", " << (yyvsp[0].attrVal).name << endl;
                          strcpy((yyval.attrVal).name,makeTemp().c_str());
                          string_codes << ". " << (yyval.attrVal).name << endl;
                          string_codes << "- " << (yyval.attrVal).name <<  ", " << zero << ", " << num << endl;
                        }        
                        else if ((yyvsp[0].attrVal).type == 1) { 
                          // if array
                          string zero = makeTemp();
                          string num = makeTemp();
                          string_codes << ". " << zero << endl;
                          string_codes << "= " << zero << ", " << "0" << endl;
                          string_codes << ". " << num << endl;
                          string_codes << ". " << num << endl;
                          string_codes << "=[] " << num << ", " << (yyvsp[0].attrVal).name <<  ", " << (yyvsp[0].attrVal).index << endl;
                          strcpy((yyval.attrVal).name,makeTemp().c_str());
                          string_codes << ". " <<  (yyval.attrVal).name<< endl;
                          string_codes << "- " << (yyval.attrVal).name << ", " << zero <<  ", " << num << endl;
                        }
                      }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 471 "miniL.y" /* yacc.c:1646  */
    {
                        (yyval.attrVal).val = (yyvsp[0].numVal);
                        (yyval.attrVal).type = 0;
                        strcpy((yyval.attrVal).name, makeTemp().c_str());
                        strcpy((yyval.attrVal).index,(yyval.attrVal).name);
                        string_codes << ". " << (yyval.attrVal).name << endl;
                        string_codes << "= " << (yyval.attrVal).name <<  ", " << (yyval.attrVal).val << endl;
                      }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 479 "miniL.y" /* yacc.c:1646  */
    {
                          (yyval.attrVal).val = (yyvsp[0].numVal) * (-1);
                          (yyval.attrVal).type = 0;
                          string zero = makeTemp();
                          string num = makeTemp();
                          string_codes << ". " << zero << endl;
                          string_codes << "= " << zero << ", " << "0" << endl;
                          string_codes << ". " << num << endl;
                          string_codes << "= " << num << ", " << (yyvsp[0].numVal) << endl;
                          strcpy((yyval.attrVal).name, makeTemp().c_str());
                          string_codes << ". " << (yyval.attrVal).name << endl;
                          string_codes << "- " << (yyval.attrVal).name <<  ", " << zero << ", "<< num << endl;
                      }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 492 "miniL.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.attrVal).name, (yyvsp[-1].attrVal).name);
                      }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 495 "miniL.y" /* yacc.c:1646  */
    {
                        string zero = makeTemp();
                        string_codes << ". " << zero << endl;
                        string_codes << "= " << zero << ", " << "0"<< endl;
                        strcpy((yyval.attrVal).name, makeTemp().c_str());
                        string_codes << ". " << (yyval.attrVal).name << endl;
                        string_codes << "- " << (yyval.attrVal).name <<  ", " << zero << ", "<< (yyvsp[-1].attrVal).name << endl;
                      }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 503 "miniL.y" /* yacc.c:1646  */
    {
                        check_func((yyvsp[-4].identVal));
                        exp_stack.push((yyvsp[-2].attrVal).name); 
                        while (!exp_stack.empty()){
                          string_codes << "param " << exp_stack.top() << endl;
                          exp_stack.pop();
                        }
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "call " << ((yyvsp[-4].identVal)) << ", " << temp << endl;
                        strcpy((yyval.attrVal).name,temp.c_str());
                      }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 515 "miniL.y" /* yacc.c:1646  */
    {
                        check_func((yyvsp[-2].identVal));
                        string temp = makeTemp();
                        string_codes << ". " << temp << endl;
                        string_codes << "call " << (yyvsp[-2].identVal) << ", " << temp << endl;
                        strcpy((yyval.attrVal).name,temp.c_str());
                      }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "miniL.y" /* yacc.c:1646  */
    {
                        exp_stack.push((yyvsp[-1].attrVal).name); 
                      }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 530 "miniL.y" /* yacc.c:1646  */
    {
                      strcpy((yyval.attrVal).name, (yyvsp[0].attrVal).name);
                    }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 533 "miniL.y" /* yacc.c:1646  */
    {
                      string temp = makeTemp();
                      strcpy((yyval.attrVal).name, temp.c_str());
                      string_codes << ". " << temp << endl;
                      string_codes << "|| " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                    }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 541 "miniL.y" /* yacc.c:1646  */
    {
                       strcpy((yyval.attrVal).name, (yyvsp[0].attrVal).name);
                    }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 544 "miniL.y" /* yacc.c:1646  */
    {
                        string temp = makeTemp();
                        strcpy((yyval.attrVal).name, temp.c_str());
                        string_codes << ". " << temp << endl;
                        string_codes << "&& " << temp << ", " << (yyvsp[-2].attrVal).name << ", " <<  (yyvsp[0].attrVal).name << endl;
                      }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 552 "miniL.y" /* yacc.c:1646  */
    {
                    strcpy((yyval.attrVal).name, (yyvsp[0].attrVal).name);
                    }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 555 "miniL.y" /* yacc.c:1646  */
    {
                      string temp = makeTemp();
                      strcpy((yyval.attrVal).name, temp.c_str());
                      string_codes << "! " << temp << (yyvsp[0].attrVal).name << endl;
                      }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 562 "miniL.y" /* yacc.c:1646  */
    {
                    string temp = makeTemp();
                    strcpy((yyval.attrVal).name, temp.c_str());
                    string_codes << ". " << temp << endl;
                    string_codes << (yyvsp[-1].identVal) << " " << temp << ", " << (yyvsp[-2].attrVal).name << ", " << (yyvsp[0].attrVal).name << endl;
                   }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 568 "miniL.y" /* yacc.c:1646  */
    {
                      string temp = makeTemp();
                      strcpy((yyval.attrVal).name, temp.c_str());
                      string_codes << ". " << temp << endl;
                      string_codes << "= " << temp << ", " << "1" << endl;
                    }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 574 "miniL.y" /* yacc.c:1646  */
    {
                      string temp = makeTemp();
                      strcpy((yyval.attrVal).name, temp.c_str());
                      string_codes << ". " << temp << endl;
                      string_codes << "= " << temp << ", " << "0" << endl;
                    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 580 "miniL.y" /* yacc.c:1646  */
    {
                     strcpy((yyval.attrVal).name, (yyvsp[-1].attrVal).name);
                    }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 585 "miniL.y" /* yacc.c:1646  */
    { (yyval.identVal) = const_cast<char*>("=="); }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 586 "miniL.y" /* yacc.c:1646  */
    { (yyval.identVal) = const_cast<char*>("!="); }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 587 "miniL.y" /* yacc.c:1646  */
    { (yyval.identVal) = const_cast<char*>("<"); }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 588 "miniL.y" /* yacc.c:1646  */
    { (yyval.identVal) = const_cast<char*>(">"); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 589 "miniL.y" /* yacc.c:1646  */
    { (yyval.identVal) = const_cast<char*>("<="); }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 590 "miniL.y" /* yacc.c:1646  */
    { (yyval.identVal) = const_cast<char*>(">="); }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2155 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 593 "miniL.y" /* yacc.c:1906  */


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
