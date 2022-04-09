/*****************************************************************************
 *
 * Module: add_links
 *
 * Prefix: AL
 *
 * Description:
 *
 * Whenever a cast is executed on a boolean, this traversal transforms it into a
 * conditional expression that returns ints 1-0 for Boolean values true-false 
 * respectively, or float 1.0-0.0
 *
 *****************************************************************************/


#include "add_links.h"
#include "make_table_helper.h"

#include "stdlib.h"
#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"
#include "string.h"

#include "memory.h"
#include "ctinfo.h"

struct INFO {
  type type;
  node* Symboltable;
};

#define INFO_ST(n) ((n)->Symboltable)

static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_ST(result) = NULL;

  DBUG_RETURN( result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}

/*
 * Traversal functions
 */

node* ALprogram(node *arg_node, info *arg_info) {

  DBUG_ENTER("ALprogram");

  INFO_ST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

node* ALfundef(node *arg_node, info *arg_info) {

  DBUG_ENTER("ALprogram");

  INFO_ST(arg_info) = FUNDEF_SYMBOLTABLE(arg_node);
  FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

// Adds a link to globdecl the correct symboltableEntry.
node *ALglobdecl(node* arg_node, info* arg_info) {

    DBUG_ENTER("ALglobdecl");

    // Get a pointer to symboltableEntry of the globdecl.
    char* name = STRcpy(GLOBDECL_NAME(arg_node));
    node* ST_entry = get_entry(name, INFO_ST(arg_info), FALSE);

    // Add the pointer to the decl attribute of globdecl.
    if(ST_entry != NULL) {
        GLOBDECL_DECL(arg_node) = ST_entry;
    }
    else {
        // If decleration was not found, an error is thrown.
        CTIerror("varlet %s is not in scope\n", name);
    }

    DBUG_RETURN(arg_node);
  
}

// Adds a link to globdef to the correct symboltableEntry.
node *ALglobdef(node* arg_node, info* arg_info) {

    DBUG_ENTER("ALglobdef");

    // Get a pointer to the symboltableEntry of the globdef.
    char* name = STRcpy(GLOBDEF_NAME(arg_node));
    node* ST_entry = get_entry(name, INFO_ST(arg_info), FALSE);

    // Add the pointer to the decl attribute of the globdef.
    if(ST_entry != NULL) {
        GLOBDEF_DECL(arg_node) = ST_entry;
    }
    else {
        // If decleration was not found, an error is thrown.
        CTIerror("varlet %s is not in scope\n", name);
    }

    DBUG_RETURN(arg_node); 
}

// Adds a link to vardecl to the correct symboltableEntry.
node *ALvardecl(node* arg_node, info* arg_info) {

    DBUG_ENTER("ALvardecl");

    VARDECL_INIT(arg_node) = TRAVopt(VARDECL_INIT(arg_node), arg_info);

    // Get pointer to the symboltableEntry of the vardecl.
    char* name = STRcpy(VARDECL_NAME(arg_node));
    node* ST_entry = get_entry(name, INFO_ST(arg_info), FALSE);

    // Add the pointer to the decl attribute of the vardecl.
    if(ST_entry != NULL) {
        VARDECL_DECL(arg_node) = ST_entry;
    }
    else {
        // If decleration was not found, an error is thrown.
        CTIerror("varlet %s is not in scope\n", name);
    }

    VARDECL_NEXT(arg_node) = TRAVopt(VARDECL_NEXT(arg_node), arg_info);

    DBUG_RETURN(arg_node);
  
}

// Adds a link to funcall to the correct symboltableEntry.
node *ALfuncall(node* arg_node, info* arg_info) {

    DBUG_ENTER("ALfuncall");

    // Get pointer to the symboltableEntry of the vardecl.
    char* name = STRcpy(FUNCALL_NAME(arg_node));
    node* ST_entry = get_entry(name, INFO_ST(arg_info), TRUE);
    
    // Get the pointer to the decl attribute of funcall.
    if(ST_entry != NULL) {
        FUNCALL_DECL(arg_node) = ST_entry;
    }
    else {
        // If decleration was not found, an error is thrown.
        CTIerror("funcall %s is not in scope\n", name);
    }

    // Traverse through the arguments of the function.
    FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);

    DBUG_RETURN(arg_node);
  
}

// Adds a link to varlet to the correct symboltableEntry.
node *ALvarlet(node* arg_node, info* arg_info) {

    DBUG_ENTER("ALvarlet");

    // Get pointer to the symboltableEntry of the varlet.
    char* name = STRcpy(VARLET_NAME(arg_node));
    node* ST_entry = get_entry(name, INFO_ST(arg_info), FALSE);

    // Get the pointer to the decl attribute of varlet.  
    if(ST_entry != NULL) {
        VARLET_DECL(arg_node) = ST_entry;
    }
    else {
        // If decleration was not found, an error is thrown.
        CTIerror("varlet %s is not in scope\n", name);
    }

    DBUG_RETURN(arg_node);
  
}

// Adds a link to var to the correct symboltableEntry
node *ALvar(node* arg_node, info* arg_info) {

    DBUG_ENTER("ALvar");
    
    // Get pointer to the symboltableEntry of the varlet.
    char* name = STRcpy(VAR_NAME(arg_node));
    node* ST_entry = get_entry(name, INFO_ST(arg_info), FALSE);

    // Get the pointer to the decl attribute of varlet.
    if(ST_entry != NULL) {
        VAR_DECL(arg_node) = ST_entry;
    }
    else {
        // If decleration was not found, an error is thrown.
        CTIerror("var %s is not in scope\n", name);
    }

    DBUG_RETURN(arg_node);
  
}


/*
 * Traversal start function
 */

node *ALdoAddLinks( node *syntaxtree)
{

  DBUG_ENTER("ALdoAddLinks");

  info *arg_info = MakeInfo();

  TRAVpush( TR_al);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
