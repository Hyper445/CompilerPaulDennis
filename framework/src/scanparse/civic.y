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
 monop               cmonop;
 node               *node;
 type                ctype;
}

%token INT_TYPE FLOAT_TYPE BOOL_TYPE
%token BRACKET_L BRACKET_R COMMA SEMICOLON
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND
%token NOT NEG
%token TRUEVAL FALSEVAL LET INTTYPE FLOATTYPE BOOLTYPE 
%token CURLY_BRACKET_L CURLY_BRACKET_R RETURN

%token IF ELSE FOR DO WHILE  

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> intval floatval boolval constant expr exprs
%type <node> stmts stmt assign varlet

%type <node> program decls decl fundefs globdecl globdef fundef param block ids funbody vardecl ifelse return 
%type <node> for dowhile while exprstmt arrexpr funcall cast

%type <cbinop> binop
%type <ctype> type
%type <cmonop> monop

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

decl: fundef 
  { 
    $$ = $1; 
  }
  | globdef 
  { 
    $$ = $1; 
  }
  | globdecl
  {
    $$ = $1;
  }
  ;

globdecl: type ID ids SEMICOLON
  {
    $$ = TBmakeGlobdecl($1, STRcpy($2), $3);
  }
  | type ID SEMICOLON
  {
    $$ = TBmakeGlobdecl($1, STRcpy($2), NULL);
  }
  ;

globdef: type ID LET expr SEMICOLON 
  {
    $$ = TBmakeGlobdef($1, STRcpy($2), NULL, $4);
  }
  ;

fundef: type ID BRACKET_L param BRACKET_R funbody
  {
    $$ = TBmakeFundef($1, STRcpy($2), $4, $6);
  }
  ;

param: type ID ids param
  {
    $$ = TBmakeParam($1, STRcpy($2), $3, $4);
  }
  | type ID ids
  {
    $$ = TBmakeParam($1, STRcpy($2), $3, NULL);
  }
  | type ID COMMA param
  {
    $$ = TBmakeParam($1, STRcpy($2), NULL, $4);
  }
  | type ID
  {
    $$ = TBmakeParam($1, STRcpy($2), NULL, NULL);
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

ids: ID ids
  {
    $$ = TBmakeIds(STRcpy($1), $2);
  }
  | ID
  {
    $$ = TBmakeIds(STRcpy($1), NULL);
  }

funbody: CURLY_BRACKET_L vardecl fundefs stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody($2, $3, $4);
  }
  | CURLY_BRACKET_L fundefs stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, $2, $3);
  }
  | CURLY_BRACKET_L vardecl stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody($2, NULL, $3);
  }
  | CURLY_BRACKET_L vardecl fundefs CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody($2, $3, NULL);
  }
  | CURLY_BRACKET_L vardecl CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody($2, NULL, NULL);
  }
  | CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, NULL, $2);
  }
  | CURLY_BRACKET_L fundefs CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, $2, NULL);
  }
  | CURLY_BRACKET_L CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, NULL, NULL);
  }
  ;

vardecl: type ID LET exprs expr SEMICOLON vardecl
  {
    $$ = TBmakeVardecl($1, STRcpy($2), $4, $5, $7);
  }
  | type ID LET exprs expr SEMICOLON
  {
    $$ = TBmakeVardecl($1, STRcpy($2), $4, $5, NULL);
  }
  | type ID LET exprs SEMICOLON vardecl
  {
    $$ = TBmakeVardecl($1, STRcpy($2), $4, NULL, $6);
  }
  | type ID LET expr SEMICOLON vardecl
  {
    $$ = TBmakeVardecl($1, STRcpy($2), NULL, $4, $6);
  }
  | type ID LET exprs SEMICOLON
  {
    $$ = TBmakeVardecl($1, STRcpy($2), $4, NULL, NULL);
  }
  | type ID LET expr SEMICOLON
  {
    $$ = TBmakeVardecl($1, STRcpy($2), NULL, $4, NULL);
  }
  | type ID LET SEMICOLON vardecl
  {
    $$ = TBmakeVardecl($1, STRcpy($2), NULL, NULL, $5);
  }
  | type ID SEMICOLON
  {
    $$ = TBmakeVardecl($1, STRcpy($2), NULL, NULL, NULL);
  }

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
  | dowhile
  {
    $$ = $1;
  }
  | while
  {
    $$ = $1;
  }
  | exprstmt
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

ifelse: IF BRACKET_L expr BRACKET_R block ELSE block
  {
    $$ = TBmakeIfelse($3, $5, $7);
  }
  | IF BRACKET_L expr BRACKET_R block
  {
    $$ = TBmakeIfelse($3, $5, NULL);
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

block: CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = $2;
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

  dowhile: DO CURLY_BRACKET_L stmts CURLY_BRACKET_R WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = TBmakeDowhile( $7, $3);
  }

  while: WHILE BRACKET_L expr BRACKET_R CURLY_BRACKET_L stmts CURLY_BRACKET_R
  {
    $$ = TBmakeWhile( $3, $6);
  }

exprstmt: expr
  {
    $$ = TBmakeExprstmt($1);
  }

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
  | monop expr 
  {
    $$ = TBmakeMonop($1, $2);
  }
  | BRACKET_L expr binop expr BRACKET_R
  {
    $$ = TBmakeBinop( $3, $2, $4);
  }
  | cast
  {
    $$ = $1;
  }
  | funcall
  {
    $$ = $1;
  }
  | arrexpr
  {
    $$ = $1;
  }
  ;

cast: BRACKET_L type BRACKET_R expr SEMICOLON
  {
    $$ = TBmakeCast($2, $4);
  }
  ;

funcall: ID BRACKET_L exprs BRACKET_R SEMICOLON
  {
    $$ = TBmakeFuncall($1, NULL, $3);
  }
  | ID BRACKET_L BRACKET_R
  {
    $$ = TBmakeFuncall($1, NULL, NULL);
  }
  ;
  
arrexpr: exprs
  {
    TBmakeArrexpr($1);
  }
  ;

exprs: expr
  {
    $$ = TBmakeExprs($1, NULL);
  }
  | expr COMMA exprs
  {
    $$ = TBmakeExprs($1, $3);
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

monop: NOT { $$ = MO_not; }
     | MINUS { $$ = MO_neg; }
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

