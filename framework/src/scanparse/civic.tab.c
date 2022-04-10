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
     VOID_TYPE = 261,
     BRACKET_L = 262,
     BRACKET_R = 263,
     COMMA = 264,
     SEMICOLON = 265,
     MINUS = 266,
     PLUS = 267,
     STAR = 268,
     SLASH = 269,
     PERCENT = 270,
     LE = 271,
     LT = 272,
     GE = 273,
     GT = 274,
     EQ = 275,
     NE = 276,
     OR = 277,
     AND = 278,
     NOT = 279,
     NEG = 280,
     TRUEVAL = 281,
     FALSEVAL = 282,
     LET = 283,
     INTTYPE = 284,
     FLOATTYPE = 285,
     BOOLTYPE = 286,
     CURLY_BRACKET_L = 287,
     CURLY_BRACKET_R = 288,
     RETURN = 289,
     SQUARE_BRACKET_L = 290,
     SQUARE_BRACKET_R = 291,
     EXTERN = 292,
     EXPORT = 293,
     IF = 294,
     ELSE = 295,
     FOR = 296,
     DO = 297,
     WHILE = 298,
     CAST = 299,
     NUM = 300,
     FLOAT = 301,
     ID = 302
   };
#endif
/* Tokens.  */
#define INT_TYPE 258
#define FLOAT_TYPE 259
#define BOOL_TYPE 260
#define VOID_TYPE 261
#define BRACKET_L 262
#define BRACKET_R 263
#define COMMA 264
#define SEMICOLON 265
#define MINUS 266
#define PLUS 267
#define STAR 268
#define SLASH 269
#define PERCENT 270
#define LE 271
#define LT 272
#define GE 273
#define GT 274
#define EQ 275
#define NE 276
#define OR 277
#define AND 278
#define NOT 279
#define NEG 280
#define TRUEVAL 281
#define FALSEVAL 282
#define LET 283
#define INTTYPE 284
#define FLOATTYPE 285
#define BOOLTYPE 286
#define CURLY_BRACKET_L 287
#define CURLY_BRACKET_R 288
#define RETURN 289
#define SQUARE_BRACKET_L 290
#define SQUARE_BRACKET_R 291
#define EXTERN 292
#define EXPORT 293
#define IF 294
#define ELSE 295
#define FOR 296
#define DO 297
#define WHILE 298
#define CAST 299
#define NUM 300
#define FLOAT 301
#define ID 302




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
#include "stdint.h" 
#include "limits.h"

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
#line 26 "src/scanparse/civic.y"
{
 nodetype            nodetype;
 char               *id;
 int                 cint;
 float               cflt;
 node               *node;
 type                ctype;
}
/* Line 193 of yacc.c.  */
#line 224 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 237 "y.tab.c"

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  240

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    23,
      28,    37,    44,    49,    57,    63,    67,    74,    82,    88,
      95,   102,   110,   115,   119,   124,   127,   130,   132,   135,
     137,   143,   149,   154,   159,   164,   169,   173,   177,   181,
     184,   191,   197,   202,   206,   209,   211,   213,   215,   217,
     219,   221,   223,   226,   230,   233,   241,   247,   257,   266,
     273,   280,   284,   286,   291,   303,   317,   330,   345,   358,
     369,   377,   385,   387,   391,   395,   399,   403,   407,   411,
     415,   419,   423,   427,   431,   435,   439,   443,   446,   449,
     451,   453,   455,   457,   459,   464,   466,   471,   475,   479,
     481,   485,   487,   489,   491,   493,   495,   497,   499,   501,
     503,   505
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    51,    -1,    51,    50,    -1,
      54,    -1,    53,    -1,    52,    -1,    37,    80,    47,     9,
      57,    10,    -1,    37,    80,    47,    10,    -1,    38,    80,
      47,    28,    70,     9,    75,    10,    -1,    38,    80,    47,
      28,    70,    10,    -1,    38,    80,    47,    10,    -1,    80,
      47,    28,    70,     9,    75,    10,    -1,    80,    47,    28,
      70,    10,    -1,    80,    47,    10,    -1,    38,    80,    47,
       7,     8,    58,    -1,    38,    80,    47,     7,    55,     8,
      58,    -1,    80,    47,     7,     8,    58,    -1,    80,    47,
       7,    55,     8,    58,    -1,    37,    80,    47,     7,     8,
      10,    -1,    37,    80,    47,     7,    55,     8,    10,    -1,
      80,    47,    57,    55,    -1,    80,    47,    57,    -1,    80,
      47,     9,    55,    -1,    80,    47,    -1,    54,    56,    -1,
      54,    -1,    47,    57,    -1,    47,    -1,    32,    59,    56,
      60,    33,    -1,    32,    59,    60,    56,    33,    -1,    32,
      56,    60,    33,    -1,    32,    59,    60,    33,    -1,    32,
      59,    56,    33,    -1,    32,    60,    56,    33,    -1,    32,
      59,    33,    -1,    32,    60,    33,    -1,    32,    56,    33,
      -1,    32,    33,    -1,    59,    80,    47,    28,    70,    10,
      -1,    80,    47,    28,    70,    10,    -1,    59,    80,    47,
      10,    -1,    80,    47,    10,    -1,    61,    60,    -1,    61,
      -1,    65,    -1,    62,    -1,    63,    -1,    66,    -1,    67,
      -1,    68,    -1,    70,    10,    -1,    34,    70,    10,    -1,
      34,    10,    -1,    39,     7,    70,     8,    64,    40,    64,
      -1,    39,     7,    70,     8,    64,    -1,    39,     7,    70,
       8,    32,    33,    40,    32,    33,    -1,    39,     7,    70,
       8,    32,    33,    40,    64,    -1,    39,     7,    70,     8,
      32,    33,    -1,    39,     7,    70,     8,    40,    64,    -1,
      32,    60,    33,    -1,    61,    -1,    69,    28,    70,    10,
      -1,    41,     7,    80,    47,    28,    70,     9,    70,     8,
      32,    33,    -1,    41,     7,    80,    47,    28,    70,     9,
      70,     9,    70,     8,    32,    33,    -1,    41,     7,    80,
      47,    28,    70,     9,    70,     8,    32,    60,    33,    -1,
      41,     7,    80,    47,    28,    70,     9,    70,     9,    70,
       8,    32,    60,    33,    -1,    41,     7,    80,    47,    28,
      70,     9,    70,     9,    70,     8,    60,    -1,    41,     7,
      80,    47,    28,    70,     9,    70,     8,    60,    -1,    42,
      64,    43,     7,    70,     8,    10,    -1,    43,     7,    70,
       8,    32,    60,    33,    -1,    47,    -1,     7,    70,     8,
      -1,    70,    12,    70,    -1,    70,    11,    70,    -1,    70,
      13,    70,    -1,    70,    14,    70,    -1,    70,    15,    70,
      -1,    70,    16,    70,    -1,    70,    17,    70,    -1,    70,
      18,    70,    -1,    70,    19,    70,    -1,    70,    20,    70,
      -1,    70,    22,    70,    -1,    70,    23,    70,    -1,    70,
      21,    70,    -1,    11,    70,    -1,    24,    70,    -1,    76,
      -1,    72,    -1,    71,    -1,    73,    -1,    74,    -1,     7,
      80,     8,    70,    -1,    47,    -1,    47,     7,    75,     8,
      -1,    47,     7,     8,    -1,    35,    75,    36,    -1,    70,
      -1,    70,     9,    75,    -1,    77,    -1,    78,    -1,    79,
      -1,    46,    -1,    45,    -1,    26,    -1,    27,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    78,    82,    88,    92,    96,   102,   106,
     112,   118,   124,   130,   134,   138,   145,   152,   159,   166,
     173,   180,   189,   193,   197,   201,   207,   211,   217,   221,
     226,   230,   234,   238,   242,   246,   250,   254,   258,   262,
     268,   272,   276,   280,   285,   289,   295,   299,   303,   307,
     311,   315,   319,   325,   329,   335,   339,   343,   347,   351,
     355,   361,   365,   371,   377,   381,   385,   389,   393,   397,
     403,   409,   419,   426,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     449,   453,   457,   461,   467,   473,   480,   484,   490,   496,
     500,   506,   510,   514,   520,   526,   540,   544,   551,   552,
     553,   554
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TYPE", "FLOAT_TYPE", "BOOL_TYPE",
  "VOID_TYPE", "BRACKET_L", "BRACKET_R", "COMMA", "SEMICOLON", "MINUS",
  "PLUS", "STAR", "SLASH", "PERCENT", "LE", "LT", "GE", "GT", "EQ", "NE",
  "OR", "AND", "NOT", "NEG", "TRUEVAL", "FALSEVAL", "LET", "INTTYPE",
  "FLOATTYPE", "BOOLTYPE", "CURLY_BRACKET_L", "CURLY_BRACKET_R", "RETURN",
  "SQUARE_BRACKET_L", "SQUARE_BRACKET_R", "EXTERN", "EXPORT", "IF", "ELSE",
  "FOR", "DO", "WHILE", "\"cast\"", "NUM", "FLOAT", "ID", "$accept",
  "program", "decls", "decl", "globdecl", "globdef", "fundef", "param",
  "fundefs", "ids", "funbody", "vardecl", "stmts", "stmt", "return",
  "ifelse", "block", "assign", "for", "dowhile", "while", "varlet", "expr",
  "cast", "var", "funcall", "arrexpr", "exprs", "constant", "floatval",
  "intval", "boolval", "type", 0
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    66,    66,    66,    66,    66,    66,
      67,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    72,    73,    73,    74,    75,
      75,    76,    76,    76,    77,    78,    79,    79,    80,    80,
      80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     6,     4,
       8,     6,     4,     7,     5,     3,     6,     7,     5,     6,
       6,     7,     4,     3,     4,     2,     2,     1,     2,     1,
       5,     5,     4,     4,     4,     4,     3,     3,     3,     2,
       6,     5,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     2,     7,     5,     9,     8,     6,
       6,     3,     1,     4,    11,    13,    12,    14,    12,    10,
       7,     7,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     4,     1,     4,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   108,   109,   110,   111,     0,     0,     0,     2,     3,
       7,     6,     5,     0,     0,     0,     1,     4,     0,     0,
       0,     0,    15,     0,     0,     0,     9,     0,    12,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,   105,
     104,    95,     0,    91,    90,    92,    93,    89,   101,   102,
     103,     0,     0,    29,     0,     0,     0,     0,     0,    18,
       0,    25,     0,     0,    87,    88,    99,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,    28,     8,    16,     0,
       0,    11,    39,     0,     0,     0,     0,     0,     0,     0,
      95,    27,     0,     0,     0,    45,    47,    48,    46,    49,
      50,    51,     0,     0,     0,    19,     0,    23,    73,     0,
       0,    98,    97,     0,     0,    75,    74,    76,    77,    78,
      79,    80,    81,    82,    83,    86,    84,    85,    21,    17,
       0,    54,     0,     0,     0,     0,     0,     0,    62,     0,
       0,    26,     0,    38,     0,    36,     0,     0,     0,    37,
       0,    44,     0,    52,     0,    24,    22,    94,   100,    96,
      13,    10,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    34,     0,    33,     0,     0,    35,     0,    43,
       0,     0,     0,    61,     0,     0,    30,    31,    42,     0,
      63,     0,     0,     0,    56,     0,     0,     0,     0,    41,
      59,    60,     0,     0,     0,     0,    40,     0,    55,     0,
      70,    71,     0,    58,     0,    57,     0,     0,     0,    69,
       0,    64,     0,     0,    66,     0,    68,    65,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,   101,    31,   102,    54,
      59,   103,   177,   105,   106,   107,   149,   108,   109,   110,
     111,   112,   113,    43,    44,    45,    46,    67,    47,    48,
      49,    50,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
      28,  -123,  -123,  -123,  -123,   147,   147,     4,  -123,    28,
    -123,  -123,  -123,   -39,   -33,   -10,  -123,  -123,    13,    33,
      66,    96,  -123,   600,   155,    -9,  -123,   204,  -123,   600,
      12,    55,    21,   265,   600,   600,  -123,  -123,   600,  -123,
    -123,    64,   735,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,    62,    70,    -9,    81,    12,    76,   750,   195,  -123,
      12,    -8,   656,    84,    15,  -123,   765,    57,   569,   600,
    -123,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,  -123,    98,  -123,  -123,  -123,    12,
     600,  -123,  -123,   595,   147,   147,   104,   105,   290,   111,
      -4,   211,   316,   240,    83,   544,  -123,  -123,  -123,  -123,
    -123,  -123,    95,   794,    78,  -123,   147,   147,  -123,   600,
     600,  -123,  -123,   122,   121,    15,    15,  -123,  -123,  -123,
     212,   212,   212,   212,   887,   887,   242,   876,  -123,  -123,
     123,  -123,   808,    91,    93,   600,   147,   544,  -123,   103,
     600,  -123,   115,  -123,   131,  -123,   341,   151,   118,  -123,
     137,  -123,   600,  -123,    75,  -123,  -123,   863,  -123,  -123,
    -123,  -123,  -123,   165,   166,   672,   127,   146,   173,   688,
     174,  -123,  -123,   150,  -123,   153,   107,  -123,   822,  -123,
     600,   102,   162,  -123,   600,   159,  -123,  -123,  -123,   600,
    -123,   836,   366,   290,   157,   600,   704,   544,   850,  -123,
     163,  -123,   290,   780,   183,   172,  -123,   391,  -123,   600,
    -123,  -123,   417,  -123,   640,  -123,   442,   600,   468,  -123,
     720,  -123,   178,   493,  -123,   519,  -123,  -123,   180,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,   186,  -123,  -123,  -123,     9,   -11,   -82,   -26,
     -53,  -123,   -41,   -93,  -123,  -123,  -122,  -123,  -123,  -123,
    -123,  -123,   -23,  -123,  -123,  -123,  -123,   -43,  -123,  -123,
    -123,  -123,    74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      42,   116,    88,    68,    16,   148,    57,   115,    18,    12,
      62,    64,    65,    52,    19,    66,    56,   104,    12,   151,
      21,   156,   160,    22,   -72,   123,   124,    86,    73,    74,
      75,     1,     2,     3,     4,   117,   139,    20,    53,    53,
      24,    23,    25,    26,    58,    66,    66,   140,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   154,   157,    60,   161,     5,     6,    66,    61,   204,
     142,    68,    84,    27,    13,   185,    28,   168,    85,    14,
      15,   211,    21,    13,    89,   189,     1,     2,     3,     4,
     218,    87,   119,   121,    29,   223,   167,    66,   148,     1,
       2,     3,     4,   190,    30,   165,   166,    63,   138,    33,
     148,   145,   146,    34,    21,   183,   159,   198,   150,   148,
      94,    95,   175,   162,   148,   164,    35,   179,    36,    37,
     169,   170,   114,   171,   202,   199,    93,    38,   173,   188,
     174,    96,   203,    97,    98,    99,   178,    39,    40,   100,
       1,     2,     3,     4,     1,     2,     3,     4,     1,     2,
       3,     4,   180,    51,   181,   186,   215,   201,   143,   144,
     187,   206,    24,    27,   192,   152,   208,   158,   152,   193,
     194,    21,   213,   196,   184,   229,   197,   232,    94,    95,
     205,   207,   236,   220,   238,    17,   224,   212,     1,     2,
       3,     4,    33,   217,   230,   221,    34,     1,     2,     3,
       4,   234,    55,   239,     1,     2,     3,     4,     0,    35,
     176,    36,    37,    71,    72,    73,    74,    75,    92,    93,
      38,   152,    94,    95,    96,     0,    97,    98,    99,     0,
      39,    40,   100,     1,     2,     3,     4,    33,    94,    95,
       0,    34,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    35,    83,    36,    37,     1,     2,
       3,     4,    33,   155,    93,    38,    34,    94,    95,    96,
       0,    97,    98,    99,     0,    39,    40,   100,     0,    35,
       0,    36,    37,     0,     0,     0,     0,    33,     0,     0,
      38,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41,     0,    35,     0,    36,    37,     0,     0,
       0,     0,   147,    33,    93,    38,     0,    34,     0,    96,
       0,    97,    98,    99,     0,    39,    40,   100,     0,     0,
      35,     0,    36,    37,     0,     0,     0,     0,    33,   153,
      93,    38,    34,     0,     0,    96,     0,    97,    98,    99,
       0,    39,    40,   100,     0,    35,     0,    36,    37,     0,
       0,     0,     0,    33,   182,    93,    38,    34,     0,     0,
      96,     0,    97,    98,    99,     0,    39,    40,   100,     0,
      35,     0,    36,    37,     0,     0,     0,     0,    33,   210,
      93,    38,    34,     0,     0,    96,     0,    97,    98,    99,
       0,    39,    40,   100,     0,    35,     0,    36,    37,     0,
       0,     0,     0,   222,    33,    93,    38,     0,    34,     0,
      96,     0,    97,    98,    99,     0,    39,    40,   100,     0,
       0,    35,     0,    36,    37,     0,     0,     0,     0,    33,
     225,    93,    38,    34,     0,     0,    96,     0,    97,    98,
      99,     0,    39,    40,   100,     0,    35,     0,    36,    37,
       0,     0,     0,     0,   228,    33,    93,    38,     0,    34,
       0,    96,     0,    97,    98,    99,     0,    39,    40,   100,
       0,     0,    35,     0,    36,    37,     0,     0,     0,     0,
      33,   231,    93,    38,    34,     0,     0,    96,     0,    97,
      98,    99,     0,    39,    40,   100,     0,    35,     0,    36,
      37,     0,     0,     0,     0,   235,    33,    93,    38,     0,
      34,     0,    96,     0,    97,    98,    99,     0,    39,    40,
     100,     0,     0,    35,     0,    36,    37,     0,     0,     0,
       0,    33,   237,    93,    38,    34,     0,     0,    96,     0,
      97,    98,    99,     0,    39,    40,   100,     0,    35,     0,
      36,    37,     0,     0,     0,     0,    33,   122,    93,    38,
      34,     0,     0,    96,     0,    97,    98,    99,     0,    39,
      40,   100,     0,    35,     0,    36,    37,     0,     0,     0,
       0,     0,    33,     0,    38,   141,    34,    33,     0,     0,
       0,    34,     0,     0,    39,    40,    41,     0,     0,    35,
       0,    36,    37,     0,    35,     0,    36,    37,     0,     0,
      38,     0,     0,     0,     0,    38,     0,     0,     0,     0,
      39,    40,    41,     0,     0,    39,    40,    41,   226,   227,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   118,     0,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     191,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   195,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   214,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   233,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    90,
      91,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   120,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,   219,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   163,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   172,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   200,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   209,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     216,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    71,    72,
      73,    74,    75,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
      23,     9,    55,     7,     0,    98,    29,    60,    47,     0,
      33,    34,    35,    24,    47,    38,    27,    58,     9,   101,
       7,   103,   104,    10,    28,    68,    69,    53,    13,    14,
      15,     3,     4,     5,     6,    61,    89,    47,    47,    47,
       7,    28,     9,    10,    32,    68,    69,    90,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   102,   103,     8,   105,    37,    38,    90,    47,   191,
      93,     7,    10,     7,     0,   157,    10,   120,     8,     5,
       6,   203,     7,     9,     8,    10,     3,     4,     5,     6,
     212,    10,     8,    36,    28,   217,   119,   120,   191,     3,
       4,     5,     6,    28,     8,   116,   117,    33,    10,     7,
     203,     7,     7,    11,     7,   156,    33,    10,     7,   212,
      37,    38,   145,    28,   217,    47,    24,   150,    26,    27,
       8,    10,    58,    10,    32,    28,    34,    35,    47,   162,
      47,    39,    40,    41,    42,    43,    43,    45,    46,    47,
       3,     4,     5,     6,     3,     4,     5,     6,     3,     4,
       5,     6,    47,     8,    33,    47,   207,   190,    94,    95,
      33,   194,     7,     7,    47,   101,   199,   103,   104,    33,
       7,     7,   205,    33,    33,   226,    33,   228,    37,    38,
      28,    32,   233,    10,   235,     9,   219,    40,     3,     4,
       5,     6,     7,    40,   227,    33,    11,     3,     4,     5,
       6,    33,     8,    33,     3,     4,     5,     6,    -1,    24,
     146,    26,    27,    11,    12,    13,    14,    15,    33,    34,
      35,   157,    37,    38,    39,    -1,    41,    42,    43,    -1,
      45,    46,    47,     3,     4,     5,     6,     7,    37,    38,
      -1,    11,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    24,    23,    26,    27,     3,     4,
       5,     6,     7,    33,    34,    35,    11,    37,    38,    39,
      -1,    41,    42,    43,    -1,    45,    46,    47,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      35,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    32,     7,    34,    35,    -1,    11,    -1,    39,
      -1,    41,    42,    43,    -1,    45,    46,    47,    -1,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,     7,    33,
      34,    35,    11,    -1,    -1,    39,    -1,    41,    42,    43,
      -1,    45,    46,    47,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,     7,    33,    34,    35,    11,    -1,    -1,
      39,    -1,    41,    42,    43,    -1,    45,    46,    47,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,     7,    33,
      34,    35,    11,    -1,    -1,    39,    -1,    41,    42,    43,
      -1,    45,    46,    47,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    32,     7,    34,    35,    -1,    11,    -1,
      39,    -1,    41,    42,    43,    -1,    45,    46,    47,    -1,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,     7,
      33,    34,    35,    11,    -1,    -1,    39,    -1,    41,    42,
      43,    -1,    45,    46,    47,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    32,     7,    34,    35,    -1,    11,
      -1,    39,    -1,    41,    42,    43,    -1,    45,    46,    47,
      -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
       7,    33,    34,    35,    11,    -1,    -1,    39,    -1,    41,
      42,    43,    -1,    45,    46,    47,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    32,     7,    34,    35,    -1,
      11,    -1,    39,    -1,    41,    42,    43,    -1,    45,    46,
      47,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,     7,    33,    34,    35,    11,    -1,    -1,    39,    -1,
      41,    42,    43,    -1,    45,    46,    47,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,     7,     8,    34,    35,
      11,    -1,    -1,    39,    -1,    41,    42,    43,    -1,    45,
      46,    47,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    35,    10,    11,     7,    -1,    -1,
      -1,    11,    -1,    -1,    45,    46,    47,    -1,    -1,    24,
      -1,    26,    27,    -1,    24,    -1,    26,    27,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    45,    46,    47,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     8,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     9,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    37,    38,    49,    50,    51,
      52,    53,    54,    80,    80,    80,     0,    50,    47,    47,
      47,     7,    10,    28,     7,     9,    10,     7,    10,    28,
       8,    55,    80,     7,    11,    24,    26,    27,    35,    45,
      46,    47,    70,    71,    72,    73,    74,    76,    77,    78,
      79,     8,    55,    47,    57,     8,    55,    70,    32,    58,
       8,    47,    70,    80,    70,    70,    70,    75,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    10,     8,    57,    10,    58,     8,
       9,    10,    33,    34,    37,    38,    39,    41,    42,    43,
      47,    54,    56,    59,    60,    61,    62,    63,    65,    66,
      67,    68,    69,    70,    80,    58,     9,    57,     8,     8,
       9,    36,     8,    75,    75,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    10,    58,
      75,    10,    70,    80,    80,     7,     7,    32,    61,    64,
       7,    56,    80,    33,    60,    33,    56,    60,    80,    33,
      56,    60,    28,    10,    47,    55,    55,    70,    75,     8,
      10,    10,    10,    47,    47,    70,    80,    60,    43,    70,
      47,    33,    33,    60,    33,    56,    47,    33,    70,    10,
      28,     8,    47,    33,     7,     8,    33,    33,    10,    28,
      10,    70,    32,    40,    64,    28,    70,    32,    70,    10,
      33,    64,    40,    70,     8,    60,    10,    40,    64,     9,
      10,    33,    32,    64,    70,    33,     8,     9,    32,    60,
      70,    33,    60,     8,    33,    32,    60,    33,    60,    33
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
#line 73 "src/scanparse/civic.y"
    {
    parseresult = TBmakeProgram((yyvsp[(1) - (1)].node), NULL, NULL, NULL, NULL);      
  }
    break;

  case 3:
