/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.ypp"

	#include <stdio.h>
	#include "ast.hpp"
	#include "primitive.hpp"
	#include "symtab.hpp"
	#define YYDEBUG 1
	#include <iostream>
	extern Program_ptr ast;
	int yylex(void);
	void yyerror(const char *);


/* Line 268 of yacc.c  */
#line 84 "parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TYPE = 258,
     IDENTIFIER = 259,
     BOOL = 260,
     INT = 261,
     RATIONAL = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     VAR = 266,
     FUNCTION = 267,
     INTARRAY = 268,
     AUTO = 269,
     RETURN = 270,
     YIELD = 271,
     TRUE_NT = 272,
     FALSE_NT = 273,
     PLUS = 274,
     MINUS = 275,
     TIMES = 276,
     DIV = 277,
     AS_OP = 278,
     EQ_OP = 279,
     GT_OP = 280,
     GE_OP = 281,
     LT_OP = 282,
     LE_OP = 283,
     NE_OP = 284,
     AND_OP = 285,
     OR_OP = 286,
     NOT_OP = 287,
     COLON = 288,
     OPENBRACKET = 289,
     CLOSEBRACKET = 290,
     OPENCURLY = 291,
     CLOSECURLY = 292,
     COMMA = 293,
     OPENPAREN = 294,
     CLOSEPAREN = 295,
     SEMICOLON = 296,
     UNARY = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 168 "parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    21,    23,    24,    28,
      30,    34,    38,    40,    45,    47,    48,    52,    55,    60,
      62,    67,    69,    70,    73,    75,    77,    79,    80,    83,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   106,
     114,   122,   133,   135,   136,   140,   142,   150,   154,   166,
     174,   178,   182,   186,   190,   194,   198,   202,   206,   210,
     214,   218,   222,   226,   228,   231,   234,   236,   240,   242,
     244,   246,   248,   250
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    45,    46,    -1,    46,    -1,
      12,     4,    39,    47,    40,    33,     3,    36,    51,    37,
      -1,    48,    -1,    -1,    49,    41,    48,    -1,    49,    -1,
      50,    33,     3,    -1,     4,    38,    50,    -1,     4,    -1,
      52,    56,    59,    72,    -1,    53,    -1,    -1,    54,    41,
      53,    -1,    54,    41,    -1,    11,    50,    33,    55,    -1,
       3,    -1,     4,    34,     6,    35,    -1,    57,    -1,    -1,
      58,    57,    -1,    58,    -1,    46,    -1,    60,    -1,    -1,
      61,    60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,     4,    23,    73,    41,    -1,     4,    34,    73,    35,
      23,    73,    41,    -1,     4,    23,     4,    39,    66,    40,
      41,    -1,     4,    34,    73,    35,    23,     4,    39,    66,
      40,    41,    -1,    67,    -1,    -1,    73,    38,    67,    -1,
      73,    -1,     8,    39,    73,    40,    36,    59,    37,    -1,
      16,    73,    41,    -1,     8,    39,    73,    40,    36,    59,
      37,     9,    36,    59,    37,    -1,    10,    39,    73,    40,
      36,    59,    37,    -1,    15,    73,    41,    -1,    73,    31,
      73,    -1,    73,    30,    73,    -1,    73,    24,    73,    -1,
      73,    25,    73,    -1,    73,    26,    73,    -1,    73,    27,
      73,    -1,    73,    28,    73,    -1,    73,    29,    73,    -1,
      73,    19,    73,    -1,    73,    20,    73,    -1,    73,    21,
      73,    -1,    73,    22,    73,    -1,    74,    -1,    20,    74,
      -1,    32,    74,    -1,    75,    -1,    39,    73,    40,    -1,
      17,    -1,    18,    -1,     7,    -1,     6,    -1,     4,    -1,
       4,    34,    73,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   106,   111,   120,   150,   155,   161,   166,
     174,   194,   200,   211,   219,   224,   230,   235,   243,   249,
     266,   276,   281,   287,   292,   300,   308,   313,   319,   324,
     332,   333,   334,   335,   336,   337,   338,   339,   342,   348,
     354,   361,   368,   373,   379,   384,   392,   399,   405,   413,
     422,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   447,   448,   449,   452,   456,   465,
     474,   480,   490,   497
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "IDENTIFIER", "BOOL", "INT",
  "RATIONAL", "IF", "ELSE", "WHILE", "VAR", "FUNCTION", "INTARRAY", "AUTO",
  "RETURN", "YIELD", "TRUE_NT", "FALSE_NT", "PLUS", "MINUS", "TIMES",
  "DIV", "AS_OP", "EQ_OP", "GT_OP", "GE_OP", "LT_OP", "LE_OP", "NE_OP",
  "AND_OP", "OR_OP", "NOT_OP", "COLON", "OPENBRACKET", "CLOSEBRACKET",
  "OPENCURLY", "CLOSECURLY", "COMMA", "OPENPAREN", "CLOSEPAREN",
  "SEMICOLON", "UNARY", "$accept", "Program", "L_NT", "F_NT", "Param_List",
  "NEParam_List", "Param", "Ident_List", "Body", "Var_Dec_List",
  "NEVar_Dec_List", "Var_Dec", "Dec_Type", "F_Dec_List", "NEF_Dec_List",
  "F_Dec", "S_List", "NES_List", "S", "Ass_S", "Arr_Ass_St", "C_S",
  "Arr_C_S", "Arg_List", "NEArg_List", "If_S", "Y_S", "If_E_S", "W_S",
  "Return_S", "Expr", "U_Lit", "Lit", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    48,
      49,    50,    50,    51,    52,    52,    53,    53,    54,    55,
      55,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      64,    65,    66,    66,    67,    67,    68,    69,    70,    71,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,    10,     1,     0,     3,     1,
       3,     3,     1,     4,     1,     0,     3,     2,     4,     1,
       4,     1,     0,     2,     1,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     7,
       7,    10,     1,     0,     3,     1,     7,     3,    11,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     2,     1,     3,     1,     1,
       1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     7,    12,
       0,     6,     9,     0,     0,     0,     0,     0,    11,     0,
       8,    10,     0,    15,     0,     0,    22,    14,     0,     0,
       5,    25,    27,    21,    24,    17,     0,     0,     0,     0,
       0,     0,    26,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    23,    16,    19,     0,    18,     0,     0,     0,
       0,    72,    71,    70,    68,    69,     0,     0,     0,     0,
      63,    66,     0,    13,    28,     0,    72,     0,     0,     0,
       0,     0,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      43,    38,     0,     0,     0,     0,    67,    59,    60,    61,
      62,    53,    54,    55,    56,    57,    58,    52,    51,    50,
      20,     0,    42,    45,     0,    27,    27,    73,     0,     0,
      72,     0,     0,     0,    40,    44,    43,    39,    46,    49,
       0,     0,     0,    27,    41,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    31,    10,    11,    12,    13,    25,    26,
      27,    28,    56,    32,    33,    34,    41,    42,    43,    44,
      45,    46,    47,   121,   122,    48,    49,    50,    51,    73,
     123,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
      15,    -2,    29,    15,  -121,    -4,  -121,  -121,    38,     6,
      22,  -121,    17,    36,    38,    39,    38,    73,  -121,    75,
    -121,  -121,    43,    69,    38,    45,    15,  -121,    40,    50,
    -121,  -121,    -1,  -121,    15,    69,    30,   -22,    47,    48,
       4,    76,  -121,    -1,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,    54,  -121,    53,     4,     4,
       4,    56,  -121,  -121,  -121,  -121,     4,     4,     4,    78,
    -121,  -121,     4,  -121,  -121,    87,    -9,    96,   216,   150,
     167,     4,  -121,  -121,   184,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,  -121,   114,    59,
       4,  -121,    72,    65,    74,   233,  -121,    44,    44,  -121,
    -121,   273,    18,    18,    18,    18,   273,   262,   250,  -121,
    -121,    71,  -121,   201,    57,    -1,    -1,  -121,    88,     4,
      -8,   132,    77,    91,  -121,  -121,     4,  -121,   103,  -121,
      90,    95,   105,    -1,  -121,   110,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,  -121,    13,  -121,    97,  -121,   -10,  -121,  -121,
     113,  -121,  -121,  -121,    98,  -121,  -120,   106,  -121,  -121,
    -121,  -121,  -121,    14,    35,  -121,  -121,  -121,  -121,  -121,
     -40,     1,  -121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      69,    57,     5,    37,    18,   132,   133,    38,    61,    39,
      62,    63,    58,     4,    29,    40,     7,    77,    78,    79,
      80,    64,    65,   145,    66,    81,    81,     1,    84,     6,
     100,   136,    98,    54,    55,     8,    67,    85,    86,    87,
      88,   105,     9,    68,    14,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    76,    16,    62,
      63,   130,    15,    62,    63,    87,    88,    82,    83,    17,
      64,    65,    19,    66,    64,    65,    21,    66,    22,    23,
      24,    35,    30,    36,   131,    67,    59,    60,    75,    67,
      81,    72,    68,    99,   120,   124,    68,    85,    86,    87,
      88,   125,    89,    90,    91,    92,    93,    94,    95,    96,
     126,   128,   141,    20,   138,    85,    86,    87,    88,    97,
      89,    90,    91,    92,    93,    94,    95,    96,   139,   134,
     142,   143,    52,    85,    86,    87,    88,   101,    89,    90,
      91,    92,    93,    94,    95,    96,   144,   146,    53,    74,
     140,    85,    86,    87,    88,   119,    89,    90,    91,    92,
      93,    94,    95,    96,   135,     0,     0,     0,     0,    85,
      86,    87,    88,   137,    89,    90,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,    85,    86,    87,    88,
     103,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,    85,    86,    87,    88,   104,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
      85,    86,    87,    88,   106,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,    85,    86,    87,    88,   129,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
       0,   102,    85,    86,    87,    88,     0,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,   127,    85,
      86,    87,    88,     0,    89,    90,    91,    92,    93,    94,
      95,    85,    86,    87,    88,     0,    89,    90,    91,    92,
      93,    94,    85,    86,    87,    88,     0,     0,    90,    91,
      92,    93
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-121))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      40,    23,     4,     4,    14,   125,   126,     8,     4,    10,
       6,     7,    34,     0,    24,    16,     3,    57,    58,    59,
      60,    17,    18,   143,    20,    34,    34,    12,    68,     0,
      39,    39,    72,     3,     4,    39,    32,    19,    20,    21,
      22,    81,     4,    39,    38,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     4,    41,     6,
       7,     4,    40,     6,     7,    21,    22,    66,    67,    33,
      17,    18,    33,    20,    17,    18,     3,    20,     3,    36,
      11,    41,    37,    33,   124,    32,    39,    39,    34,    32,
      34,    15,    39,     6,    35,    23,    39,    19,    20,    21,
      22,    36,    24,    25,    26,    27,    28,    29,    30,    31,
      36,    40,     9,    16,    37,    19,    20,    21,    22,    41,
      24,    25,    26,    27,    28,    29,    30,    31,    37,    41,
      40,    36,    34,    19,    20,    21,    22,    41,    24,    25,
      26,    27,    28,    29,    30,    31,    41,    37,    35,    43,
     136,    19,    20,    21,    22,    41,    24,    25,    26,    27,
      28,    29,    30,    31,   129,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    41,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      40,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    40,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    40,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    19,    20,    21,    22,    38,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    35,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    19,    20,    21,    22,    -1,    -1,    25,    26,
      27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    44,    45,    46,     4,     0,    46,    39,     4,
      47,    48,    49,    50,    38,    40,    41,    33,    50,    33,
      48,     3,     3,    36,    11,    51,    52,    53,    54,    50,
      37,    46,    56,    57,    58,    41,    33,     4,     8,    10,
      16,    59,    60,    61,    62,    63,    64,    65,    68,    69,
      70,    71,    57,    53,     3,     4,    55,    23,    34,    39,
      39,     4,     6,     7,    17,    18,    20,    32,    39,    73,
      74,    75,    15,    72,    60,    34,     4,    73,    73,    73,
      73,    34,    74,    74,    73,    19,    20,    21,    22,    24,
      25,    26,    27,    28,    29,    30,    31,    41,    73,     6,
      39,    41,    35,    40,    40,    73,    40,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    41,
      35,    66,    67,    73,    23,    36,    36,    35,    40,    38,
       4,    73,    59,    59,    41,    67,    39,    41,    37,    37,
      66,     9,    40,    36,    41,    59,    37
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 101 "parser.ypp"
    {
				ast = new ProgramImpl((yyvsp[(1) - (1)]).u_func_list);
		}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 107 "parser.ypp"
    {
				(yyvsp[(1) - (2)]).u_func_list->push_back((yyvsp[(2) - (2)]).u_func);
				(yyval).u_func_list = (yyvsp[(1) - (2)]).u_func_list;
		}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 112 "parser.ypp"
    {
				list<Func_ptr>* fpl = new list<Func_ptr>;
				fpl->push_back((yyvsp[(1) - (1)]).u_func);
				(yyval).u_func_list = fpl;
		}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 121 "parser.ypp"
    {
				SymName* sN = new SymName((yyvsp[(2) - (10)]).u_base_charptr);
				Type* t;
				if((yyvsp[(7) - (10)]).u_base_charptr[0] == 'b')
				{
					t = new TBoolean();
					//cout << "type is bool" << endl;
				}
				else if((yyvsp[(7) - (10)]).u_base_charptr[0] == 'i')
				{
					t = new TInteger();
					//cout << "type is int" << endl;
				}
				else if((yyvsp[(7) - (10)]).u_base_charptr[0] == 'r')
				{
					t = new TRational();
					//cout << "type is rational" << endl;
				}
				else
				{
					t = new TAuto();
					//cout << "type is auto" << endl;
				}
				FuncImpl* fI = new FuncImpl(sN,(yyvsp[(4) - (10)]).u_decl_list,t,(yyvsp[(9) - (10)]).u_funcblock);
				(yyval).u_func = fI;
		}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 151 "parser.ypp"
    {
				(yyval).u_decl_list = (yyvsp[(1) - (1)]).u_decl_list;
		}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 155 "parser.ypp"
    {
				list<Decl_ptr>* dPL = new list<Decl_ptr>;
				(yyval).u_decl_list = dPL;
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 162 "parser.ypp"
    {
				(yyvsp[(3) - (3)]).u_decl_list->push_front((yyvsp[(1) - (3)]).u_decl);
				(yyval).u_decl_list = (yyvsp[(3) - (3)]).u_decl_list;
		}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 167 "parser.ypp"
    {
				list<Decl_ptr>* dPL = new list<Decl_ptr>;
				dPL->push_back((yyvsp[(1) - (1)]).u_decl);
				(yyval).u_decl_list = dPL;
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 175 "parser.ypp"
    {
				Type* t;
				if((yyvsp[(3) - (3)]).u_base_charptr[0] == 'b')
				{
					t = new TBoolean();
				}
				else if((yyvsp[(3) - (3)]).u_base_charptr[0] == 'i')
				{
					t = new TInteger();
				}
				else
				{
					t = new TRational();
				}
				(yyval).u_decl = new DeclImpl((yyvsp[(1) - (3)]).u_symname_list,t);
		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 195 "parser.ypp"
    {
				SymName* sN = new SymName((yyvsp[(1) - (3)]).u_base_charptr);
				(yyvsp[(3) - (3)]).u_symname_list->push_front(sN);
				(yyval).u_symname_list = (yyvsp[(3) - (3)]).u_symname_list;
		}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 201 "parser.ypp"
    {
				list<SymName_ptr>* sNPl = new list<SymName_ptr>;
				SymName* sN = new SymName((yyvsp[(1) - (1)]).u_base_charptr);
				sNPl->push_back(sN);
				(yyval).u_symname_list=sNPl;
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 212 "parser.ypp"
    {
				FuncBlockImpl* fBl = new FuncBlockImpl((yyvsp[(1) - (4)]).u_decl_list,(yyvsp[(2) - (4)]).u_func_list,(yyvsp[(3) - (4)]).u_stat_list,(yyvsp[(4) - (4)]).u_return);
				(yyval).u_funcblock = fBl;
		}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 220 "parser.ypp"
    {
				(yyval).u_decl_list = (yyvsp[(1) - (1)]).u_decl_list;
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 224 "parser.ypp"
    {
				list<Decl_ptr>* dPl = new list<Decl_ptr>;
				(yyval).u_decl_list = dPl;
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 231 "parser.ypp"
    {
				(yyvsp[(3) - (3)]).u_decl_list->push_front((yyvsp[(1) - (3)]).u_decl);
				(yyval).u_decl_list = (yyvsp[(3) - (3)]).u_decl_list;
			}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 236 "parser.ypp"
    {
				list<Decl_ptr>* dPl = new list<Decl_ptr>;
				dPl->push_back((yyvsp[(1) - (2)]).u_decl);
				(yyval).u_decl_list = dPl;
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 244 "parser.ypp"
    {
				(yyval).u_decl = new DeclImpl((yyvsp[(2) - (4)]).u_symname_list,(yyvsp[(4) - (4)]).u_type);
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 250 "parser.ypp"
    {
				Type* t;
				if((yyvsp[(1) - (1)]).u_base_charptr[0] == 'b')
				{
					t = new TBoolean();
				}
				else if((yyvsp[(1) - (1)]).u_base_charptr[0] == 'i')
				{
					t = new TInteger();
				}
				else
				{
					t = new TRational();
				}
				(yyval).u_type = t;
		}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 267 "parser.ypp"
    {
				Primitive* p = new Primitive((yyvsp[(3) - (4)]).u_base_int);
				Type* t=new TIntArray(p);
				(yyval).u_type = t;
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 277 "parser.ypp"
    {
				(yyval).u_func_list = (yyvsp[(1) - (1)]).u_func_list;
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 281 "parser.ypp"
    {
				list<Func_ptr>* fPL = new list<Func_ptr>;
				(yyval).u_func_list = fPL;
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 288 "parser.ypp"
    {
				(yyvsp[(2) - (2)]).u_func_list->push_front((yyvsp[(1) - (2)]).u_func);
				(yyval).u_func_list = (yyvsp[(2) - (2)]).u_func_list;
			}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 293 "parser.ypp"
    {
				list<Func_ptr>* fPL = new list<Func_ptr>;
				fPL->push_back((yyvsp[(1) - (1)]).u_func);
				(yyval).u_func_list = fPL;
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 301 "parser.ypp"
    {
				(yyval).u_func=(yyvsp[(1) - (1)]).u_func;
		}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 309 "parser.ypp"
    {
				(yyval).u_stat_list = (yyvsp[(1) - (1)]).u_stat_list;
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 313 "parser.ypp"
    {
				list<Stat_ptr>* sPL = new list<Stat_ptr>;
				(yyval).u_stat_list = sPL;
		}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 320 "parser.ypp"
    {
				(yyvsp[(2) - (2)]).u_stat_list->push_front((yyvsp[(1) - (2)]).u_stat);
				(yyval).u_stat_list = (yyvsp[(2) - (2)]).u_stat_list;
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 325 "parser.ypp"
    {
				list<Stat_ptr>* sPL = new list<Stat_ptr>;
				sPL->push_back((yyvsp[(1) - (1)]).u_stat);
				(yyval).u_stat_list = sPL;
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 332 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 333 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 334 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 335 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 336 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 337 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 338 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 339 "parser.ypp"
    {(yyval).u_stat = (yyvsp[(1) - (1)]).u_stat;}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 343 "parser.ypp"
    {
				SymName* sN = new SymName((yyvsp[(1) - (4)]).u_base_charptr);
				(yyval).u_stat = new Assignment(sN,(yyvsp[(3) - (4)]).u_expr);
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 349 "parser.ypp"
    {
				SymName* sN = new SymName((yyvsp[(1) - (7)]).u_base_charptr);
				(yyval).u_stat = new ArrayAssignment(sN,(yyvsp[(3) - (7)]).u_expr,(yyvsp[(6) - (7)]).u_expr);
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 355 "parser.ypp"
    {
				SymName* sNX = new SymName((yyvsp[(1) - (7)]).u_base_charptr);
				SymName* sNY = new SymName((yyvsp[(3) - (7)]).u_base_charptr);
				(yyval).u_stat = new Call(sNX,sNY,(yyvsp[(5) - (7)]).u_expr_list);
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 362 "parser.ypp"
    {
				SymName* sNX = new SymName((yyvsp[(1) - (10)]).u_base_charptr);
				SymName* sNY = new SymName((yyvsp[(6) - (10)]).u_base_charptr);
				(yyval).u_stat = new ArrayCall(sNX,(yyvsp[(3) - (10)]).u_expr,sNY,(yyvsp[(8) - (10)]).u_expr_list);
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 369 "parser.ypp"
    {
				(yyval).u_expr_list = (yyvsp[(1) - (1)]).u_expr_list;
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 373 "parser.ypp"
    {
				list<Expr_ptr>* ePL = new list<Expr_ptr>;
				(yyval).u_expr_list = ePL;
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 380 "parser.ypp"
    {
				(yyvsp[(3) - (3)]).u_expr_list->push_front((yyvsp[(1) - (3)]).u_expr);
				(yyval).u_expr_list = (yyvsp[(3) - (3)]).u_expr_list;
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 385 "parser.ypp"
    {
				list<Expr_ptr>* ePL = new list<Expr_ptr>;
				ePL->push_back((yyvsp[(1) - (1)]).u_expr);
				(yyval).u_expr_list = ePL;
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 393 "parser.ypp"
    {
				StatBlockImpl* sBI = new StatBlockImpl((yyvsp[(6) - (7)]).u_stat_list); 
				(yyval).u_stat = new IfNoElse((yyvsp[(3) - (7)]).u_expr,sBI);
		}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 400 "parser.ypp"
    {
				(yyval).u_stat = new Yield((yyvsp[(2) - (3)]).u_expr);
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 406 "parser.ypp"
    {
				StatBlockImpl* sBIA = new StatBlockImpl((yyvsp[(6) - (11)]).u_stat_list); 
				StatBlockImpl* sBIB = new StatBlockImpl((yyvsp[(10) - (11)]).u_stat_list); 
				(yyval).u_stat = new IfWithElse((yyvsp[(3) - (11)]).u_expr,sBIA,sBIB);
		}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 414 "parser.ypp"
    {
				StatBlockImpl* sBI = new StatBlockImpl((yyvsp[(6) - (7)]).u_stat_list);
				(yyval).u_stat = new WhileLoop((yyvsp[(3) - (7)]).u_expr,sBI);
		}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 423 "parser.ypp"
    {
				(yyval).u_return = new ReturnImpl((yyvsp[(2) - (3)]).u_expr);
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 430 "parser.ypp"
    {(yyval).u_expr = new Or((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 431 "parser.ypp"
    {(yyval).u_expr = new And((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 432 "parser.ypp"
    {(yyval).u_expr = new Compare((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 433 "parser.ypp"
    {(yyval).u_expr = new Gt((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 434 "parser.ypp"
    {(yyval).u_expr = new Gteq((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 435 "parser.ypp"
    {(yyval).u_expr = new Lt((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 436 "parser.ypp"
    {(yyval).u_expr = new Lteq((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 437 "parser.ypp"
    {(yyval).u_expr = new Noteq((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 438 "parser.ypp"
    {(yyval).u_expr = new Plus((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 439 "parser.ypp"
    {(yyval).u_expr = new Minus((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 440 "parser.ypp"
    {(yyval).u_expr = new Times((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 441 "parser.ypp"
    {(yyval).u_expr = new Div((yyvsp[(1) - (3)]).u_expr,(yyvsp[(3) - (3)]).u_expr);}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 442 "parser.ypp"
    {(yyval).u_expr = (yyvsp[(1) - (1)]).u_expr;}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 447 "parser.ypp"
    {(yyval).u_expr = new Uminus((yyvsp[(2) - (2)]).u_expr);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 448 "parser.ypp"
    {(yyval).u_expr = new Not((yyvsp[(2) - (2)]).u_expr);}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 449 "parser.ypp"
    {(yyval).u_expr = (yyvsp[(1) - (1)]).u_expr;}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 453 "parser.ypp"
    {
			(yyval).u_expr=(yyvsp[(2) - (3)]).u_expr;
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 457 "parser.ypp"
    {
				// Primitive* p = new Primitive($1.u_base_int);
				// BoolLit* b = new BoolLit(p);
				// $$.u_expr=b;
				(yyval).u_expr = new BoolLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));
				// $$.u_type->m_attribute.m_basetype = bt_boolean;
				// $$.u_type = new TBoolean();
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 466 "parser.ypp"
    {
				// Primitive* p = new Primitive($1.u_base_int);
				// BoolLit* b = new BoolLit(p);
				// $$.u_expr=b;
				(yyval).u_expr = new BoolLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));
				// $$.u_type->m_attribute.m_basetype = bt_boolean;
				// $$.u_type = new TBoolean();
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 475 "parser.ypp"
    {
				(yyval).u_expr=(yyvsp[(1) - (1)]).u_expr;
				// $$.u_type->m_attribute.m_basetype = bt_rational;
				// $$.u_type = new TRational();
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 481 "parser.ypp"
    {
				// Primitive* p = new Primitive($1.u_base_int);
				// IntLit* i = new IntLit(p);
				// $$.u_expr=i;
				
				 (yyval).u_expr = new IntLit(new Primitive((yyvsp[(1) - (1)]).u_base_int)); // Maybe this works better
				// $$.u_type->m_attribute.m_basetype = bt_integer;
				// $$.u_type = new TInteger();
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 491 "parser.ypp"
    {
				SymName* sN = new SymName((yyvsp[(1) - (1)]).u_base_charptr);
				Ident* i = new Ident(sN);
				(yyval).u_expr=i;

		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 498 "parser.ypp"
    {
				SymName* sN = new SymName((yyvsp[(1) - (4)]).u_base_charptr);
				(yyval).u_expr = new ArrayAccess(sN,(yyvsp[(3) - (4)]).u_expr);
		}
    break;



/* Line 1806 of yacc.c  */
#line 2268 "parser.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 505 "parser.ypp"





extern int yylineno;

void yyerror(const char *s) {
	fprintf(stderr, "%s at line %d\n", s, yylineno);
	return;
}

