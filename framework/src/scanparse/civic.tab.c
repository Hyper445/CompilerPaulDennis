/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_TYPE = 258,
     FLOAT_TYPE = 259,
     BOOL_TYPE = 260,
     BRACKET_L = 261,
     BRACKET_R = 262,
     COMMA = 263,
     SEMICOLON = 264,
     MINUS = 265,
     PLUS = 266,
     STAR = 267,
     SLASH = 268,
     PERCENT = 269,
     LE = 270,
     LT = 271,
     GE = 272,
     GT = 273,
     EQ = 274,
     NE = 275,
     OR = 276,
     AND = 277,
     TRUEVAL = 278,
     FALSEVAL = 279,
     LET = 280,
     INTTYPE = 281,
     FLOATTYPE = 282,
     BOOLTYPE = 283,
     CURLY_BRACKET_L = 284,
     CURLY_BRACKET_R = 285,
     RETURN = 286,
     IF = 287,
     ELSE = 288,
     FOR = 289,
     DO = 290,
     WHILE = 291,
     NUM = 292,
     FLOAT = 293,
     ID = 294
   };
#endif
/* Tokens.  */
#define INT_TYPE 258
#define FLOAT_TYPE 259
#define BOOL_TYPE 260
#define BRACKET_L 261
#define BRACKET_R 262
#define COMMA 263
#define SEMICOLON 264
#define MINUS 265
#define PLUS 266
#define STAR 267
#define SLASH 268
#define PERCENT 269
#define LE 270
#define LT 271
#define GE 272
#define GT 273
#define EQ 274
#define NE 275
#define OR 276
#define AND 277
#define TRUEVAL 278
#define FALSEVAL 279
#define LET 280
#define INTTYPE 281
#define FLOATTYPE 282
#define BOOLTYPE 283
#define CURLY_BRACKET_L 284
#define CURLY_BRACKET_R 285
#define RETURN 286
#define IF 287
#define ELSE 288
#define FOR 289
#define DO 290
#define WHILE 291
#define NUM 292
#define FLOAT 293
#define ID 294




/* Copy the first part of user declarations.  */
#line 1 "src/scanparse/civic.y"



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "types.h"
#include "tree_basic.h"
#include "str.h"
#include "dbug.h"
#include "ctinfo.h"
#include "free.h"
#include "globals.h"

static node *parseresult = NULL;
extern int yylex();
static int yyerror( char *errname);

