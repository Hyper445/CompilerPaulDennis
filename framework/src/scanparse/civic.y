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

%token INT_TYPE FLOAT_TYPE BOOL_TYPE VOID_TYPE
%token BRACKET_L BRACKET_R COMMA SEMICOLON
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND
%token NOT NEG
%token TRUEVAL FALSEVAL LET INTTYPE FLOATTYPE BOOLTYPE 
%token CURLY_BRACKET_L CURLY_BRACKET_R RETURN SQUARE_BRACKET_L SQUARE_BRACKET_R
%token EXTERN EXPORT

%token IF ELSE FOR DO WHILE  

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> intval floatval boolval constant expr exprs
%type <node> stmts stmt assign varlet

%type <node> program decls decl fundefs globdecl globdef fundef param block ids funbody vardecl ifelse return 
%type <node> for dowhile while arrexpr funcall cast exprstmt

%type <cbinop> binop
%type <ctype> type
%type <cmonop> monop

%left NOT
%left STAR SLASH PERCENT
%left MINUS PLUS
%left GE GT LE LT
%left EQ NE
%left AND
%left OR

%start program

%%

program: decls
  {
    parseresult = TBmakeProgram($1, NULL, NULL);      
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

globdecl: EXTERN type ID COMMA ids SEMICOLON
  {
    $$ = TBmakeGlobdecl($2, STRcpy($3), NULL, $5);
  }
  | EXTERN type ID SEMICOLON
  {
    $$ = TBmakeGlobdecl($2, STRcpy($3), NULL, NULL);
  }
  ;

globdef: EXPORT type ID LET expr COMMA exprs SEMICOLON
  {
    node* globNode= TBmakeGlobdef($2, STRcpy($3), NULL, $7, $5);
    GLOBDEF_ISEXPORT(globNode) = TRUE;
    $$ = globNode;
  } 
  | EXPORT type ID LET expr SEMICOLON
  {
    node* globNode = TBmakeGlobdef($2, STRcpy($3), NULL, NULL, $5);
    GLOBDEF_ISEXPORT(globNode) = TRUE;
    $$ = globNode;
  }
  | EXPORT type ID SEMICOLON
  {
    node* globNode = TBmakeGlobdef($2, STRcpy($3), NULL, NULL, NULL);
    GLOBDEF_ISEXPORT(globNode) = TRUE;
    $$ = globNode;
  }
  | type ID LET expr COMMA exprs SEMICOLON
  {
    $$ = TBmakeGlobdef($1, STRcpy($2), NULL, $6, $4);
  } 
  | type ID LET expr SEMICOLON
  {
    $$ = TBmakeGlobdef($1, STRcpy($2), NULL, NULL, $4);
  }
  | type ID SEMICOLON
  {
    $$ = TBmakeGlobdef($1, STRcpy($2), NULL, NULL, NULL);
  }
  ;


fundef: EXPORT type ID BRACKET_L BRACKET_R funbody
  {
    node* funNode = TBmakeFundef($2, STRcpy($3), NULL, $6, NULL);
    FUNDEF_ISEXPORT(funNode) = 1;
    FUNDEF_ISEXTERN(funNode) = 0;    
    $$ = funNode;
  }
  | EXPORT type ID BRACKET_L param BRACKET_R funbody
  {
    node* funNode = TBmakeFundef($2, STRcpy($3), $5, $7, NULL);
    FUNDEF_ISEXPORT(funNode) = 1;
    FUNDEF_ISEXTERN(funNode) = 0;    
    $$ = funNode;
  }
  | type ID BRACKET_L BRACKET_R funbody
  {
    node* funNode = TBmakeFundef($1, STRcpy($2), NULL, $5, NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 0;    
    $$ = funNode;
  }
  | type ID BRACKET_L param BRACKET_R funbody
  {
    node* funNode = TBmakeFundef($1, STRcpy($2), $4, $6, NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 0;    
    $$ = funNode;
  } 
  | EXTERN type ID BRACKET_L BRACKET_R SEMICOLON
  {
    node* funNode = TBmakeFundef($2, STRcpy($3), NULL, NULL, NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 1;    
    $$ = funNode;
  }
  | EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON
  {
    node* funNode = TBmakeFundef($2, STRcpy($3), $5, NULL, NULL);
    FUNDEF_ISEXPORT(funNode) = 0;
    FUNDEF_ISEXTERN(funNode) = 1;    
    $$ = funNode;
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
  | CURLY_BRACKET_L vardecl stmts fundefs CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody($2, $4, $3);
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
  | CURLY_BRACKET_L stmts fundefs CURLY_BRACKET_R
  {
    $$ = TBmakeFunbody(NULL, $3, $2);
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

vardecl: vardecl type ID LET expr SEMICOLON
  {
    $$ = TBmakeVardecl($2, STRcpy($3), NULL, NULL, $5, $1);
  }
  | type ID LET expr SEMICOLON
  {
    $$ = TBmakeVardecl($1, STRcpy($2), NULL, NULL, $4, NULL);
  }
  | vardecl type ID SEMICOLON 
  {
    $$ = TBmakeVardecl($2, STRcpy($3), NULL, NULL, NULL, $1);
  }
  | type ID SEMICOLON
  {
    $$ = TBmakeVardecl($1, STRcpy($2), NULL, NULL, NULL, NULL);
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
  | expr SEMICOLON
  {
    $$ = TBmakeExprstmt($1);
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
  | IF BRACKET_L expr BRACKET_R CURLY_BRACKET_L CURLY_BRACKET_R ELSE block
  {
    $$ = TBmakeIfelse($3, NULL, $8);
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
  | DO CURLY_BRACKET_L CURLY_BRACKET_R WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = TBmakeDowhile( $6, NULL);
  }
  ;

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


expr: monop expr 
  {
    $$ = TBmakeMonop($1, $2);
  }
  | constant
  {
    $$ = $1;
  }
  | ID
  {
    $$ = TBmakeVar( STRcpy( $1), NULL, NULL);
  }
  | expr binop expr
  {
    $$ = TBmakeBinop( $2, $1, $3);
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

cast: BRACKET_L type BRACKET_R expr
  {
    $$ = TBmakeCast($2, $4);
  }
  ;


funcall: ID BRACKET_L exprs BRACKET_R
  {
    $$ = TBmakeFuncall($1, NULL, $3);
  }
  | ID BRACKET_L BRACKET_R
  {
    $$ = TBmakeFuncall($1, NULL, NULL);
  }
  ;
  
arrexpr: SQUARE_BRACKET_L exprs SQUARE_BRACKET_R
  {
    TBmakeArrexpr($2);
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
     | AND       { $$ = BO_and;}
     | NE        { $$ = BO_ne; }
     ;

monop: NOT { $$ = MO_not; }
     | MINUS { $$ = MO_neg; }
     ;

type: INT_TYPE { $$ = T_int;}
    | FLOAT_TYPE { $$ = T_float;}
    | BOOL_TYPE { $$ = T_bool;}
    | VOID_TYPE { $$ = T_void;}


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

