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
     NOT = 278,
     NEG = 279,
     TRUEVAL = 280,
     FALSEVAL = 281,
     LET = 282,
     INTTYPE = 283,
     FLOATTYPE = 284,
     BOOLTYPE = 285,
     CURLY_BRACKET_L = 286,
     CURLY_BRACKET_R = 287,
     RETURN = 288,
     SQUARE_BRACKET_L = 289,
     SQUARE_BRACKET_R = 290,
     EXTERN = 291,
     EXPORT = 292,
     IF = 293,
     ELSE = 294,
     FOR = 295,
     DO = 296,
     WHILE = 297,
     NUM = 298,
     FLOAT = 299,
     ID = 300
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
#define NOT 278
#define NEG 279
#define TRUEVAL 280
#define FALSEVAL 281
#define LET 282
#define INTTYPE 283
#define FLOATTYPE 284
#define BOOLTYPE 285
#define CURLY_BRACKET_L 286
#define CURLY_BRACKET_R 287
#define RETURN 288
#define SQUARE_BRACKET_L 289
#define SQUARE_BRACKET_R 290
#define EXTERN 291
#define EXPORT 292
#define IF 293
#define ELSE 294
#define FOR 295
#define DO 296
#define WHILE 297
#define NUM 298
#define FLOAT 299
#define ID 300




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
 monop               cmonop;
 node               *node;
 type                ctype;
}
/* Line 193 of yacc.c.  */
#line 220 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 233 "y.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    22,
      27,    36,    43,    48,    56,    62,    66,    74,    81,    89,
      96,   102,   109,   114,   118,   123,   126,   129,   131,   134,
     136,   142,   147,   152,   157,   161,   165,   169,   172,   180,
     187,   194,   201,   207,   213,   219,   223,   226,   228,   230,
     232,   234,   236,   238,   240,   243,   247,   250,   258,   264,
     274,   283,   290,   294,   299,   311,   325,   338,   353,   363,
     371,   373,   375,   377,   380,   386,   388,   390,   392,   397,
     402,   406,   410,   412,   416,   418,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   440,   442,   444,   446,
     448,   450,   452,   454,   456,   458,   460,   462
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    49,    48,    -1,
      52,    -1,    51,    -1,    50,    -1,    36,    79,    45,    55,
       9,    -1,    36,    79,    45,     9,    -1,    37,    79,    45,
      27,    68,     8,    72,     9,    -1,    37,    79,    45,    27,
      68,     9,    -1,    37,    79,    45,     9,    -1,    79,    45,
      27,    68,     8,    72,     9,    -1,    79,    45,    27,    68,
       9,    -1,    79,    45,     9,    -1,    37,    79,    45,     6,
       7,    31,    32,    -1,    37,    79,    45,     6,     7,    56,
      -1,    37,    79,    45,     6,    53,     7,    56,    -1,    79,
      45,     6,     7,    31,    32,    -1,    79,    45,     6,     7,
      56,    -1,    79,    45,     6,    53,     7,    56,    -1,    79,
      45,    55,    53,    -1,    79,    45,    55,    -1,    79,    45,
       8,    53,    -1,    79,    45,    -1,    52,    54,    -1,    52,
      -1,    45,    55,    -1,    45,    -1,    31,    57,    54,    58,
      32,    -1,    31,    54,    58,    32,    -1,    31,    57,    58,
      32,    -1,    31,    57,    54,    32,    -1,    31,    57,    32,
      -1,    31,    58,    32,    -1,    31,    54,    32,    -1,    31,
      32,    -1,    79,    45,    27,    72,    68,     9,    57,    -1,
      79,    45,    27,    72,    68,     9,    -1,    79,    45,    27,
      72,     9,    57,    -1,    79,    45,    27,    68,     9,    57,
      -1,    79,    45,    27,    72,     9,    -1,    79,    45,    27,
      68,     9,    -1,    79,    45,    27,     9,    57,    -1,    79,
      45,     9,    -1,    59,    58,    -1,    59,    -1,    63,    -1,
      60,    -1,    61,    -1,    64,    -1,    65,    -1,    66,    -1,
      68,     9,    -1,    33,    68,     9,    -1,    33,     9,    -1,
      38,     6,    68,     7,    62,    39,    62,    -1,    38,     6,
      68,     7,    62,    -1,    38,     6,    68,     7,    31,    32,
      39,    31,    32,    -1,    38,     6,    68,     7,    31,    32,
      39,    62,    -1,    38,     6,    68,     7,    31,    32,    -1,
      31,    58,    32,    -1,    67,    27,    68,     9,    -1,    40,
       6,    79,    45,    27,    68,     8,    68,     7,    31,    32,
      -1,    40,     6,    79,    45,    27,    68,     8,    68,     8,
      68,     7,    31,    32,    -1,    40,     6,    79,    45,    27,
      68,     8,    68,     7,    31,    58,    32,    -1,    40,     6,
      79,    45,    27,    68,     8,    68,     8,    68,     7,    31,
      58,    32,    -1,    41,    31,    58,    32,    42,     6,    68,
       7,     9,    -1,    42,     6,    68,     7,    31,    58,    32,
      -1,    45,    -1,    73,    -1,    45,    -1,    78,    68,    -1,
       6,    68,    77,    68,     7,    -1,    69,    -1,    70,    -1,
      71,    -1,     6,    79,     7,    68,    -1,    45,     6,    72,
       7,    -1,    45,     6,     7,    -1,    34,    72,    35,    -1,
      68,    -1,    68,     8,    72,    -1,    74,    -1,    75,    -1,
      76,    -1,    44,    -1,    43,    -1,    25,    -1,    26,    -1,
      11,    -1,    10,    -1,    12,    -1,    13,    -1,    14,    -1,
      15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      21,    -1,    22,    -1,    23,    -1,    10,    -1,     3,    -1,
       4,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    69,    73,    79,    83,    87,    93,    97,
     103,   107,   111,   115,   119,   123,   129,   133,   137,   141,
     145,   149,   155,   159,   163,   167,   173,   177,   183,   187,
     192,   196,   200,   204,   208,   212,   216,   220,   226,   230,
     234,   238,   242,   246,   250,   254,   259,   263,   269,   273,
     277,   281,   285,   289,   293,   299,   303,   309,   313,   317,
     321,   325,   331,   337,   343,   347,   351,   355,   361,   366,
     376,   383,   387,   391,   395,   399,   403,   407,   413,   420,
     424,   430,   436,   440,   446,   450,   454,   460,   466,   472,
     476,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   496,   497,   500,   501,   502
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
  "NOT", "NEG", "TRUEVAL", "FALSEVAL", "LET", "INTTYPE", "FLOATTYPE",
  "BOOLTYPE", "CURLY_BRACKET_L", "CURLY_BRACKET_R", "RETURN",
  "SQUARE_BRACKET_L", "SQUARE_BRACKET_R", "EXTERN", "EXPORT", "IF", "ELSE",
  "FOR", "DO", "WHILE", "NUM", "FLOAT", "ID", "$accept", "program",
  "decls", "decl", "globdecl", "globdef", "fundef", "param", "fundefs",
  "ids", "funbody", "vardecl", "stmts", "stmt", "return", "ifelse",
  "block", "assign", "for", "dowhile", "while", "varlet", "expr", "cast",
  "funcall", "arrexpr", "exprs", "constant", "floatval", "intval",
  "boolval", "binop", "monop", "type", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    62,    63,    64,    64,    64,    64,    65,    66,
      67,    68,    68,    68,    68,    68,    68,    68,    69,    70,
      70,    71,    72,    72,    73,    73,    73,    74,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     5,     4,
       8,     6,     4,     7,     5,     3,     7,     6,     7,     6,
       5,     6,     4,     3,     4,     2,     2,     1,     2,     1,
       5,     4,     4,     4,     3,     3,     3,     2,     7,     6,
       6,     6,     5,     5,     5,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     7,     5,     9,
       8,     6,     3,     4,    11,    13,    12,    14,     9,     7,
       1,     1,     1,     2,     5,     1,     1,     1,     4,     4,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   105,   106,   107,     0,     0,     0,     2,     3,     7,
       6,     5,     0,     0,     0,     1,     4,     0,     0,     0,
       0,    15,     0,     9,    29,     0,     0,    12,     0,     0,
       0,     0,     0,   104,   103,    89,    90,     0,    88,    87,
      72,     0,    75,    76,    77,    71,    84,    85,    86,     0,
      28,     8,     0,     0,     0,     0,    20,     0,    25,     0,
       0,    82,     0,     0,     0,    14,    73,     0,    17,     0,
       0,    11,    19,     0,     0,     0,     0,     0,     0,    70,
      27,     0,     0,     0,    47,    49,    50,    48,    51,    52,
      53,     0,     0,     0,     0,    21,     0,    23,    92,    91,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,    81,    80,     0,     0,    16,    18,     0,
      56,     0,     0,     0,     0,     0,     0,    26,     0,    36,
       0,    34,     0,     0,    35,    46,     0,    54,     0,    37,
      24,    22,     0,    78,    83,    79,    13,    10,    55,     0,
       0,     0,     0,     0,     0,    31,    33,     0,    32,     0,
      45,     0,    74,     0,     0,     0,     0,    30,    63,     0,
      82,     0,     0,    58,     0,     0,     0,    44,     0,    43,
      42,     0,    61,     0,     0,     0,     0,     0,     0,    41,
      40,    39,     0,    62,     0,    57,     0,     0,    69,    38,
       0,    60,     0,     0,    59,     0,     0,    68,     0,     0,
      64,     0,     0,    66,     0,    65,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    80,    30,    81,    25,
      56,    82,    83,    84,    85,    86,   173,    87,    88,    89,
      90,    91,    92,    42,    43,    44,    62,    45,    46,    47,
      48,   110,    49,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -151