#line 79 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDecls((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 4:
#line 83 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDecls((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 5:
#line 89 "src/scanparse/civic.y"
    { 
    (yyval.node) = (yyvsp[(1) - (1)].node); 
  }
    break;

  case 6:
#line 93 "src/scanparse/civic.y"
    { 
    (yyval.node) = (yyvsp[(1) - (1)].node); 
  }
    break;

  case 7:
#line 97 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 8:
#line 103 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdecl((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, (yyvsp[(5) - (6)].node));
  }
    break;

  case 9:
#line 107 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdecl((yyvsp[(2) - (4)].ctype), STRcpy((yyvsp[(3) - (4)].id)), NULL, NULL);
  }
    break;

  case 10:
#line 113 "src/scanparse/civic.y"
    {
    node* globNode= TBmakeGlobdef((yyvsp[(2) - (8)].ctype), STRcpy((yyvsp[(3) - (8)].id)), NULL, (yyvsp[(7) - (8)].node), (yyvsp[(5) - (8)].node));
    GLOBDEF_ISEXPORT(globNode) = TRUE;
    (yyval.node) = globNode;
  }
    break;

  case 11:
#line 119 "src/scanparse/civic.y"
    {
    node* globNode = TBmakeGlobdef((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, NULL, (yyvsp[(5) - (6)].node));
    GLOBDEF_ISEXPORT(globNode) = TRUE;
    (yyval.node) = globNode;
  }
    break;

  case 12:
#line 125 "src/scanparse/civic.y"
    {
    node* globNode = TBmakeGlobdef((yyvsp[(2) - (4)].ctype), STRcpy((yyvsp[(3) - (4)].id)), NULL, NULL, NULL);
    GLOBDEF_ISEXPORT(globNode) = TRUE;
    (yyval.node) = globNode;
  }
    break;

  case 13:
#line 131 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (7)].ctype), STRcpy((yyvsp[(2) - (7)].id)), NULL, (yyvsp[(6) - (7)].node), (yyvsp[(4) - (7)].node));
  }
    break;

  case 14:
#line 135 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, NULL, (yyvsp[(4) - (5)].node));
  }
    break;

  case 15:
#line 139 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeGlobdef((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), NULL, NULL, NULL);
  }
    break;

  case 16:
#line 146 "src/scanparse/civic.y"
    {
    node* funNode = TBmakeFundef((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, (yyvsp[(6) - (6)].node), NULL);
    FUNDEF_ISEXPORT(funNode) = 1;
    FUNDEF_ISEXTERN(funNode) = 0;    
    (yyval.node) = funNode;
  }
    break;

  case 17:
#line 153 "src/scanparse/civic.y"
    {
    node* funNode = TBmakeFundef((yyvsp[(2) - (7)].ctype), STRcpy((yyvsp[(3) - (7)].id)), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node), NULL);
    FUNDEF_ISEXPORT(funNode) = 1;
    FUNDEF_ISEXTERN(funNode) = 0;    
    (yyval.node) = funNode;
  }
    break;

  case 18:
#line 160 "src/scanparse/civic.y"
    {
    node* funNode = TBmakeFundef((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, (yyvsp[(5) - (5)].node), NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 0;    
    (yyval.node) = funNode;
  }
    break;

  case 19:
#line 167 "src/scanparse/civic.y"
    {
    node* funNode = TBmakeFundef((yyvsp[(1) - (6)].ctype), STRcpy((yyvsp[(2) - (6)].id)), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node), NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 0;    
    (yyval.node) = funNode;
  }
    break;

  case 20:
#line 174 "src/scanparse/civic.y"
    {
    node* funNode = TBmakeFundef((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, NULL, NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 1;    
    (yyval.node) = funNode;
  }
    break;

  case 21:
#line 181 "src/scanparse/civic.y"
    {
    node* funNode = TBmakeFundef((yyvsp[(2) - (7)].ctype), STRcpy((yyvsp[(3) - (7)].id)), (yyvsp[(5) - (7)].node), NULL, NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 1;    
    (yyval.node) = funNode;
  }
    break;

  case 22:
#line 190 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
  }
    break;

  case 23:
#line 194 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), (yyvsp[(3) - (3)].node), NULL);
  }
    break;

  case 24:
#line 198 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (4)].ctype), STRcpy((yyvsp[(2) - (4)].id)), NULL, (yyvsp[(4) - (4)].node));
  }
    break;

  case 25:
#line 202 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeParam((yyvsp[(1) - (2)].ctype), STRcpy((yyvsp[(2) - (2)].id)), NULL, NULL);
  }
    break;

  case 26:
#line 208 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundefs((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 27:
#line 212 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFundefs((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 28:
#line 218 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIds(STRcpy((yyvsp[(1) - (2)].id)), (yyvsp[(2) - (2)].node));
  }
    break;

  case 29:
