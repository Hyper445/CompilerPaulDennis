
/**
 * @file traverse_helper.c
 *
 * Defines the helper function needed by the traversal system
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: traverse_helper.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */


#include "traverse_helper.h"
#include "dbug.h"
#include "tree_basic.h"
#include "traverse.h"

#define TRAV( son, info)    if (son != NULL) { son = TRAVdo( son, info); }

node           *
TRAVnone(node * arg_node, info * arg_info)
{
	return (arg_node);
}

node           *
TRAVerror(node * arg_node, info * arg_info)
{
	DBUG_ASSERT((FALSE), "Illegal node type found.");

	return (arg_node);
}

node           *
TRAVsons(node * arg_node, info * arg_info)
{
	switch (NODE_TYPE(arg_node)) {
	case N_program:
		TRAV(PROGRAM_DECLS(arg_node), arg_info);
		break;
	case N_decls:
		TRAV(DECLS_DECL(arg_node), arg_info);
		TRAV(DECLS_NEXT(arg_node), arg_info);
		break;
	case N_exprs:
		TRAV(EXPRS_EXPR(arg_node), arg_info);
		TRAV(EXPRS_NEXT(arg_node), arg_info);
		break;
	case N_arrexpr:
		TRAV(ARREXPR_EXPRS(arg_node), arg_info);
		break;
	case N_ids:
		TRAV(IDS_NEXT(arg_node), arg_info);
		break;
	case N_exprstmt:
		TRAV(EXPRSTMT_EXPR(arg_node), arg_info);
		break;
	case N_return:
		TRAV(RETURN_EXPR(arg_node), arg_info);
		break;
	case N_funcall:
		TRAV(FUNCALL_ARGS(arg_node), arg_info);
		break;
	case N_cast:
		TRAV(CAST_EXPR(arg_node), arg_info);
		break;
	case N_fundefs:
		TRAV(FUNDEFS_FUNDEF(arg_node), arg_info);
		TRAV(FUNDEFS_NEXT(arg_node), arg_info);
		break;
	case N_fundef:
		TRAV(FUNDEF_PARAMS(arg_node), arg_info);
		TRAV(FUNDEF_FUNBODY(arg_node), arg_info);
		break;
	case N_funbody:
		TRAV(FUNBODY_VARDECLS(arg_node), arg_info);
		TRAV(FUNBODY_LOCALFUNDEFS(arg_node), arg_info);
		TRAV(FUNBODY_STMTS(arg_node), arg_info);
		break;
	case N_ifelse:
		TRAV(IFELSE_COND(arg_node), arg_info);
		TRAV(IFELSE_THEN(arg_node), arg_info);
		TRAV(IFELSE_ELSE(arg_node), arg_info);
		break;
	case N_while:
		TRAV(WHILE_COND(arg_node), arg_info);
		TRAV(WHILE_BLOCK(arg_node), arg_info);
		break;
	case N_dowhile:
		TRAV(DOWHILE_COND(arg_node), arg_info);
		TRAV(DOWHILE_BLOCK(arg_node), arg_info);
		break;
	case N_for:
		TRAV(FOR_START(arg_node), arg_info);
		TRAV(FOR_STOP(arg_node), arg_info);
		TRAV(FOR_STEP(arg_node), arg_info);
		TRAV(FOR_BLOCK(arg_node), arg_info);
		break;
	case N_globdecl:
		TRAV(GLOBDECL_DIMS(arg_node), arg_info);
		break;
	case N_globdef:
		TRAV(GLOBDEF_DIMS(arg_node), arg_info);
		TRAV(GLOBDEF_INIT(arg_node), arg_info);
		break;
	case N_param:
		TRAV(PARAM_DIMS(arg_node), arg_info);
		TRAV(PARAM_NEXT(arg_node), arg_info);
		break;
	case N_vardecl:
		TRAV(VARDECL_DIMS(arg_node), arg_info);
		TRAV(VARDECL_INIT(arg_node), arg_info);
		TRAV(VARDECL_NEXT(arg_node), arg_info);
		break;
	case N_stmts:
		TRAV(STMTS_STMT(arg_node), arg_info);
		TRAV(STMTS_NEXT(arg_node), arg_info);
		break;
	case N_assign:
		TRAV(ASSIGN_LET(arg_node), arg_info);
		TRAV(ASSIGN_EXPR(arg_node), arg_info);
		break;
	case N_binop:
		TRAV(BINOP_LEFT(arg_node), arg_info);
		TRAV(BINOP_RIGHT(arg_node), arg_info);
		break;
	case N_monop:
		TRAV(MONOP_OPERAND(arg_node), arg_info);
		break;
	case N_varlet:
		TRAV(VARLET_INDICES(arg_node), arg_info);
		break;
	case N_var:
		TRAV(VAR_INDICES(arg_node), arg_info);
		break;
	case N_symboltable:
		TRAV(SYMBOLTABLE_ENTRIES(arg_node), arg_info);
		break;
	case N_symboltableentry:
		break;
	case N_num:
		break;
	case N_float:
		break;
	case N_bool:
		break;
	case N_error:
		TRAV(ERROR_NEXT(arg_node), arg_info);
		break;
	default:
		DBUG_ASSERT((FALSE),
			    "Illegal nodetype found!");
		break;
	}

	return (arg_node);
}

