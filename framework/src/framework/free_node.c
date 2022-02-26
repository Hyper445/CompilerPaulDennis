
/**
 * @file free_node.c
 *
 * Functions needed by free traversal.
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: free_node.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

/**
 * @defgroup free Free Tree Functions.
 *
 * Functions needed by free traversal.
 *
 * @{
 */


#include "free.h"
#include "free_node.h"
#include "free_attribs.h"
#include "free_info.h"
#include "tree_basic.h"
#include "traverse.h"
#include "str.h"
#include "memory.h"
#include "dbug.h"

#define FREETRAV( node, info) (node != NULL) ? TRAVdo( node, info) : node
#define FREECOND( node, info)                                    \
  (INFO_FREE_FLAG( info) != arg_node)                            \
    ? FREETRAV( node, info)                                      \
    : (node)


/** <!--******************************************************************-->
 *
 * @fn FREEarrexpr
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node ArrExpr node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEarrexpr(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEarrexpr");
	DBUG_PRINT("FREE", ("Processing node N_arrexpr at " F_PTR, arg_node));
	ARREXPR_EXPRS(arg_node) = FREETRAV(ARREXPR_EXPRS(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_arrexpr = MEMfree(arg_node->sons.N_arrexpr);
	arg_node->attribs.N_arrexpr = MEMfree(arg_node->attribs.N_arrexpr);
	DBUG_PRINT("FREE", ("Processing node N_arrexpr at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEassign
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Assign node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEassign(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEassign");
	DBUG_PRINT("FREE", ("Processing node N_assign at " F_PTR, arg_node));
	ASSIGN_LET(arg_node) = FREETRAV(ASSIGN_LET(arg_node), arg_info);
	ASSIGN_EXPR(arg_node) = FREETRAV(ASSIGN_EXPR(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_assign = MEMfree(arg_node->sons.N_assign);
	arg_node->attribs.N_assign = MEMfree(arg_node->attribs.N_assign);
	DBUG_PRINT("FREE", ("Processing node N_assign at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEbinop
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEbinop(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEbinop");
	DBUG_PRINT("FREE", ("Processing node N_binop at " F_PTR, arg_node));
	BINOP_LEFT(arg_node) = FREETRAV(BINOP_LEFT(arg_node), arg_info);
	BINOP_RIGHT(arg_node) = FREETRAV(BINOP_RIGHT(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_binop = MEMfree(arg_node->sons.N_binop);
	arg_node->attribs.N_binop = MEMfree(arg_node->attribs.N_binop);
	DBUG_PRINT("FREE", ("Processing node N_binop at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEbool
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Bool node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEbool(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEbool");
	DBUG_PRINT("FREE", ("Processing node N_bool at " F_PTR, arg_node));
	result = NULL;
	arg_node->sons.N_bool = MEMfree(arg_node->sons.N_bool);
	arg_node->attribs.N_bool = MEMfree(arg_node->attribs.N_bool);
	DBUG_PRINT("FREE", ("Processing node N_bool at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEcast
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Cast node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEcast(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEcast");
	DBUG_PRINT("FREE", ("Processing node N_cast at " F_PTR, arg_node));
	CAST_EXPR(arg_node) = FREETRAV(CAST_EXPR(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_cast = MEMfree(arg_node->sons.N_cast);
	arg_node->attribs.N_cast = MEMfree(arg_node->attribs.N_cast);
	DBUG_PRINT("FREE", ("Processing node N_cast at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEdecls
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Decls node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEdecls(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEdecls");
	DBUG_PRINT("FREE", ("Processing node N_decls at " F_PTR, arg_node));
	DECLS_NEXT(arg_node) = FREECOND(DECLS_NEXT(arg_node), arg_info);
	DECLS_DECL(arg_node) = FREETRAV(DECLS_DECL(arg_node), arg_info);
	result = DECLS_NEXT(arg_node);
	arg_node->sons.N_decls = MEMfree(arg_node->sons.N_decls);
	arg_node->attribs.N_decls = MEMfree(arg_node->attribs.N_decls);
	DBUG_PRINT("FREE", ("Processing node N_decls at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEdowhile
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node DoWhile node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEdowhile(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEdowhile");
	DBUG_PRINT("FREE", ("Processing node N_dowhile at " F_PTR, arg_node));
	DOWHILE_COND(arg_node) = FREETRAV(DOWHILE_COND(arg_node), arg_info);
	DOWHILE_BLOCK(arg_node) = FREETRAV(DOWHILE_BLOCK(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_dowhile = MEMfree(arg_node->sons.N_dowhile);
	arg_node->attribs.N_dowhile = MEMfree(arg_node->attribs.N_dowhile);
	DBUG_PRINT("FREE", ("Processing node N_dowhile at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEerror
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Error node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEerror(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEerror");
	DBUG_PRINT("FREE", ("Processing node N_error at " F_PTR, arg_node));
	ERROR_NEXT(arg_node) = FREECOND(ERROR_NEXT(arg_node), arg_info);
	ERROR_MESSAGE(arg_node) = FREEattribString(ERROR_MESSAGE(arg_node), arg_node);
	result = ERROR_NEXT(arg_node);
	arg_node->sons.N_error = MEMfree(arg_node->sons.N_error);
	arg_node->attribs.N_error = MEMfree(arg_node->attribs.N_error);
	DBUG_PRINT("FREE", ("Processing node N_error at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEexprstmt
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node ExprStmt node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEexprstmt(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEexprstmt");
	DBUG_PRINT("FREE", ("Processing node N_exprstmt at " F_PTR, arg_node));
	EXPRSTMT_EXPR(arg_node) = FREETRAV(EXPRSTMT_EXPR(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_exprstmt = MEMfree(arg_node->sons.N_exprstmt);
	arg_node->attribs.N_exprstmt = MEMfree(arg_node->attribs.N_exprstmt);
	DBUG_PRINT("FREE", ("Processing node N_exprstmt at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEexprs
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Exprs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEexprs(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEexprs");
	DBUG_PRINT("FREE", ("Processing node N_exprs at " F_PTR, arg_node));
	EXPRS_NEXT(arg_node) = FREECOND(EXPRS_NEXT(arg_node), arg_info);
	EXPRS_EXPR(arg_node) = FREETRAV(EXPRS_EXPR(arg_node), arg_info);
	result = EXPRS_NEXT(arg_node);
	arg_node->sons.N_exprs = MEMfree(arg_node->sons.N_exprs);
	arg_node->attribs.N_exprs = MEMfree(arg_node->attribs.N_exprs);
	DBUG_PRINT("FREE", ("Processing node N_exprs at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEfloat
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEfloat(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEfloat");
	DBUG_PRINT("FREE", ("Processing node N_float at " F_PTR, arg_node));
	result = NULL;
	arg_node->sons.N_float = MEMfree(arg_node->sons.N_float);
	arg_node->attribs.N_float = MEMfree(arg_node->attribs.N_float);
	DBUG_PRINT("FREE", ("Processing node N_float at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEfor
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node For node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEfor(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEfor");
	DBUG_PRINT("FREE", ("Processing node N_for at " F_PTR, arg_node));
	FOR_LOOPVAR(arg_node) = FREEattribString(FOR_LOOPVAR(arg_node), arg_node);
	FOR_START(arg_node) = FREETRAV(FOR_START(arg_node), arg_info);
	FOR_STOP(arg_node) = FREETRAV(FOR_STOP(arg_node), arg_info);
	FOR_STEP(arg_node) = FREETRAV(FOR_STEP(arg_node), arg_info);
	FOR_BLOCK(arg_node) = FREETRAV(FOR_BLOCK(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_for = MEMfree(arg_node->sons.N_for);
	arg_node->attribs.N_for = MEMfree(arg_node->attribs.N_for);
	DBUG_PRINT("FREE", ("Processing node N_for at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEfunbody
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunBody node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEfunbody(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEfunbody");
	DBUG_PRINT("FREE", ("Processing node N_funbody at " F_PTR, arg_node));
	FUNBODY_VARDECLS(arg_node) = FREETRAV(FUNBODY_VARDECLS(arg_node), arg_info);
	FUNBODY_LOCALFUNDEFS(arg_node) = FREETRAV(FUNBODY_LOCALFUNDEFS(arg_node), arg_info);
	FUNBODY_STMTS(arg_node) = FREETRAV(FUNBODY_STMTS(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_funbody = MEMfree(arg_node->sons.N_funbody);
	arg_node->attribs.N_funbody = MEMfree(arg_node->attribs.N_funbody);
	DBUG_PRINT("FREE", ("Processing node N_funbody at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEfuncall
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunCall node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEfuncall(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEfuncall");
	DBUG_PRINT("FREE", ("Processing node N_funcall at " F_PTR, arg_node));
	FUNCALL_NAME(arg_node) = FREEattribString(FUNCALL_NAME(arg_node), arg_node);
	FUNCALL_DECL(arg_node) = FREEattribLink(FUNCALL_DECL(arg_node), arg_node);
	FUNCALL_ARGS(arg_node) = FREETRAV(FUNCALL_ARGS(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_funcall = MEMfree(arg_node->sons.N_funcall);
	arg_node->attribs.N_funcall = MEMfree(arg_node->attribs.N_funcall);
	DBUG_PRINT("FREE", ("Processing node N_funcall at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEfundef
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEfundef(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEfundef");
	DBUG_PRINT("FREE", ("Processing node N_fundef at " F_PTR, arg_node));
	FUNDEF_NAME(arg_node) = FREEattribString(FUNDEF_NAME(arg_node), arg_node);
	FUNDEF_FUNBODY(arg_node) = FREETRAV(FUNDEF_FUNBODY(arg_node), arg_info);
	FUNDEF_PARAMS(arg_node) = FREETRAV(FUNDEF_PARAMS(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_fundef = MEMfree(arg_node->sons.N_fundef);
	arg_node->attribs.N_fundef = MEMfree(arg_node->attribs.N_fundef);
	DBUG_PRINT("FREE", ("Processing node N_fundef at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEfundefs
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunDefs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEfundefs(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEfundefs");
	DBUG_PRINT("FREE", ("Processing node N_fundefs at " F_PTR, arg_node));
	FUNDEFS_NEXT(arg_node) = FREECOND(FUNDEFS_NEXT(arg_node), arg_info);
	FUNDEFS_FUNDEF(arg_node) = FREETRAV(FUNDEFS_FUNDEF(arg_node), arg_info);
	result = FUNDEFS_NEXT(arg_node);
	arg_node->sons.N_fundefs = MEMfree(arg_node->sons.N_fundefs);
	arg_node->attribs.N_fundefs = MEMfree(arg_node->attribs.N_fundefs);
	DBUG_PRINT("FREE", ("Processing node N_fundefs at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEglobdecl
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node GlobDecl node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEglobdecl(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEglobdecl");
	DBUG_PRINT("FREE", ("Processing node N_globdecl at " F_PTR, arg_node));
	GLOBDECL_NAME(arg_node) = FREEattribString(GLOBDECL_NAME(arg_node), arg_node);
	GLOBDECL_DIMS(arg_node) = FREETRAV(GLOBDECL_DIMS(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_globdecl = MEMfree(arg_node->sons.N_globdecl);
	arg_node->attribs.N_globdecl = MEMfree(arg_node->attribs.N_globdecl);
	DBUG_PRINT("FREE", ("Processing node N_globdecl at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEglobdef
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node GlobDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEglobdef(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEglobdef");
	DBUG_PRINT("FREE", ("Processing node N_globdef at " F_PTR, arg_node));
	GLOBDEF_NAME(arg_node) = FREEattribString(GLOBDEF_NAME(arg_node), arg_node);
	GLOBDEF_DIMS(arg_node) = FREETRAV(GLOBDEF_DIMS(arg_node), arg_info);
	GLOBDEF_INIT(arg_node) = FREETRAV(GLOBDEF_INIT(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_globdef = MEMfree(arg_node->sons.N_globdef);
	arg_node->attribs.N_globdef = MEMfree(arg_node->attribs.N_globdef);
	DBUG_PRINT("FREE", ("Processing node N_globdef at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEids
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Ids node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEids(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEids");
	DBUG_PRINT("FREE", ("Processing node N_ids at " F_PTR, arg_node));
	IDS_NEXT(arg_node) = FREECOND(IDS_NEXT(arg_node), arg_info);
	IDS_NAME(arg_node) = FREEattribString(IDS_NAME(arg_node), arg_node);
	result = IDS_NEXT(arg_node);
	arg_node->sons.N_ids = MEMfree(arg_node->sons.N_ids);
	arg_node->attribs.N_ids = MEMfree(arg_node->attribs.N_ids);
	DBUG_PRINT("FREE", ("Processing node N_ids at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEifelse
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node IfElse node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEifelse(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEifelse");
	DBUG_PRINT("FREE", ("Processing node N_ifelse at " F_PTR, arg_node));
	IFELSE_COND(arg_node) = FREETRAV(IFELSE_COND(arg_node), arg_info);
	IFELSE_THEN(arg_node) = FREETRAV(IFELSE_THEN(arg_node), arg_info);
	IFELSE_ELSE(arg_node) = FREETRAV(IFELSE_ELSE(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_ifelse = MEMfree(arg_node->sons.N_ifelse);
	arg_node->attribs.N_ifelse = MEMfree(arg_node->attribs.N_ifelse);
	DBUG_PRINT("FREE", ("Processing node N_ifelse at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEmonop
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node MonOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEmonop(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEmonop");
	DBUG_PRINT("FREE", ("Processing node N_monop at " F_PTR, arg_node));
	MONOP_OPERAND(arg_node) = FREETRAV(MONOP_OPERAND(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_monop = MEMfree(arg_node->sons.N_monop);
	arg_node->attribs.N_monop = MEMfree(arg_node->attribs.N_monop);
	DBUG_PRINT("FREE", ("Processing node N_monop at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEnum
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEnum(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEnum");
	DBUG_PRINT("FREE", ("Processing node N_num at " F_PTR, arg_node));
	result = NULL;
	arg_node->sons.N_num = MEMfree(arg_node->sons.N_num);
	arg_node->attribs.N_num = MEMfree(arg_node->attribs.N_num);
	DBUG_PRINT("FREE", ("Processing node N_num at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEparam
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Param node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEparam(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEparam");
	DBUG_PRINT("FREE", ("Processing node N_param at " F_PTR, arg_node));
	PARAM_NEXT(arg_node) = FREECOND(PARAM_NEXT(arg_node), arg_info);
	PARAM_NAME(arg_node) = FREEattribString(PARAM_NAME(arg_node), arg_node);
	PARAM_DIMS(arg_node) = FREETRAV(PARAM_DIMS(arg_node), arg_info);
	result = PARAM_NEXT(arg_node);
	arg_node->sons.N_param = MEMfree(arg_node->sons.N_param);
	arg_node->attribs.N_param = MEMfree(arg_node->attribs.N_param);
	DBUG_PRINT("FREE", ("Processing node N_param at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEprogram
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Program node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEprogram(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEprogram");
	DBUG_PRINT("FREE", ("Processing node N_program at " F_PTR, arg_node));
	PROGRAM_DECLS(arg_node) = FREETRAV(PROGRAM_DECLS(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_program = MEMfree(arg_node->sons.N_program);
	arg_node->attribs.N_program = MEMfree(arg_node->attribs.N_program);
	DBUG_PRINT("FREE", ("Processing node N_program at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEreturn
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Return node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEreturn(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEreturn");
	DBUG_PRINT("FREE", ("Processing node N_return at " F_PTR, arg_node));
	RETURN_EXPR(arg_node) = FREETRAV(RETURN_EXPR(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_return = MEMfree(arg_node->sons.N_return);
	arg_node->attribs.N_return = MEMfree(arg_node->attribs.N_return);
	DBUG_PRINT("FREE", ("Processing node N_return at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEstmts
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Stmts node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEstmts(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEstmts");
	DBUG_PRINT("FREE", ("Processing node N_stmts at " F_PTR, arg_node));
	STMTS_NEXT(arg_node) = FREECOND(STMTS_NEXT(arg_node), arg_info);
	STMTS_STMT(arg_node) = FREETRAV(STMTS_STMT(arg_node), arg_info);
	result = STMTS_NEXT(arg_node);
	arg_node->sons.N_stmts = MEMfree(arg_node->sons.N_stmts);
	arg_node->attribs.N_stmts = MEMfree(arg_node->attribs.N_stmts);
	DBUG_PRINT("FREE", ("Processing node N_stmts at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEvar
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Var node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEvar(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEvar");
	DBUG_PRINT("FREE", ("Processing node N_var at " F_PTR, arg_node));
	VAR_NAME(arg_node) = FREEattribString(VAR_NAME(arg_node), arg_node);
	VAR_DECL(arg_node) = FREEattribLink(VAR_DECL(arg_node), arg_node);
	VAR_INDICES(arg_node) = FREETRAV(VAR_INDICES(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_var = MEMfree(arg_node->sons.N_var);
	arg_node->attribs.N_var = MEMfree(arg_node->attribs.N_var);
	DBUG_PRINT("FREE", ("Processing node N_var at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEvardecl
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node VarDecl node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEvardecl(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEvardecl");
	DBUG_PRINT("FREE", ("Processing node N_vardecl at " F_PTR, arg_node));
	VARDECL_NEXT(arg_node) = FREECOND(VARDECL_NEXT(arg_node), arg_info);
	VARDECL_NAME(arg_node) = FREEattribString(VARDECL_NAME(arg_node), arg_node);
	VARDECL_DIMS(arg_node) = FREETRAV(VARDECL_DIMS(arg_node), arg_info);
	VARDECL_INIT(arg_node) = FREETRAV(VARDECL_INIT(arg_node), arg_info);
	result = VARDECL_NEXT(arg_node);
	arg_node->sons.N_vardecl = MEMfree(arg_node->sons.N_vardecl);
	arg_node->attribs.N_vardecl = MEMfree(arg_node->attribs.N_vardecl);
	DBUG_PRINT("FREE", ("Processing node N_vardecl at " F_PTR, arg_node));
	arg_node = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEvarlet
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node VarLet node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEvarlet(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEvarlet");
	DBUG_PRINT("FREE", ("Processing node N_varlet at " F_PTR, arg_node));
	VARLET_NAME(arg_node) = FREEattribString(VARLET_NAME(arg_node), arg_node);
	VARLET_DECL(arg_node) = FREEattribLink(VARLET_DECL(arg_node), arg_node);
	VARLET_INDICES(arg_node) = FREETRAV(VARLET_INDICES(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_varlet = MEMfree(arg_node->sons.N_varlet);
	arg_node->attribs.N_varlet = MEMfree(arg_node->attribs.N_varlet);
	DBUG_PRINT("FREE", ("Processing node N_varlet at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/** <!--******************************************************************-->
 *
 * @fn FREEwhile
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node While node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *FREEwhile(node * arg_node, info * arg_info) {
	node           *result = NULL;
	DBUG_ENTER("FREEwhile");
	DBUG_PRINT("FREE", ("Processing node N_while at " F_PTR, arg_node));
	WHILE_COND(arg_node) = FREETRAV(WHILE_COND(arg_node), arg_info);
	WHILE_BLOCK(arg_node) = FREETRAV(WHILE_BLOCK(arg_node), arg_info);
	result = NULL;
	arg_node->sons.N_while = MEMfree(arg_node->sons.N_while);
	arg_node->attribs.N_while = MEMfree(arg_node->attribs.N_while);
	DBUG_PRINT("FREE", ("Processing node N_while at " F_PTR, arg_node));
	result = MEMfree(arg_node);
	DBUG_RETURN(result);
}
/**
 * @}
 */