static const yytype_int16 yypact[] =
{
      32,  -151,  -151,  -151,   115,   115,    31,  -151,    32,  -151,
    -151,  -151,     9,    30,    36,  -151,  -151,    12,     6,    17,
     109,  -151,   472,  -151,    43,    68,   134,  -151,   472,    55,
      85,    54,    53,  -151,  -151,  -151,  -151,   472,  -151,  -151,
      95,    56,  -151,  -151,  -151,  -151,  -151,  -151,  -151,   472,
    -151,  -151,    72,   114,    62,   167,  -151,    96,    -5,   508,
     128,   139,   116,   100,   472,  -151,  -151,   192,  -151,    96,
     472,  -151,  -151,   123,   115,   146,   148,   124,   150,    41,
      80,   267,   217,   126,   417,  -151,  -151,  -151,  -151,  -151,
    -151,   132,   151,   117,   242,  -151,   115,   115,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
     472,   472,   472,  -151,  -151,   154,   155,  -151,  -151,   165,
    -151,   169,   118,   472,   115,   417,   472,  -151,   131,  -151,
     149,  -151,   292,   152,  -151,  -151,   472,  -151,    39,  -151,
    -151,  -151,   175,  -151,  -151,  -151,  -151,  -151,  -151,   177,
     179,   142,   156,   182,   188,  -151,  -151,   171,  -151,   197,
    -151,   443,  -151,   183,   186,   174,   200,  -151,  -151,   115,
     122,   466,   317,   180,   472,   222,   417,  -151,   193,   115,
     115,   230,   202,   212,   225,   245,   472,   231,    -3,  -151,
    -151,   115,   233,  -151,   417,  -151,   472,   259,  -151,  -151,
     342,  -151,   101,   260,  -151,   239,   472,  -151,   367,   264,
    -151,   240,   247,  -151,   392,  -151,   249,  -151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,   280,  -151,  -151,  -151,    25,   -24,    13,     3,
     -35,  -150,   -72,  -151,  -151,  -151,  -146,  -151,  -151,  -151,
    -151,  -151,   -21,  -151,  -151,  -151,   -50,  -151,  -151,  -151,
    -151,  -151,  -151,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      12,    41,    53,    96,    13,    14,   160,    54,    12,   130,
     133,    59,   135,   115,   116,    23,    61,    68,    20,   177,
     119,    21,    95,    26,   161,    11,    27,    50,    66,   189,
     190,    15,    60,    11,   118,     1,     2,     3,   195,    22,
      24,   199,    61,    61,    28,    20,   201,    63,   160,    61,
     -72,    24,   121,   152,    17,    93,     1,     2,     3,    32,
     157,    97,   144,    33,    64,    65,   161,    93,     4,     5,
      70,    71,   140,   141,   122,    18,    34,    51,    35,    36,
     128,    19,   128,     1,     2,     3,    55,    37,    24,   142,
     143,    61,    57,   127,    93,   132,    38,    39,    40,    58,
     183,    63,   150,    67,   187,   153,    32,   114,   205,   206,
      33,   171,     1,     2,     3,   159,    29,    74,     1,     2,
       3,    69,   183,    34,   151,    35,    36,    94,   183,    32,
     112,   179,   120,    33,    37,   111,   211,     1,     2,     3,
     170,    52,   216,    38,    39,    40,    34,   112,    35,    36,
     181,   113,   123,   185,   124,   125,   126,    37,   134,   136,
     137,   145,   138,   149,   146,   197,    38,    39,    40,   178,
       1,     2,     3,    32,   147,   202,   154,    33,   148,   178,
     178,   155,   162,    26,   158,   209,   163,   164,   165,   166,
      34,   178,    35,    36,    20,     1,     2,     3,    32,    72,
      73,    37,    33,   167,    74,    75,   168,    76,    77,    78,
      38,    39,    79,   174,   172,    34,   175,    35,    36,   184,
       1,     2,     3,    32,   117,    73,    37,    33,   186,    74,
      75,   176,    76,    77,    78,    38,    39,    79,   188,   191,
      34,   192,    35,    36,   193,     1,     2,     3,    32,   131,
      73,    37,    33,   196,    74,    75,   194,    76,    77,    78,
      38,    39,    79,   198,   200,    34,   203,    35,    36,   207,
     208,   212,   213,    32,   139,    73,    37,    33,   214,    74,
      75,   217,    76,    77,    78,    38,    39,    79,    16,     0,
      34,     0,    35,    36,     0,     0,     0,     0,    32,   129,
      73,    37,    33,     0,     0,    75,     0,    76,    77,    78,
      38,    39,    79,     0,     0,    34,     0,    35,    36,     0,
       0,     0,     0,    32,   156,    73,    37,    33,     0,     0,
      75,     0,    76,    77,    78,    38,    39,    79,     0,     0,
      34,     0,    35,    36,     0,     0,     0,     0,    32,   182,
      73,    37,    33,     0,     0,    75,     0,    76,    77,    78,
      38,    39,    79,     0,     0,    34,     0,    35,    36,     0,
       0,     0,     0,    32,   204,    73,    37,    33,     0,     0,
      75,     0,    76,    77,    78,    38,    39,    79,     0,     0,
      34,     0,    35,    36,     0,     0,     0,     0,    32,   210,
      73,    37,    33,     0,     0,    75,     0,    76,    77,    78,
      38,    39,    79,     0,     0,    34,     0,    35,    36,     0,
       0,     0,     0,    32,   215,    73,    37,    33,     0,     0,
      75,     0,    76,    77,    78,    38,    39,    79,     0,     0,
      34,     0,    35,    36,     0,     0,     0,     0,     0,    32,
      73,    37,   169,    33,     0,    75,     0,    76,    77,    78,
      38,    39,    79,     0,     0,     0,    34,     0,    35,    36,
       0,     0,    32,     0,     0,   180,    33,    37,    32,     0,
       0,     0,    33,     0,     0,     0,    38,    39,    40,    34,
       0,    35,    36,     0,     0,    34,     0,    35,    36,     0,
      37,     0,     0,     0,     0,     0,    37,     0,     0,    38,
      39,    40,     0,     0,     0,    38,    39,    40,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
     109
};

