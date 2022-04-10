/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 152 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