// this is a test comment for a test commit.


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "src/scanparse/civic.y"
{
 nodetype            nodetype;
 char               *id;
 int                 cint;
 float               cflt;
 binop               cbinop;
 node               *node;
 type                ctype;
}
/* Line 193 of yacc.c.  */
#line 207 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    21,
      25,    31,    38,    43,    47,    52,    55,    58,    60,    63,
      65,    71,    76,    81,    86,    90,    94,    98,   101,   109,
     116,   123,   130,   136,   142,   148,   152,   155,   157,   159,
     161,   163,   165,   167,   169,   173,   176,   184,   190,   200,
     207,   211,   216,   228,   242,   255,   270,   280,   288,   290,
     292,   294,   300,   302,   305,   307,   309,   311,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    -1,    43,    42,    -1,
      46,    -1,    45,    -1,    44,    -1,    69,    39,    49,     9,
      -1,    69,    39,     9,    -1,    69,    39,    25,    62,     9,
      -1,    69,    39,     6,    47,     7,    50,    -1,    69,    39,
      49,    47,    -1,    69,    39,    49,    -1,    69,    39,     8,
      47,    -1,    69,    39,    -1,    46,    48,    -1,    46,    -1,
      39,    49,    -1,    39,    -1,    29,    51,    48,    52,    30,
      -1,    29,    48,    52,    30,    -1,    29,    51,    52,    30,
      -1,    29,    51,    48,    30,    -1,    29,    51,    30,    -1,
      29,    52,    30,    -1,    29,    48,    30,    -1,    29,    30,
      -1,    69,    39,    25,    63,    62,     9,    51,    -1,    69,
      39,    25,    63,    62,     9,    -1,    69,    39,    25,    63,
       9,    51,    -1,    69,    39,    25,    62,     9,    51,    -1,
      69,    39,    25,    63,     9,    -1,    69,    39,    25,    62,
       9,    -1,    69,    39,    25,     9,    51,    -1,    69,    39,
       9,    -1,    53,    52,    -1,    53,    -1,    57,    -1,    54,
      -1,    55,    -1,    58,    -1,    59,    -1,    60,    -1,    31,
      62,     9,    -1,    31,     9,    -1,    32,     6,    62,     7,
      56,    33,    56,    -1,    32,     6,    62,     7,    56,    -1,
      32,     6,    62,     7,    29,    30,    33,    29,    30,    -1,
      32,     6,    62,     7,    29,    30,    -1,    29,    52,    30,
      -1,    61,    25,    62,     9,    -1,    34,     6,    69,    39,
      25,    62,     8,    62,     7,    29,    30,    -1,    34,     6,
      69,    39,    25,    62,     8,    62,     8,    62,     7,    29,
      30,    -1,    34,     6,    69,    39,    25,    62,     8,    62,
       7,    29,    52,    30,    -1,    34,     6,    69,    39,    25,
      62,     8,    62,     8,    62,     7,    29,    52,    30,    -1,
      35,    29,    52,    30,    36,     6,    62,     7,     9,    -1,
      36,     6,    62,     7,    29,    52,    30,    -1,    39,    -1,
      64,    -1,    39,    -1,     6,    62,    68,    62,     7,    -1,
      62,    -1,    62,    63,    -1,    65,    -1,    66,    -1,    67,
      -1,    38,    -1,    37,    -1,    23,    -1,    24,    -1,    11,
      -1,    10,    -1,    12,    -1,    13,    -1,    14,    -1,    15,
      -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,    21,
      -1,    22,    -1,     3,    -1,     4,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    65,    69,    75,    79,    83,    89,    93,
      99,   105,   111,   115,   119,   123,   129,   133,   139,   143,
     148,   152,   156,   160,   164,   168,   172,   176,   182,   186,
     190,   194,   198,   202,   206,   210,   215,   219,   225,   229,
     233,   237,   241,   245,   251,   255,   261,   265,   269,   273,
     279,   285,   291,   295,   299,   303,   309,   314,   319,   326,
     330,   334,   340,   344,   350,   354,   358,   364,   370,   376,
     380,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   401,   402,   403
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TYPE", "FLOAT_TYPE", "BOOL_TYPE",
  "BRACKET_L", "BRACKET_R", "COMMA", "SEMICOLON", "MINUS", "PLUS", "STAR",
  "SLASH", "PERCENT", "LE", "LT", "GE", "GT", "EQ", "NE", "OR", "AND",
  "TRUEVAL", "FALSEVAL", "LET", "INTTYPE", "FLOATTYPE", "BOOLTYPE",
  "CURLY_BRACKET_L", "CURLY_BRACKET_R", "RETURN", "IF", "ELSE", "FOR",
  "DO", "WHILE", "NUM", "FLOAT", "ID", "$accept", "program", "decls",
  "decl", "globdecl", "globdef", "fundef", "param", "fundefs", "ids",
  "funbody", "vardecl", "stmts", "stmt", "return", "ifelse", "block",
  "assign", "for", "doWhile", "while", "varlet", "expr", "exprs",
  "constant", "floatval", "intval", "boolval", "binop", "type", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    46,    47,    47,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      56,    57,    58,    58,    58,    58,    59,    60,    61,    62,
      62,    62,    63,    63,    64,    64,    64,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     4,     3,
       5,     6,     4,     3,     4,     2,     2,     1,     2,     1,
       5,     4,     4,     4,     3,     3,     3,     2,     7,     6,
       6,     6,     5,     5,     5,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     7,     5,     9,     6,
       3,     4,    11,    13,    12,    14,     9,     7,     1,     1,
       1,     5,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    84,    85,     0,     2,     3,     7,     6,     5,
       0,     1,     4,     0,     0,     9,     0,    19,     0,     0,
       0,     0,    69,    70,    68,    67,    60,     0,    59,    64,
      65,    66,    18,     8,     0,    15,     0,    10,     0,    11,
       0,    13,    72,    71,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    27,     0,     0,     0,     0,
       0,    58,    17,     0,     0,     0,    37,    39,    40,    38,
      41,    42,    43,     0,     0,    14,    12,     0,    45,     0,
       0,     0,     0,     0,    16,     0,    26,     0,    24,     0,
       0,    25,    36,     0,     0,    61,    44,     0,     0,     0,
       0,     0,    21,    23,     0,    22,     0,    35,     0,     0,
       0,     0,     0,    20,    51,     0,     0,     0,     0,    47,
       0,     0,     0,    34,     0,    33,    62,    63,    32,     0,
      49,     0,     0,     0,     0,     0,     0,    31,    30,    29,
       0,    50,     0,    46,     0,     0,    57,    28,     0,     0,
       0,    48,     0,     0,    56,     0,     0,    52,     0,     0,
      54,     0,    53,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    62,    19,    63,    18,
      39,    64,   131,    66,    67,    68,   119,    69,    70,    71,
      72,    73,   126,   127,    28,    29,    30,    31,    54,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
       6,  -103,  -103,  -103,    29,  -103,     6,  -103,  -103,  -103,
      16,  -103,  -103,    51,     6,  -103,    97,    19,    59,    64,
      33,    97,  -103,  -103,  -103,  -103,  -103,    66,  -103,  -103,
    -103,  -103,  -103,  -103,    52,    11,   136,  -103,    13,  -103,
       6,     6,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,    97,  -103,    -3,    79,    85,    65,
      87,  -103,     6,   129,    75,    70,   175,  -103,  -103,  -103,
    -103,  -103,  -103,    71,    56,  -103,  -103,    95,  -103,    99,
      97,     6,   175,    97,  -103,    74,  -103,    86,  -103,   139,
      92,  -103,  -103,    97,    45,  -103,  -103,   110,    84,    94,
     119,   121,  -103,  -103,   101,  -103,   123,  -103,    50,   104,
     113,   103,   111,  -103,  -103,     6,    60,   106,   149,   108,
      97,   150,   175,  -103,   127,     6,    97,  -103,     6,   133,
     134,   132,   143,   168,    97,   147,    -1,  -103,  -103,     6,
     153,  -103,   175,  -103,    97,   179,  -103,  -103,   157,    54,
     183,  -103,   167,    97,  -103,   159,   190,  -103,   172,   184,
    -103,   169,  -103,   182,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   209,  -103,  -103,  -103,    25,    -8,   -50,   -13,
    -103,  -102,   -36,  -103,  -103,  -103,    88,  -103,  -103,  -103,
    -103,  -103,   -16,   109,  -103,  -103,  -103,  -103,  -103,     1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    10,    65,    21,    32,    36,    78,    10,   107,     1,
       2,     3,    84,   123,    89,    20,     1,     2,     3,    40,
      22,    23,    41,   137,   108,     9,   138,    87,    90,    11,
      92,     9,    75,    76,    24,    25,    26,   147,    77,    74,
      79,    20,    20,    55,    56,    57,    99,    58,    59,    60,
      17,    14,    61,   104,   107,    13,    21,    14,    17,   115,
      15,   152,   153,    85,    97,    85,    21,   100,    33,   125,
     108,    34,    35,    22,    23,    37,    16,   106,     1,     2,
       3,    38,    98,    22,    23,    80,   135,    24,    25,    26,
      17,    81,   116,    83,    82,    94,    93,    24,    25,    26,
      91,   129,    95,    21,   133,    88,    56,    57,    96,    58,
      59,    60,    21,   101,    61,   128,   102,   109,   145,   158,
      22,    23,   105,   110,   111,   163,   112,    14,   149,    22,
      23,   113,   114,   118,    24,    25,    26,   156,   120,   121,
     122,   132,   139,    24,    25,    26,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   134,    52,    53,    86,
      56,    57,   141,    58,    59,    60,   136,   140,    61,   103,
      56,    57,   142,    58,    59,    60,   144,   146,    61,   130,
      56,    57,   148,    58,    59,    60,   150,   151,    61,   157,
      56,    57,   154,    58,    59,    60,   155,   159,    61,   162,
      56,    57,   160,    58,    59,    60,    56,    57,    61,    58,
      59,    60,   164,   161,    61,    12,     0,   117,     0,     0,
     143
};