#line 222 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIds(STRcpy((yyvsp[(1) - (1)].id)), NULL);
  }
    break;

  case 30:
#line 227 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node));
  }
    break;

  case 31:
#line 231 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), (yyvsp[(3) - (5)].node));
  }
    break;

  case 32:
#line 235 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));
  }
    break;

  case 33:
#line 239 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (4)].node), NULL, (yyvsp[(3) - (4)].node));
  }
    break;

  case 34:
#line 243 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), NULL);
  }
    break;

  case 35:
#line 247 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(3) - (4)].node), (yyvsp[(2) - (4)].node));
  }
    break;

  case 36:
#line 251 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody((yyvsp[(2) - (3)].node), NULL, NULL);
  }
    break;

  case 37:
#line 255 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, NULL, (yyvsp[(2) - (3)].node));
  }
    break;

  case 38:
#line 259 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, (yyvsp[(2) - (3)].node), NULL);
  }
    break;

  case 39:
#line 263 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFunbody(NULL, NULL, NULL);
  }
    break;

  case 40:
#line 269 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(2) - (6)].ctype), STRcpy((yyvsp[(3) - (6)].id)), NULL, NULL, (yyvsp[(5) - (6)].node), (yyvsp[(1) - (6)].node));
  }
    break;

  case 41:
#line 273 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (5)].ctype), STRcpy((yyvsp[(2) - (5)].id)), NULL, NULL, (yyvsp[(4) - (5)].node), NULL);
  }
    break;

  case 42:
#line 277 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(2) - (4)].ctype), STRcpy((yyvsp[(3) - (4)].id)), NULL, NULL, NULL, (yyvsp[(1) - (4)].node));
  }
    break;

  case 43:
#line 281 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVardecl((yyvsp[(1) - (3)].ctype), STRcpy((yyvsp[(2) - (3)].id)), NULL, NULL, NULL, NULL);
  }
    break;

  case 44:
#line 286 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeStmts( (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  }
    break;

  case 45:
#line 290 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeStmts( (yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 46:
#line 296 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 47:
#line 300 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 48:
#line 304 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 49:
#line 308 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 50:
#line 312 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 51:
#line 316 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 52:
#line 320 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprstmt((yyvsp[(1) - (2)].node));
  }
    break;

  case 53:
#line 326 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeReturn((yyvsp[(2) - (3)].node));
  }
    break;

  case 54:
#line 330 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeReturn(NULL);
  }
    break;

  case 55:
#line 336 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  }
    break;

  case 56:
#line 340 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL);
  }
    break;

  case 57:
#line 344 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (9)].node), NULL, NULL);
  }
    break;

  case 58:
#line 348 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (8)].node), NULL, (yyvsp[(8) - (8)].node));
  }
    break;

  case 59:
#line 352 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (6)].node), NULL, NULL);
  }
    break;

  case 60:
#line 356 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeIfelse((yyvsp[(3) - (6)].node), NULL, (yyvsp[(6) - (6)].node));
  }
    break;

  case 61:
#line 362 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  }
    break;

  case 62:
#line 366 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 63:
#line 372 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeAssign( (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
  }
    break;

  case 64:
#line 378 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (11)].id), (yyvsp[(6) - (11)].node), (yyvsp[(8) - (11)].node), NULL, NULL);
  }
    break;

  case 65:
#line 382 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (13)].id), (yyvsp[(6) - (13)].node), (yyvsp[(8) - (13)].node), (yyvsp[(10) - (13)].node), NULL);
  }
    break;

  case 66:
#line 386 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (12)].id), (yyvsp[(6) - (12)].node), (yyvsp[(8) - (12)].node), NULL, (yyvsp[(11) - (12)].node));
  }
    break;

  case 67:
#line 390 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (14)].id), (yyvsp[(6) - (14)].node), (yyvsp[(8) - (14)].node), (yyvsp[(10) - (14)].node), (yyvsp[(13) - (14)].node));
  }
    break;

  case 68:
#line 394 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (12)].id), (yyvsp[(6) - (12)].node), (yyvsp[(8) - (12)].node), (yyvsp[(10) - (12)].node), (yyvsp[(12) - (12)].node));
  }
    break;

  case 69:
#line 398 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFor( (yyvsp[(4) - (10)].id), (yyvsp[(6) - (10)].node), (yyvsp[(8) - (10)].node), NULL, (yyvsp[(10) - (10)].node));
  }
    break;

  case 70:
#line 404 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeDowhile( (yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node));
  }
    break;

  case 71:
#line 410 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeWhile( (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
  }
    break;

  case 72:
#line 420 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVarlet( STRcpy( (yyvsp[(1) - (1)].id)), NULL, NULL);
  }
    break;

  case 73:
#line 427 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  }
    break;

  case 74:
#line 430 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_add, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 75:
#line 431 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_sub, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 76:
#line 432 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_mul, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 77:
#line 433 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_div, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 78:
#line 434 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_mod, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 79:
#line 435 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_le, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 80:
#line 436 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_lt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 81:
#line 437 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_ge, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 82:
#line 438 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_gt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 83:
#line 439 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_eq, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 84:
#line 440 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_or, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 85:
#line 441 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_and, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 86:
#line 442 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeBinop(BO_ne, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 87:
#line 443 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeMonop( MO_neg, (yyvsp[(2) - (2)].node)); }
    break;

  case 88:
