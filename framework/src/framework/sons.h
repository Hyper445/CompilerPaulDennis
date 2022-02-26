
/**
 * @file sons.h
 *
 * Defines the NodesUnion and node structures.
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: sons.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_SONS_H_
#define _SAC_SONS_H_

#include "types.h"


/******************************************************************************
 * For each node a structure of its sons is defined, named
 * SONS_<nodename>
 *****************************************************************************/
struct SONS_N_ARREXPR {
	node           *Exprs;
};
struct SONS_N_ASSIGN {
	node           *Let;
	node           *Expr;
};
struct SONS_N_BINOP {
	node           *Left;
	node           *Right;
};
struct SONS_N_BOOL {
};
struct SONS_N_CAST {
	node           *Expr;
};
struct SONS_N_DECLS {
	node           *Decl;
	node           *Next;
};
struct SONS_N_DOWHILE {
	node           *Cond;
	node           *Block;
};
struct SONS_N_ERROR {
	node           *Next;
};
struct SONS_N_EXPRSTMT {
	node           *Expr;
};
struct SONS_N_EXPRS {
	node           *Expr;
	node           *Next;
};
struct SONS_N_FLOAT {
};
struct SONS_N_FOR {
	node           *Start;
	node           *Stop;
	node           *Step;
	node           *Block;
};
struct SONS_N_FUNBODY {
	node           *Vardecls;
	node           *LocalFundefs;
	node           *Stmts;
};
struct SONS_N_FUNCALL {
	node           *Args;
};
struct SONS_N_FUNDEF {
	node           *FunBody;
	node           *Params;
};
struct SONS_N_FUNDEFS {
	node           *Fundef;
	node           *Next;
};
struct SONS_N_GLOBDECL {
	node           *Dims;
};
struct SONS_N_GLOBDEF {
	node           *Dims;
	node           *Init;
};
struct SONS_N_IDS {
	node           *Next;
};
struct SONS_N_IFELSE {
	node           *Cond;
	node           *Then;
	node           *Else;
};
struct SONS_N_MONOP {
	node           *Operand;
};
struct SONS_N_NUM {
};
struct SONS_N_PARAM {
	node           *Dims;
	node           *Next;
};
struct SONS_N_PROGRAM {
	node           *Decls;
};
struct SONS_N_RETURN {
	node           *Expr;
};
struct SONS_N_STMTS {
	node           *Stmt;
	node           *Next;
};
struct SONS_N_VAR {
	node           *Indices;
};
struct SONS_N_VARDECL {
	node           *Dims;
	node           *Init;
	node           *Next;
};
struct SONS_N_VARLET {
	node           *Indices;
};
struct SONS_N_WHILE {
	node           *Cond;
	node           *Block;
};
/*****************************************************************************
 * This union handles all different types of sons. Its members are
 * called N_nodename.
 ****************************************************************************/
struct SONUNION {
	struct SONS_N_ARREXPR *N_arrexpr;
	struct SONS_N_ASSIGN *N_assign;
	struct SONS_N_BINOP *N_binop;
	struct SONS_N_BOOL *N_bool;
	struct SONS_N_CAST *N_cast;
	struct SONS_N_DECLS *N_decls;
	struct SONS_N_DOWHILE *N_dowhile;
	struct SONS_N_ERROR *N_error;
	struct SONS_N_EXPRSTMT *N_exprstmt;
	struct SONS_N_EXPRS *N_exprs;
	struct SONS_N_FLOAT *N_float;
	struct SONS_N_FOR *N_for;
	struct SONS_N_FUNBODY *N_funbody;
	struct SONS_N_FUNCALL *N_funcall;
	struct SONS_N_FUNDEF *N_fundef;
	struct SONS_N_FUNDEFS *N_fundefs;
	struct SONS_N_GLOBDECL *N_globdecl;
	struct SONS_N_GLOBDEF *N_globdef;
	struct SONS_N_IDS *N_ids;
	struct SONS_N_IFELSE *N_ifelse;
	struct SONS_N_MONOP *N_monop;
	struct SONS_N_NUM *N_num;
	struct SONS_N_PARAM *N_param;
	struct SONS_N_PROGRAM *N_program;
	struct SONS_N_RETURN *N_return;
	struct SONS_N_STMTS *N_stmts;
	struct SONS_N_VAR *N_var;
	struct SONS_N_VARDECL *N_vardecl;
	struct SONS_N_VARLET *N_varlet;
	struct SONS_N_WHILE *N_while;
};
#endif				/* _SAC_SONS_H_ */