static const yytype_int16 yycheck[] =
{
      16,     0,    38,     6,    17,    21,     9,     6,     9,     3,
       4,     5,    62,   115,    64,    14,     3,     4,     5,     8,
      23,    24,    35,   125,    25,     0,   128,    63,    64,     0,
      66,     6,    40,    41,    37,    38,    39,   139,    54,    38,
      56,    40,    41,    30,    31,    32,    82,    34,    35,    36,
      39,     6,    39,    89,     9,    39,     6,     6,    39,     9,
       9,     7,     8,    62,    80,    64,     6,    83,     9,     9,
      25,     7,    39,    23,    24,     9,    25,    93,     3,     4,
       5,    29,    81,    23,    24,     6,   122,    37,    38,    39,
      39,     6,   108,     6,    29,    39,    25,    37,    38,    39,
      30,   117,     7,     6,   120,    30,    31,    32,     9,    34,
      35,    36,     6,    39,    39,     9,    30,     7,   134,   155,
      23,    24,    30,    39,    30,   161,     7,     6,   144,    23,
      24,    30,     9,    29,    37,    38,    39,   153,    25,    36,
      29,    33,     9,    37,    38,    39,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     6,    21,    22,    30,
      31,    32,    30,    34,    35,    36,    39,    33,    39,    30,
      31,    32,    29,    34,    35,    36,     8,    30,    39,    30,
      31,    32,    29,    34,    35,    36,     7,    30,    39,    30,
      31,    32,     9,    34,    35,    36,    29,     7,    39,    30,
      31,    32,    30,    34,    35,    36,    31,    32,    39,    34,
      35,    36,    30,    29,    39,     6,    -1,   108,    -1,    -1,
     132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    41,    42,    43,    44,    45,    46,
      69,     0,    42,    39,     6,     9,    25,    39,    49,    47,
      69,     6,    23,    24,    37,    38,    39,    62,    64,    65,
      66,    67,    49,     9,     7,    39,    62,     9,    29,    50,
       8,    49,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    21,    22,    68,    30,    31,    32,    34,    35,
      36,    39,    46,    48,    51,    52,    53,    54,    55,    57,
      58,    59,    60,    61,    69,    47,    47,    62,     9,    62,
       6,     6,    29,     6,    48,    69,    30,    52,    30,    48,
      52,    30,    52,    25,    39,     7,     9,    62,    69,    52,
      62,    39,    30,    30,    52,    30,    62,     9,    25,     7,
      39,    30,     7,    30,     9,     9,    62,    63,    29,    56,
      25,    36,    29,    51,    69,     9,    62,    63,     9,    62,
      30,    52,    33,    62,     6,    52,    39,    51,    51,     9,
      33,    30,    29,    56,     8,    62,    30,    51,    29,    62,
       7,    30,     7,     8,     9,    29,    62,    30,    52,     7,
      30,    29,    30,    52,    30
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 60 "src/scanparse/civic.y"
    {
    parseresult = (yyvsp[(1) - (1)].node);      
  }
    break;

  case 3:
#line 66 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDecls((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 4:
#line 70 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDecls((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 5:
#line 76 "src/scanparse/civic.y"
    { 
    (yyval.node) = (yyvsp[(1) - (1)].node); 
  }
    break;

  case 6:
#line 80 "src/scanparse/civic.y"
    { 
    (yyval.node) = (yyvsp[(1) - (1)].node); 
  }
    break;

  case 7:
#line 84 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 8:
#line 90 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdecl((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), (yyvsp[(3) - (4)].node));
  }
    break;

  case 9:
#line 94 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdecl((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), NULL);
  }
    break;

  case 10:
#line 100 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, (yyvsp[(4) - (5)].node));
  }
    break;

  case 11:
#line 106 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
  }
    break;

  case 12:
#line 112 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
  }
    break;

  case 13:
#line 116 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), (yyvsp[(3) - (3)].node), NULL);
  }
    break;

  case 14:
#line 120 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), NULL, (yyvsp[(4) - (4)].node));
  }
    break;

  case 15:
#line 124 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (2)].ctype), (yyvsp[(2) - (2)].id), NULL, NULL);
  }
    break;

  case 16:
#line 130 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundefs((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 17:
#line 134 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundefs((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 18:
#line 140 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIds(STRcpy((yyvsp[(1) - (2)].id)), (yyvsp[(2) - (2)].node));
  }
    break;

  case 19:
#line 144 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIds(STRcpy((yyvsp[(1) - (1)].id)), NULL);
  }
    break;

  case 20:
#line 149 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node));
  }
    break;

  case 21:
#line 153 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));
  }
    break;

  case 22:
#line 157 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (4)].node), NULL, (yyvsp[(3) - (4)].node));
  }
    break;

  case 23:
#line 161 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), NULL);
  }
    break;

  case 24:
#line 165 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (3)].node), NULL, NULL);
  }
    break;

  case 25:
#line 169 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, NULL, (yyvsp[(2) - (3)].node));
  }
    break;

  case 26:
#line 173 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(2) - (3)].node), NULL);
  }
    break;

  case 27:
#line 177 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, NULL, NULL);
  }
    break;

  case 28:
#line 183 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (7)].ctype), STRcpy((yyvsp[(2) - (7)].id)), (yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  }
    break;

  case 29:
#line 187 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), (yyvsp[(5) - (6)].node), NULL);
  }
    break;

  case 30:
#line 191 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), NULL, (yyvsp[(6) - (6)].node));
  }
    break;

  case 31:
#line 195 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), NULL, (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
  }
    break;

  case 32:
#line 199 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), (yyvsp[(4) - (5)].node), NULL, NULL);
  }
    break;

  case 33:
#line 203 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, (yyvsp[(4) - (5)].node), NULL);
  }
    break;

  case 34:
#line 207 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, NULL, (yyvsp[(5) - (5)].node));
  }
    break;

  case 35:
#line 211 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), NULL, NULL, NULL);
  }
    break;

  case 36:
#line 216 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeStmts( (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 37:
#line 220 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeStmts( (yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 38:
#line 226 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 39:
#line 230 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 40:
#line 234 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 41:
#line 238 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 42:
#line 242 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 43:
#line 246 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 44:
#line 252 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeReturn((yyvsp[(2) - (3)].node));
  }
    break;

  case 45:
#line 256 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeReturn(NULL);
  }
    break;

  case 46:
#line 262 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  }
    break;

  case 47:
#line 266 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL);
  }
    break;

  case 48:
#line 270 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (9)].node), NULL, NULL);
  }
    break;

  case 49:
#line 274 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (6)].node), NULL, NULL);
  }
    break;

  case 50:
#line 280 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  }
    break;

  case 51:
#line 286 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeAssign( (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
  }
    break;

  case 52:
#line 292 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (11)].id), (yyvsp[(6) - (11)].node), (yyvsp[(8) - (11)].node), NULL, NULL);
  }
    break;

  case 53:
#line 296 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (13)].id), (yyvsp[(6) - (13)].node), (yyvsp[(8) - (13)].node), (yyvsp[(10) - (13)].node), NULL);
  }
    break;

  case 54:
#line 300 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (12)].id), (yyvsp[(6) - (12)].node), (yyvsp[(8) - (12)].node), NULL, (yyvsp[(11) - (12)].node));
  }
    break;

  case 55:
#line 304 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (14)].id), (yyvsp[(6) - (14)].node), (yyvsp[(8) - (14)].node), (yyvsp[(10) - (14)].node), (yyvsp[(13) - (14)].node));
  }
    break;

  case 56:
#line 310 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDowhile( (yyvsp[(7) - (9)].node), (yyvsp[(3) - (9)].node));
  }
    break;

  case 57:
#line 315 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeWhile( (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
  }
    break;

  case 58:
#line 320 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVarlet( STRcpy( (yyvsp[(1) - (1)].id)), NULL, NULL);
  }
    break;

  case 59:
#line 327 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 60:
#line 331 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVar( STRcpy( (yyvsp[(1) - (1)].id)), NULL, NULL);
  }
    break;

  case 61:
#line 335 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeBinop( (yyvsp[(3) - (5)].cbinop), (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
  }
    break;

  case 62:
#line 341 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprs((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 63:
#line 345 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprs((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 64:
#line 351 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 65:
#line 355 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 66:
#line 359 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 67:
#line 365 "src/scanparse/civic.y"
    {
             (yyval.node) = TBmakeFloat( (yyvsp[(1) - (1)].cflt));
           }
    break;

  case 68:
#line 371 "src/scanparse/civic.y"
    {
          (yyval.node) = TBmakeNum( (yyvsp[(1) - (1)].cint));
        }
    break;

  case 69:
#line 377 "src/scanparse/civic.y"
    {
           (yyval.node) = TBmakeBool( TRUE);
         }
    break;

  case 70:
#line 381 "src/scanparse/civic.y"
    {
           (yyval.node) = TBmakeBool( FALSE);
         }
    break;

  case 71:
#line 386 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_add; }
    break;

  case 72:
#line 387 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_sub; }
    break;

  case 73:
#line 388 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_mul; }
    break;

  case 74:
#line 389 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_div; }
    break;

  case 75:
#line 390 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_mod; }
    break;

  case 76:
#line 391 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_le; }
    break;

  case 77:
#line 392 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_lt; }
    break;

  case 78:
#line 393 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_ge; }
    break;

  case 79:
#line 394 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_gt; }
    break;

  case 80:
#line 395 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_eq; }
    break;

  case 81:
#line 396 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_or; }
    break;

  case 82:
#line 397 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_and; }
    break;

  case 83:
#line 401 "src/scanparse/civic.y"
    { (yyval.ctype) = T_int;}
    break;

  case 84:
#line 402 "src/scanparse/civic.y"
    { (yyval.ctype) = T_float;}
    break;

  case 85:
#line 403 "src/scanparse/civic.y"
    { (yyval.ctype) = T_bool;}
    break;


/* Line 1267 of yacc.c.  */
#line 2134 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 406 "src/scanparse/civic.y"


static int yyerror( char *error)
{
  CTIabort( "line %d, col %d\nError parsing source code: %s\n", 
            global.line, global.col, error);

  return( 0);
}

node *YYparseTree( void)
{
  DBUG_ENTER("YYparseTree");

  yyparse();

  DBUG_RETURN( parseresult);
}


