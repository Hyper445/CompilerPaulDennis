
/**
 * @file eval.c
 *
 * Functions needed for compiling
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: free_node.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

/**
 * @defgroup comp Compilation functions.
 *
 * Functions needed for compiling.
 *
 * @{
 */


#include "eval.h"
#include "traverse.h"
#include "dbug.h"


/** <!--******************************************************************-->
 *
 * @fn EVALarrexpr
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node ArrExpr node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALarrexpr(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALarrexpr");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALassign
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Assign node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALassign(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALassign");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALbinop
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALbinop(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALbinop");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALbool
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Bool node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALbool(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALbool");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALcast
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Cast node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALcast(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALcast");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALcondexpr
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node CondExpr node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALcondexpr(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALcondexpr");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALconstant
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Constant node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALconstant(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALconstant");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALdecls
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Decls node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALdecls(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALdecls");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALdowhile
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node DoWhile node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALdowhile(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALdowhile");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALerror
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Error node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALerror(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALerror");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALexport
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Export node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALexport(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALexport");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALexprstmt
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node ExprStmt node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALexprstmt(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALexprstmt");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALexprs
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Exprs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALexprs(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALexprs");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALextern
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Extern node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALextern(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALextern");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALfloat
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALfloat(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALfloat");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALfor
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node For node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALfor(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALfor");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALfunbody
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunBody node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALfunbody(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALfunbody");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALfuncall
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunCall node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALfuncall(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALfuncall");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALfundef
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALfundef(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALfundef");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALfundefs
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunDefs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALfundefs(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALfundefs");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALglobdecl
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node GlobDecl node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALglobdecl(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALglobdecl");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALglobdef
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node GlobDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALglobdef(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALglobdef");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALids
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Ids node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALids(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALids");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALifelse
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node IfElse node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALifelse(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALifelse");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALmonop
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node MonOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALmonop(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALmonop");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALnum
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALnum(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALnum");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALparam
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Param node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALparam(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALparam");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALprogram
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Program node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALprogram(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALprogram");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALreturn
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Return node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALreturn(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALreturn");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALstmts
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Stmts node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALstmts(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALstmts");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALsymboltable
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Symboltable node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALsymboltable(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALsymboltable");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALsymboltableentry
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node SymboltableEntry node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALsymboltableentry(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALsymboltableentry");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALvar
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Var node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALvar(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALvar");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALvardecl
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node VarDecl node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALvardecl(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALvardecl");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALvarlet
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node VarLet node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALvarlet(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALvarlet");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/** <!--******************************************************************-->
 *
 * @fn EVALwhile
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node While node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node           *EVALwhile(node * arg_node, info * arg_info) {
	DBUG_ENTER("EVALwhile");
	arg_node = TRAVcont(arg_node, arg_info);
	DBUG_RETURN(arg_node);
}
/**
 * @}
 */