#line 444 "src/scanparse/civic.y"
    { (yyval.node) = TBmakeMonop(MO_not, (yyvsp[(2) - (2)].node)); }
    break;

  case 89:
#line 446 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 90:
#line 450 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 91:
#line 454 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 92:
#line 458 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 93:
#line 462 "src/scanparse/civic.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  }
    break;

  case 94:
#line 468 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeCast((yyvsp[(2) - (4)].ctype), (yyvsp[(4) - (4)].node));
  }
    break;

  case 95:
#line 474 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeVar( STRcpy( (yyvsp[(1) - (1)].id)), NULL, NULL);
  }
    break;

  case 96:
#line 481 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFuncall((yyvsp[(1) - (4)].id), NULL, (yyvsp[(3) - (4)].node));
  }
    break;

  case 97:
#line 485 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeFuncall((yyvsp[(1) - (3)].id), NULL, NULL);
  }
    break;

  case 98:
#line 491 "src/scanparse/civic.y"
    {
    TBmakeArrexpr((yyvsp[(2) - (3)].node));
  }
    break;

  case 99:
#line 497 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprs((yyvsp[(1) - (1)].node), NULL);
  }
    break;

  case 100:
#line 501 "src/scanparse/civic.y"
    {
    (yyval.node) = TBmakeExprs((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  }
    break;

  case 101:
#line 507 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 102:
#line 511 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 103:
#line 515 "src/scanparse/civic.y"
    {
            (yyval.node) = (yyvsp[(1) - (1)].node);
          }
    break;

  case 104:
#line 521 "src/scanparse/civic.y"
    {
             (yyval.node) = TBmakeFloat( (yyvsp[(1) - (1)].cflt));
           }
    break;

  case 105:
#line 527 "src/scanparse/civic.y"
    {
          if (NUM > INT32_MIN && NUM < INT32_MAX) {
            printf("%d\n", (yyvsp[(1) - (1)].cint));
            (yyval.node) = TBmakeNum( (yyvsp[(1) - (1)].cint));
          } else {
            (yyval.node) = TBmakeNum(0);
            CTIerror("Integer out of range!");

          }
          
        }
    break;

  case 106:
#line 541 "src/scanparse/civic.y"
    {
           (yyval.node) = TBmakeBool( TRUE);
         }
    break;

  case 107:
#line 545 "src/scanparse/civic.y"
    {
           (yyval.node) = TBmakeBool( FALSE);
         }
    break;

  case 108:
#line 551 "src/scanparse/civic.y"
    { (yyval.ctype) = T_int;}
    break;

  case 109:
#line 552 "src/scanparse/civic.y"
    { (yyval.ctype) = T_float;}
    break;

  case 110:
#line 553 "src/scanparse/civic.y"
    { (yyval.ctype) = T_bool;}
    break;

  case 111:
#line 554 "src/scanparse/civic.y"
    { (yyval.ctype) = T_void;}
    break;


/* Line 1267 of yacc.c.  */
#line 2548 "y.tab.c"
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


#line 557 "src/scanparse/civic.y"


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


