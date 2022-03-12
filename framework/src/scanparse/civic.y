%{


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
%}

%union {
 nodetype            nodetype;
 char               *id;
 int                 cint;
 float               cflt;
 binop               cbinop;
 node               *node;
 type                ctype;
}

%token INT_TYPE FLOAT_TYPE BOOL_TYPE
%token BRACKET_L BRACKET_R COMMA SEMICOLON
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND
%token TRUEVAL FALSEVAL LET INTTYPE FLOATTYPE BOOLTYPE 
%token CURLY_BRACKET_L CURLY_BRACKET_R RETURN

%token IF ELSE FOR

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> intval floatval boolval constant expr exprs
%type <node> stmts stmt assign varlet

%type <node> program decls decl fundefs fundef funbody ifelse return for

%type <cbinop> binop
%type <ctype> type

%start program

%%

program: decls
  {
    parseresult = $1;      
  }
  ;

decls: decl
  {
    $$ = TBmakeDecls($1, NULL);
  }
  | decl decls
  {
    $$ = TBmakeDecls($1, $2);
  }
  ;

decl: fundef { $$ = $1; }

fundef: type ID BRACKET_L BRACKET_R funbody
  {
    $$ = TBmakeFundef($1, $2, NULL, $5);
  }
  ;

fundefs: fundef fundefs
  {
    $$ = TBmakeFundefs($1, $2);
  }
  | fundef
  {
    $$ = TBmakeFundefs($1, NULL);
  }
  ;

funbody: CURLY_BRACKET_L fundefs stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, $2, $3);
  }
  | CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, NULL, $2);
  }
  ;

stmts: stmt stmts
  {
    $$ = TBmakeStmts( $1, $2);
  }
  | stmt
  {
    $$ = TBmakeStmts( $1, NULL);
  }
  ;

stmt: assign
  {
    $$ = $1;
  }
  | return
  {
    $$ = $1;
  }
  | ifelse
  {
    $$ = $1;
  }
  | for
  {
    $$ = $1;
  }
  ;

return: RETURN expr SEMICOLON
  {
    $$ = TBmakeReturn($2);
  }
  | RETURN SEMICOLON
  {
    $$ = TBmakeReturn(NULL);
  }
  ;

ifelse: IF BRACKET_L expr BRACKET_R CURLY_BRACKET_L stmts CURLY_BRACKET_R ELSE CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeIfelse($3, $6, $10);
  }
  | IF BRACKET_L expr BRACKET_R CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeIfelse($3, $6, NULL);
  }
  | IF BRACKET_L expr BRACKET_R CURLY_BRACKET_L CURLY_BRACKET_R ELSE CURLY_BRACKET_L CURLY_BRACKET_R
  {
    $$ = TBmakeIfelse($3, NULL, NULL);
  }
  | IF BRACKET_L expr BRACKET_R CURLY_BRACKET_L CURLY_BRACKET_R
  {
    $$ = TBmakeIfelse($3, NULL, NULL);
  }
  ;

assign: varlet LET expr SEMICOLON
  {
    $$ = TBmakeAssign( $1, $3);
  }
  ;

  for: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_BRACKET_L CURLY_BRACKET_R
  {
    $$ = TBmakeFor( $4, $6, $8, NULL, NULL);
  }
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_BRACKET_L CURLY_BRACKET_R
  {
    $$ = TBmakeFor( $4, $6, $8, $10, NULL);
  }
  | FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFor( $4, $6, $8, NULL, $11);
  }
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFor( $4, $6, $8, $10, $13);
  }
  ;

varlet: ID
  {
    $$ = TBmakeVarlet( STRcpy( $1), NULL, NULL);
  }
  ;


expr: constant
  {
    $$ = $1;
  }
  | ID
  {
    $$ = TBmakeVar( STRcpy( $1), NULL, NULL);
  }
  | BRACKET_L expr binop expr BRACKET_R
  {
    $$ = TBmakeBinop( $3, $2, $4);
  }
  ;

exprs: expr 
  {
    $$ = TBmakeExprs($1, NULL);
  }
  | expr exprs
  {
    $$ = TBmakeExprs($1, $2);
  }
  ;

constant: floatval
          {
            $$ = $1;
          }
        | intval
          {
            $$ = $1;
          }
        | boolval
          {
            $$ = $1;
          }
        ;

floatval: FLOAT
           {
             $$ = TBmakeFloat( $1);
           }
         ;

intval: NUM
        {
          $$ = TBmakeNum( $1);
        }
      ;

boolval: TRUEVAL
         {
           $$ = TBmakeBool( TRUE);
         }
       | FALSEVAL
         {
           $$ = TBmakeBool( FALSE);
         }
       ;

binop: PLUS      { $$ = BO_add; }
     | MINUS     { $$ = BO_sub; }
     | STAR      { $$ = BO_mul; }
     | SLASH     { $$ = BO_div; }
     | PERCENT   { $$ = BO_mod; }
     | LE        { $$ = BO_le; }
     | LT        { $$ = BO_lt; }
     | GE        { $$ = BO_ge; }
     | GT        { $$ = BO_gt; }
     | EQ        { $$ = BO_eq; }
     | OR        { $$ = BO_or; }
     | AND       { $$ = BO_and; }
     ;


type: INT_TYPE { $$ = T_int;}
    | FLOAT_TYPE { $$ = T_float;}
    | BOOL_TYPE { $$ = T_bool;}


%%

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

