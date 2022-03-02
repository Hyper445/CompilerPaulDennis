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
%token CURLY_BRACKET_L CURLY_BRACKET_R

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> intval floatval boolval constant expr 
%type <node> stmts stmt assign varlet program

%type <node> exprs decls fundef fundefs param decl funbody vardecl ids

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

fundef: type ID BRACKET_L param BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R
  {
    $$ = TBmakeFundef($1, $2, $7, $4);
  }
  | type ID BRACKET_L BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R
  {
    $$ = TBmakeFundef($1, $2, $6, NULL);
  }
  | type ID BRACKET_L BRACKET_R
  {
    $$ = TBmakeFundef($1, $2, NULL, NULL);
  }
  ;

funbody: vardecl fundefs stmts
  {
    $$ = TBmakeFunbody($1, $2, $3);
  }
  | vardecl fundefs
  { 
    $$ = TBmakeFunbody($1, $2, NULL);
  }
  | vardecl stmts
  {
    $$ = TBmakeFunbody($1, NULL, $2);
  }
  | fundefs stmts
  {
    $$ = TBmakeFunbody(NULL, $1, $2);
  }
  | vardecl
  {
    $$ = TBmakeFunbody($1, NULL, NULL);
  }
  | fundefs
  {
    $$ = TBmakeFunbody(NULL, $1, NULL);
  }
  | stmts
  {
    $$ = TBmakeFunbody(NULL, NULL, $1);
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

vardecl: vardecl type ID exprs expr SEMICOLON
  {
    $$ = TBmakeVardecl($3, $2, $4, $5, $1);
  }
  | type ID exprs expr SEMICOLON
  {
    $$ = TBmakeVardecl($2, $1, $3, $4, NULL);
  }
  | type ID exprs SEMICOLON
  {
    $$ = TBmakeVardecl($2, $1, $3, NULL, NULL);
  }
  | type ID SEMICOLON
  {
    $$ = TBmakeVardecl($2, $1, NULL, NULL, NULL);
  }
  ;

param: ID type ids COMMA param
  {
    $$ = TBmakeParam($1, $2, $3, $5);
  }
  | ID type ids
  {
    $$ = TBmakeParam($1, $2, $3, NULL);
  }
  | ID type
  {
    $$ = TBmakeParam($1, $2, NULL, NULL);
  }
  ;

ids: ID ids
  {
    $$ = TBmakeIds($1, $2);
  }
  | ID
  {
    $$ = TBmakeIds($1, NULL);
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
  ;

assign: varlet LET expr SEMICOLON
  {
    $$ = TBmakeAssign( $1, $3);
  }
  ;


varlet: ID exprs
  {
    $$ = TBmakeVarlet( STRcpy( $1), $2, NULL);
  }
  ;


expr: constant
  {
    $$ = $1;
  }
  | ID exprs
  {
    $$ = TBmakeVar( STRcpy( $1), $2, NULL);
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

decl: fundef { $$ = $1; }

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