static const yytype_int16 yycheck[] =
{
       0,    22,    26,     8,     4,     5,     9,    28,     8,    81,
      82,    32,    84,    63,    64,     9,    37,    52,     6,   169,
      70,     9,    57,     6,    27,     0,     9,    24,    49,   179,
     180,     0,    32,     8,    69,     3,     4,     5,   184,    27,
      45,   191,    63,    64,    27,     6,   192,     6,     9,    70,
       9,    45,    73,   125,    45,    55,     3,     4,     5,     6,
     132,    58,   112,    10,     8,     9,    27,    67,    36,    37,
       8,     9,    96,    97,    74,    45,    23,     9,    25,    26,
      80,    45,    82,     3,     4,     5,    31,    34,    45,   110,
     111,   112,     7,    80,    94,    82,    43,    44,    45,    45,
     172,     6,   123,    31,   176,   126,     6,     7,     7,     8,
      10,   161,     3,     4,     5,   136,     7,    37,     3,     4,
       5,     7,   194,    23,   124,    25,    26,    31,   200,     6,
       8,     9,     9,    10,    34,     7,   208,     3,     4,     5,
     161,     7,   214,    43,    44,    45,    23,     8,    25,    26,
     171,    35,     6,   174,     6,    31,     6,    34,    32,    27,
       9,     7,    45,    45,     9,   186,    43,    44,    45,   169,
       3,     4,     5,     6,     9,   196,    45,    10,     9,   179,
     180,    32,     7,     6,    32,   206,     7,    45,    32,     7,
      23,   191,    25,    26,     6,     3,     4,     5,     6,    32,
      33,    34,    10,    32,    37,    38,     9,    40,    41,    42,
      43,    44,    45,    27,    31,    23,    42,    25,    26,    39,
       3,     4,     5,     6,    32,    33,    34,    10,     6,    37,
      38,    31,    40,    41,    42,    43,    44,    45,    45,     9,
      23,    39,    25,    26,    32,     3,     4,     5,     6,    32,
      33,    34,    10,     8,    37,    38,    31,    40,    41,    42,
      43,    44,    45,    32,    31,    23,     7,    25,    26,     9,
      31,     7,    32,     6,    32,    33,    34,    10,    31,    37,
      38,    32,    40,    41,    42,    43,    44,    45,     8,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,     6,    32,
      33,    34,    10,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,     6,    32,    33,    34,    10,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,     6,    32,
      33,    34,    10,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,     6,    32,    33,    34,    10,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,     6,    32,
      33,    34,    10,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,     6,    32,    33,    34,    10,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,     6,
      33,    34,     9,    10,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,     6,    -1,    -1,     9,    10,    34,     6,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    43,    44,    45,    23,
      -1,    25,    26,    -1,    -1,    23,    -1,    25,    26,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    43,
      44,    45,    -1,    -1,    -1,    43,    44,    45,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    36,    37,    47,    48,    49,    50,
      51,    52,    79,    79,    79,     0,    48,    45,    45,    45,
       6,     9,    27,     9,    45,    55,     6,     9,    27,     7,
      53,    79,     6,    10,    23,    25,    26,    34,    43,    44,
      45,    68,    69,    70,    71,    73,    74,    75,    76,    78,
      55,     9,     7,    53,    68,    31,    56,     7,    45,    68,
      79,    68,    72,     6,     8,     9,    68,    31,    56,     7,
       8,     9,    32,    33,    37,    38,    40,    41,    42,    45,
      52,    54,    57,    58,    59,    60,    61,    63,    64,    65,
      66,    67,    68,    79,    31,    56,     8,    55,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    21,    22,
      77,     7,     8,    35,     7,    72,    72,    32,    56,    72,
       9,    68,    79,     6,     6,    31,     6,    54,    79,    32,
      58,    32,    54,    58,    32,    58,    27,     9,    45,    32,
      53,    53,    68,    68,    72,     7,     9,     9,     9,    45,
      68,    79,    58,    68,    45,    32,    32,    58,    32,    68,
       9,    27,     7,     7,    45,    32,     7,    32,     9,     9,
      68,    72,    31,    62,    27,    42,    31,    57,    79,     9,
       9,    68,    32,    58,    39,    68,     6,    58,    45,    57,
      57,     9,    39,    32,    31,    62,     8,    68,    32,    57,
      31,    62,    68,     7,    32,     7,     8,     9,    31,    68,
      32,    58,     7,    32,    31,    32,    58,    32
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
#line 64 "src/scanparse/civic.y"
    {
    parseresult = TBmakeProgram((yyvsp[(1) - (1)].node), NULL);      
  }
    break;

  case 3:
#line 70 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDecls((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 4:
#line 74 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDecls((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 5:
#line 80 "src/scanparse/civic.y"
    { 
    (yyval.node) = (yyvsp[(1) - (1)].node); 
  }
    break;

  case 6:
#line 84 "src/scanparse/civic.y"
    { 
    (yyval.node) = (yyvsp[(1) - (1)].node); 
  }
    break;

  case 7:
#line 88 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 8:
#line 94 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdecl((yyvsp[(2) - (5)].ctype), STRcpy((yyvsp[(3) - (5)].id)), (yyvsp[(4) - (5)].node));
  }
    break;

  case 9:
#line 98 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdecl((yyvsp[(2) - (4)].ctype), STRcpy((yyvsp[(3) - (4)].id)), NULL);
  }
    break;

  case 10:
#line 104 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(2) - (8)].ctype), STRcpy((yyvsp[(3) - (8)].id)), (yyvsp[(7) - (8)].node), (yyvsp[(5) - (8)].node));
  }
    break;

  case 11:
#line 108 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, (yyvsp[(5) - (6)].node));
  }
    break;

  case 12:
#line 112 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(2) - (4)].ctype), STRcpy((yyvsp[(3) - (4)].id)), NULL, NULL);
  }
    break;

  case 13:
#line 116 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (7)].ctype), STRcpy((yyvsp[(2) - (7)].id)), (yyvsp[(6) - (7)].node), (yyvsp[(4) - (7)].node));
  }
    break;

  case 14:
#line 120 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, (yyvsp[(4) - (5)].node));
  }
    break;

  case 15:
#line 124 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), NULL, NULL);
  }
    break;

  case 16:
#line 130 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(2) - (7)].ctype), STRcpy((yyvsp[(3) - (7)].id)), NULL, NULL, NULL);
  }
    break;

  case 17:
#line 134 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, (yyvsp[(6) - (6)].node), NULL);
  }
    break;

  case 18:
#line 138 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(2) - (7)].ctype), STRcpy((yyvsp[(3) - (7)].id)), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node), NULL);
  }
    break;

  case 19:
#line 142 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), NULL, NULL, NULL);
  }
    break;

  case 20:
#line 146 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, (yyvsp[(5) - (5)].node), NULL);
  }
    break;

  case 21:
#line 150 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundef((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node), NULL);
  }
    break;

  case 22:
#line 156 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
  }
    break;

  case 23:
#line 160 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), (yyvsp[(3) - (3)].node), NULL);
  }
    break;

  case 24:
#line 164 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), NULL, (yyvsp[(4) - (4)].node));
  }
    break;

  case 25:
#line 168 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (2)].ctype), STRcpy((yyvsp[(2) - (2)].id)), NULL, NULL);
  }
    break;

  case 26:
#line 174 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundefs((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 27:
#line 178 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundefs((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 28:
#line 184 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIds(STRcpy((yyvsp[(1) - (2)].id)), (yyvsp[(2) - (2)].node));
  }
    break;

  case 29:
#line 188 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIds(STRcpy((yyvsp[(1) - (1)].id)), NULL);
  }
    break;

  case 30:
#line 193 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node));
  }
    break;

  case 31:
#line 197 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));
  }
    break;

  case 32:
#line 201 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (4)].node), NULL, (yyvsp[(3) - (4)].node));
  }
    break;

  case 33:
#line 205 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), NULL);
  }
    break;

  case 34:
#line 209 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (3)].node), NULL, NULL);
  }
    break;

  case 35:
#line 213 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, NULL, (yyvsp[(2) - (3)].node));
  }
    break;

  case 36:
#line 217 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(2) - (3)].node), NULL);
  }
    break;

  case 37:
#line 221 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, NULL, NULL);
  }
    break;

  case 38:
#line 227 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (7)].ctype), STRcpy((yyvsp[(2) - (7)].id)), (yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  }
    break;

  case 39:
#line 231 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), (yyvsp[(5) - (6)].node), NULL);
  }
    break;

  case 40:
#line 235 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), NULL, (yyvsp[(6) - (6)].node));
  }
    break;

  case 41:
#line 239 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), NULL, (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
  }
    break;

  case 42:
#line 243 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), (yyvsp[(4) - (5)].node), NULL, NULL);
  }
    break;

  case 43:
#line 247 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, (yyvsp[(4) - (5)].node), NULL);
  }
    break;

  case 44:
#line 251 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, NULL, (yyvsp[(5) - (5)].node));
  }
    break;

  case 45:
#line 255 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), NULL, NULL, NULL);
  }
    break;

  case 46:
#line 260 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeStmts( (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 47:
#line 264 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeStmts( (yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 48:
#line 270 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 49:
#line 274 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 50:
#line 278 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 51:
#line 282 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 52:
#line 286 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 53:
#line 290 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 54:
#line 294 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprstmt((yyvsp[(1) - (2)].node));
  }
    break;

  case 55:
#line 300 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeReturn((yyvsp[(2) - (3)].node));
  }
    break;

  case 56:
#line 304 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeReturn(NULL);
  }
    break;

  case 57:
#line 310 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  }
    break;

  case 58:
#line 314 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL);
  }
    break;

  case 59:
#line 318 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (9)].node), NULL, NULL);
  }
    break;

  case 60:
#line 322 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (8)].node), NULL, (yyvsp[(8) - (8)].node));
  }
    break;

  case 61:
#line 326 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (6)].node), NULL, NULL);
  }
    break;

  case 62:
#line 332 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  }
    break;

  case 63:
#line 338 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeAssign( (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
  }
    break;

  case 64:
#line 344 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (11)].id), (yyvsp[(6) - (11)].node), (yyvsp[(8) - (11)].node), NULL, NULL);
  }
    break;

  case 65:
#line 348 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (13)].id), (yyvsp[(6) - (13)].node), (yyvsp[(8) - (13)].node), (yyvsp[(10) - (13)].node), NULL);
  }
    break;

  case 66:
#line 352 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (12)].id), (yyvsp[(6) - (12)].node), (yyvsp[(8) - (12)].node), NULL, (yyvsp[(11) - (12)].node));
  }
    break;

  case 67:
#line 356 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (14)].id), (yyvsp[(6) - (14)].node), (yyvsp[(8) - (14)].node), (yyvsp[(10) - (14)].node), (yyvsp[(13) - (14)].node));
  }
    break;

  case 68:
#line 362 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDowhile( (yyvsp[(7) - (9)].node), (yyvsp[(3) - (9)].node));
  }
    break;

  case 69:
#line 367 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeWhile( (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
  }
    break;

  case 70:
#line 377 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVarlet( STRcpy( (yyvsp[(1) - (1)].id)), NULL, NULL);
  }
    break;

  case 71:
#line 384 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 72:
#line 388 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVar( STRcpy( (yyvsp[(1) - (1)].id)), NULL, NULL);
  }
    break;

  case 73:
#line 392 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeMonop((yyvsp[(1) - (2)].cmonop), (yyvsp[(2) - (2)].node));
  }
    break;

  case 74:
#line 396 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeBinop( (yyvsp[(3) - (5)].cbinop), (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));
  }
    break;

  case 75:
#line 400 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 76:
#line 404 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 77:
#line 408 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 78:
#line 414 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeCast((yyvsp[(2) - (4)].ctype), (yyvsp[(4) - (4)].node));
  }
    break;

  case 79:
#line 421 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFuncall((yyvsp[(1) - (4)].id), NULL, (yyvsp[(3) - (4)].node));
  }
    break;

  case 80:
#line 425 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFuncall((yyvsp[(1) - (3)].id), NULL, NULL);
  }
    break;

  case 81:
#line 431 "src/scanparse/civic.y"
    {
    TBmakeArrexpr((yyvsp[(2) - (3)].node));
  }
    break;

  case 82:
#line 437 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprs((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 83:
#line 441 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprs((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  }
    break;

  case 84:
#line 447 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 85:
#line 451 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 86:
#line 455 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 87:
#line 461 "src/scanparse/civic.y"
    {
             (yyval.node) = TBmakeFloat( (yyvsp[(1) - (1)].cflt));
           }
    break;

  case 88:
#line 467 "src/scanparse/civic.y"
    {
          (yyval.node) = TBmakeNum( (yyvsp[(1) - (1)].cint));
        }
    break;

  case 89:
#line 473 "src/scanparse/civic.y"
    {
           (yyval.node) = TBmakeBool( TRUE);
         }
    break;

  case 90:
#line 477 "src/scanparse/civic.y"
    {
           (yyval.node) = TBmakeBool( FALSE);
         }
    break;

  case 91:
#line 482 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_add; }
    break;

  case 92:
#line 483 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_sub; }
    break;

  case 93:
#line 484 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_mul; }
    break;

  case 94:
#line 485 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_div; }
    break;

  case 95:
#line 486 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_mod; }
    break;

  case 96:
#line 487 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_le; }
    break;

  case 97:
#line 488 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_lt; }
    break;

  case 98:
#line 489 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_ge; }
    break;

  case 99:
#line 490 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_gt; }
    break;

  case 100:
#line 491 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_eq; }
    break;

  case 101:
#line 492 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_or; }
    break;

  case 102:
#line 493 "src/scanparse/civic.y"
    { (yyval.cbinop) = BO_and; }
    break;

  case 103:
#line 496 "src/scanparse/civic.y"
    { (yyval.cmonop) = MO_not; }
    break;

  case 104:
#line 497 "src/scanparse/civic.y"
    { (yyval.cmonop) = MO_neg; }
    break;

  case 105:
#line 500 "src/scanparse/civic.y"
    { (yyval.ctype) = T_int;}
    break;

  case 106:
#line 501 "src/scanparse/civic.y"
    { (yyval.ctype) = T_float;}
    break;

  case 107:
#line 502 "src/scanparse/civic.y"
    { (yyval.ctype) = T_bool;}
    break;


/* Line 1267 of yacc.c.  */
#line 2400 "y.tab.c"
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


#line 505 "src/scanparse/civic.y"


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