int 
TRAVnumSons(node * node)
{
	int		result = 0;

	DBUG_ENTER("TRAVnumSons");

	switch (NODE_TYPE(node)) {
	case N_program:
		result = 1;
		break;
	case N_decls:
		result = 2;
		break;
	case N_exprs:
		result = 2;
		break;
	case N_arrexpr:
		result = 1;
		break;
	case N_ids:
		result = 1;
		break;
	case N_exprstmt:
		result = 1;
		break;
	case N_return:
		result = 1;
		break;
	case N_funcall:
		result = 1;
		break;
	case N_cast:
		result = 1;
		break;
	case N_fundefs:
		result = 2;
		break;
	case N_fundef:
		result = 2;
		break;
	case N_funbody:
		result = 3;
		break;
	case N_ifelse:
		result = 3;
		break;
	case N_while:
		result = 2;
		break;
	case N_dowhile:
		result = 2;
		break;
	case N_for:
		result = 4;
		break;
	case N_globdecl:
		result = 1;
		break;
	case N_globdef:
		result = 2;
		break;
	case N_param:
		result = 2;
		break;
	case N_vardecl:
		result = 3;
		break;
	case N_stmts:
		result = 2;
		break;
	case N_assign:
		result = 2;
		break;
	case N_binop:
		result = 2;
		break;
	case N_monop:
		result = 1;
		break;
	case N_varlet:
		result = 1;
		break;
	case N_var:
		result = 1;
		break;
	case N_symboltable:
		result = 1;
		break;
	case N_symboltableentry:
		result = 0;
		break;
	case N_num:
		result = 0;
		break;
	case N_float:
		result = 0;
		break;
	case N_bool:
		result = 0;
		break;
	case N_error:
		result = 1;
		break;
	default:
		DBUG_ASSERT((FALSE),
			    "Illegal nodetype found!");
		break;
	}

	DBUG_RETURN(result);
}

