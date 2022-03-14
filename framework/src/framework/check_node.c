
/**
 * @file check_node.c
 *
 * Functions needed by chkm traversal.
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: check_node.c.xsl 15657 2007-11-13 13:57:30Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

/**
 * @defgroup check Touch all Tree Functions to catch every node, son and attribute
 *
 * Functions needed by free traversal.
 *
 * @{
 */


#include "check_node.h"
#include "check_attribs.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"

#define CHKMTRAV( node, info) (node != NULL) ? TRAVdo( node, info) : node
#define CHKMCOND( node, info)                                    \
    ? CHKMTRAV( node, info)                                      \
    : (node)



/*******************************************************************************
 *
 * @fn CHKMpostfun
 *
 * This is the postfun function of the CHKM Traversal
 *
 ******************************************************************************/
node           *
CHKMpostfun(node * arg_node, info * arg_info)
{
	DBUG_ENTER("CHKMpostfun");

	DBUG_RETURN(arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKMarrexpr
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node ArrExpr node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMarrexpr(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMarrexpr");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	ARREXPR_EXPRS(arg_node) = CHKMTRAV(ARREXPR_EXPRS(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMassign
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Assign node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMassign(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMassign");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	ASSIGN_LET(arg_node) = CHKMTRAV(ASSIGN_LET(arg_node), arg_info);
	ASSIGN_EXPR(arg_node) = CHKMTRAV(ASSIGN_EXPR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMbinop
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMbinop(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMbinop");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	BINOP_LEFT(arg_node) = CHKMTRAV(BINOP_LEFT(arg_node), arg_info);
	BINOP_RIGHT(arg_node) = CHKMTRAV(BINOP_RIGHT(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMbool
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Bool node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMbool(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMbool");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMcast
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Cast node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMcast(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMcast");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	CAST_EXPR(arg_node) = CHKMTRAV(CAST_EXPR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMdecls
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Decls node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMdecls(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMdecls");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	DECLS_NEXT(arg_node) = CHKMTRAV(DECLS_NEXT(arg_node), arg_info);
	DECLS_DECL(arg_node) = CHKMTRAV(DECLS_DECL(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMdowhile
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node DoWhile node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMdowhile(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMdowhile");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	DOWHILE_COND(arg_node) = CHKMTRAV(DOWHILE_COND(arg_node), arg_info);
	DOWHILE_BLOCK(arg_node) = CHKMTRAV(DOWHILE_BLOCK(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMerror
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Error node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMerror(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMerror");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	ERROR_NEXT(arg_node) = CHKMTRAV(ERROR_NEXT(arg_node), arg_info);
	ERROR_MESSAGE(arg_node) = CHKMattribString(ERROR_MESSAGE(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMexprstmt
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node ExprStmt node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMexprstmt(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMexprstmt");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	EXPRSTMT_EXPR(arg_node) = CHKMTRAV(EXPRSTMT_EXPR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMexprs
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Exprs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMexprs(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMexprs");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	EXPRS_NEXT(arg_node) = CHKMTRAV(EXPRS_NEXT(arg_node), arg_info);
	EXPRS_EXPR(arg_node) = CHKMTRAV(EXPRS_EXPR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMfloat
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMfloat(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMfloat");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMfor
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node For node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMfor(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMfor");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	FOR_LOOPVAR(arg_node) = CHKMattribString(FOR_LOOPVAR(arg_node), arg_info);
	FOR_START(arg_node) = CHKMTRAV(FOR_START(arg_node), arg_info);
	FOR_STOP(arg_node) = CHKMTRAV(FOR_STOP(arg_node), arg_info);
	FOR_STEP(arg_node) = CHKMTRAV(FOR_STEP(arg_node), arg_info);
	FOR_BLOCK(arg_node) = CHKMTRAV(FOR_BLOCK(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMfunbody
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node FunBody node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMfunbody(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMfunbody");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	FUNBODY_VARDECLS(arg_node) = CHKMTRAV(FUNBODY_VARDECLS(arg_node), arg_info);
	FUNBODY_LOCALFUNDEFS(arg_node) = CHKMTRAV(FUNBODY_LOCALFUNDEFS(arg_node), arg_info);
	FUNBODY_STMTS(arg_node) = CHKMTRAV(FUNBODY_STMTS(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMfuncall
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node FunCall node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMfuncall(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMfuncall");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	FUNCALL_NAME(arg_node) = CHKMattribString(FUNCALL_NAME(arg_node), arg_info);
	FUNCALL_DECL(arg_node) = CHKMattribLink(FUNCALL_DECL(arg_node), arg_info);
	FUNCALL_ARGS(arg_node) = CHKMTRAV(FUNCALL_ARGS(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMfundef
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node FunDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMfundef(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMfundef");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	FUNDEF_NAME(arg_node) = CHKMattribString(FUNDEF_NAME(arg_node), arg_info);
	FUNDEF_PARAMS(arg_node) = CHKMTRAV(FUNDEF_PARAMS(arg_node), arg_info);
	FUNDEF_FUNBODY(arg_node) = CHKMTRAV(FUNDEF_FUNBODY(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMfundefs
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node FunDefs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMfundefs(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMfundefs");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	FUNDEFS_NEXT(arg_node) = CHKMTRAV(FUNDEFS_NEXT(arg_node), arg_info);
	FUNDEFS_FUNDEF(arg_node) = CHKMTRAV(FUNDEFS_FUNDEF(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMglobdecl
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node GlobDecl node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMglobdecl(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMglobdecl");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	GLOBDECL_NAME(arg_node) = CHKMattribString(GLOBDECL_NAME(arg_node), arg_info);
	GLOBDECL_DIMS(arg_node) = CHKMTRAV(GLOBDECL_DIMS(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMglobdef
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node GlobDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMglobdef(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMglobdef");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	GLOBDEF_NAME(arg_node) = CHKMattribString(GLOBDEF_NAME(arg_node), arg_info);
	GLOBDEF_DIMS(arg_node) = CHKMTRAV(GLOBDEF_DIMS(arg_node), arg_info);
	GLOBDEF_INIT(arg_node) = CHKMTRAV(GLOBDEF_INIT(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMids
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Ids node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMids(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMids");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	IDS_NEXT(arg_node) = CHKMTRAV(IDS_NEXT(arg_node), arg_info);
	IDS_NAME(arg_node) = CHKMattribString(IDS_NAME(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMifelse
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node IfElse node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMifelse(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMifelse");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	IFELSE_COND(arg_node) = CHKMTRAV(IFELSE_COND(arg_node), arg_info);
	IFELSE_THEN(arg_node) = CHKMTRAV(IFELSE_THEN(arg_node), arg_info);
	IFELSE_ELSE(arg_node) = CHKMTRAV(IFELSE_ELSE(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMmonop
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node MonOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMmonop(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMmonop");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	MONOP_OPERAND(arg_node) = CHKMTRAV(MONOP_OPERAND(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMnum
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMnum(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMnum");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMparam
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Param node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMparam(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMparam");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	PARAM_NEXT(arg_node) = CHKMTRAV(PARAM_NEXT(arg_node), arg_info);
	PARAM_NAME(arg_node) = CHKMattribString(PARAM_NAME(arg_node), arg_info);
	PARAM_DIMS(arg_node) = CHKMTRAV(PARAM_DIMS(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMprogram
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Program node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMprogram(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMprogram");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	PROGRAM_DECLS(arg_node) = CHKMTRAV(PROGRAM_DECLS(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMreturn
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Return node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMreturn(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMreturn");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	RETURN_EXPR(arg_node) = CHKMTRAV(RETURN_EXPR(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMstmts
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Stmts node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMstmts(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMstmts");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	STMTS_NEXT(arg_node) = CHKMTRAV(STMTS_NEXT(arg_node), arg_info);
	STMTS_STMT(arg_node) = CHKMTRAV(STMTS_STMT(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMsymboltable
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Symboltable node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMsymboltable(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMsymboltable");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	SYMBOLTABLE_NAME(arg_node) = CHKMattribString(SYMBOLTABLE_NAME(arg_node), arg_info);
	SYMBOLTABLE_DECL(arg_node) = CHKMattribLink(SYMBOLTABLE_DECL(arg_node), arg_info);
	SYMBOLTABLE_ENTRIES(arg_node) = CHKMTRAV(SYMBOLTABLE_ENTRIES(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMsymboltableentry
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node SymboltableEntry node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMsymboltableentry(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMsymboltableentry");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	SYMBOLTABLEENTRY_NAME(arg_node) = CHKMattribString(SYMBOLTABLEENTRY_NAME(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMvar
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node Var node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMvar(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMvar");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	VAR_NAME(arg_node) = CHKMattribString(VAR_NAME(arg_node), arg_info);
	VAR_DECL(arg_node) = CHKMattribLink(VAR_DECL(arg_node), arg_info);
	VAR_INDICES(arg_node) = CHKMTRAV(VAR_INDICES(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMvardecl
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node VarDecl node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMvardecl(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMvardecl");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	VARDECL_NEXT(arg_node) = CHKMTRAV(VARDECL_NEXT(arg_node), arg_info);
	VARDECL_NAME(arg_node) = CHKMattribString(VARDECL_NAME(arg_node), arg_info);
	VARDECL_DIMS(arg_node) = CHKMTRAV(VARDECL_DIMS(arg_node), arg_info);
	VARDECL_INIT(arg_node) = CHKMTRAV(VARDECL_INIT(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMvarlet
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node VarLet node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMvarlet(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMvarlet");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	VARLET_NAME(arg_node) = CHKMattribString(VARLET_NAME(arg_node), arg_info);
	VARLET_DECL(arg_node) = CHKMattribLink(VARLET_DECL(arg_node), arg_info);
	VARLET_INDICES(arg_node) = CHKMTRAV(VARLET_INDICES(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn CHKMwhile
 *
 * @brief Touched the node and its sons/attributes
 *
 * @param arg_node While node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *CHKMwhile(node * arg_node, info * arg_info) {
	DBUG_ENTER("CHKMwhile");
	NODE_ERROR(arg_node) = CHKMTRAV(NODE_ERROR(arg_node), arg_info);
	WHILE_COND(arg_node) = CHKMTRAV(WHILE_COND(arg_node), arg_info);
	WHILE_BLOCK(arg_node) = CHKMTRAV(WHILE_BLOCK(arg_node), arg_info);
	DBUG_RETURN(arg_node);
}
/**
 * @}
 */