node           *
TRAVgetSon(int no, node * parent)
{
	node           *result = NULL;

	DBUG_ENTER("TRAVgetSon");

	switch (NODE_TYPE(parent)) {
	case N_program:
		switch (no) {
		case 0:
			result = PROGRAM_DECLS(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_decls:
		switch (no) {
		case 0:
			result = DECLS_DECL(parent);
			break;
		case 1:
			result = DECLS_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_exprs:
		switch (no) {
		case 0:
			result = EXPRS_EXPR(parent);
			break;
		case 1:
			result = EXPRS_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_arrexpr:
		switch (no) {
		case 0:
			result = ARREXPR_EXPRS(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_ids:
		switch (no) {
		case 0:
			result = IDS_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_exprstmt:
		switch (no) {
		case 0:
			result = EXPRSTMT_EXPR(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_return:
		switch (no) {
		case 0:
			result = RETURN_EXPR(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_funcall:
		switch (no) {
		case 0:
			result = FUNCALL_ARGS(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_cast:
		switch (no) {
		case 0:
			result = CAST_EXPR(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_fundefs:
		switch (no) {
		case 0:
			result = FUNDEFS_FUNDEF(parent);
			break;
		case 1:
			result = FUNDEFS_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_fundef:
		switch (no) {
		case 0:
			result = FUNDEF_PARAMS(parent);
			break;
		case 1:
			result = FUNDEF_FUNBODY(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_funbody:
		switch (no) {
		case 0:
			result = FUNBODY_VARDECLS(parent);
			break;
		case 1:
			result = FUNBODY_LOCALFUNDEFS(parent);
			break;
		case 2:
			result = FUNBODY_STMTS(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_ifelse:
		switch (no) {
		case 0:
			result = IFELSE_COND(parent);
			break;
		case 1:
			result = IFELSE_THEN(parent);
			break;
		case 2:
			result = IFELSE_ELSE(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_while:
		switch (no) {
		case 0:
			result = WHILE_COND(parent);
			break;
		case 1:
			result = WHILE_BLOCK(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_dowhile:
		switch (no) {
		case 0:
			result = DOWHILE_COND(parent);
			break;
		case 1:
			result = DOWHILE_BLOCK(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_for:
		switch (no) {
		case 0:
			result = FOR_START(parent);
			break;
		case 1:
			result = FOR_STOP(parent);
			break;
		case 2:
			result = FOR_STEP(parent);
			break;
		case 3:
			result = FOR_BLOCK(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_globdecl:
		switch (no) {
		case 0:
			result = GLOBDECL_DIMS(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_globdef:
		switch (no) {
		case 0:
			result = GLOBDEF_DIMS(parent);
			break;
		case 1:
			result = GLOBDEF_INIT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_param:
		switch (no) {
		case 0:
			result = PARAM_DIMS(parent);
			break;
		case 1:
			result = PARAM_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_vardecl:
		switch (no) {
		case 0:
			result = VARDECL_DIMS(parent);
			break;
		case 1:
			result = VARDECL_INIT(parent);
			break;
		case 2:
			result = VARDECL_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_stmts:
		switch (no) {
		case 0:
			result = STMTS_STMT(parent);
			break;
		case 1:
			result = STMTS_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_assign:
		switch (no) {
		case 0:
			result = ASSIGN_LET(parent);
			break;
		case 1:
			result = ASSIGN_EXPR(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_binop:
		switch (no) {
		case 0:
			result = BINOP_LEFT(parent);
			break;
		case 1:
			result = BINOP_RIGHT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_monop:
		switch (no) {
		case 0:
			result = MONOP_OPERAND(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_varlet:
		switch (no) {
		case 0:
			result = VARLET_INDICES(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_var:
		switch (no) {
		case 0:
			result = VAR_INDICES(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_symboltable:
		switch (no) {
		case 0:
			result = SYMBOLTABLE_ENTRIES(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_symboltableentry:
		switch (no) {
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_num:
		switch (no) {
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_float:
		switch (no) {
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_bool:
		switch (no) {
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	case N_error:
		switch (no) {
		case 0:
			result = ERROR_NEXT(parent);
			break;
		default:
			DBUG_ASSERT((FALSE), "index out of range!");
			break;
		} break;
	default:
		DBUG_ASSERT((FALSE),
			    "Illegal nodetype found!");
		break;
	}

	DBUG_RETURN(result);
}
