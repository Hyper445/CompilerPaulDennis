/*****************************************************************************
 *
 * Module: tranform_while
 *
 * Prefix: TW
 *
 * Description:
 *
 * This module replaces all while-loops with their do-while-loop equivalent.
 *
 *****************************************************************************/


#include "transform_while.h"

#include "stdlib.h"
#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"

#include "memory.h"
#include "ctinfo.h"


/*
 * INFO structure
 */

struct INFO {
  int tempAmount;
  node* symboltable;
};

/*
 * INFO macros
 */

#define INFO_TEMP(n) ((n)->tempAmount)
#define INFO_CST(n) ((n)->symboltable)

/*
 * INFO functions
 */

static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_TEMP(result) = 0;
  INFO_CST(result) = NULL;

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

// Creates a symboltable, stores it in arg_info.
node* TWprogram(node* arg_node, info* arg_info) {

  DBUG_ENTER("TWprogram");

  INFO_CST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

// Transforms while-loops into dowhile-loops.
node* TWfundef(node* arg_node, info* arg_info) {

  DBUG_ENTER("TWfundef");

  INFO_CST(arg_info) = FUNDEF_SYMBOLTABLE(arg_node);

  if (INFO_CST(arg_info) && !STReq(SYMBOLTABLE_NAME(SYMBOLTABLE_PARENT(INFO_CST(arg_info))), "Global")) {
    char* name = SYMBOLTABLE_NAME(SYMBOLTABLE_PARENT(INFO_CST(arg_info)));
    if (STReq(SYMBOLTABLE_NAME(SYMBOLTABLE_PARENT(SYMBOLTABLE_PARENT(INFO_CST(arg_info)))), "Global"))  {
      name = STRcat("__", SYMBOLTABLE_NAME(SYMBOLTABLE_PARENT(INFO_CST(arg_info))));
    }   
    char* functionName = STRcat("_", FUNDEF_NAME(arg_node));
    FUNDEF_NAME(arg_node) = STRcat(name, functionName);
    SYMBOLTABLE_NAME(INFO_CST(arg_info)) = STRcpy(FUNDEF_NAME(arg_nod);

  } 

  // traverse through paramaters.
  FUNDEF_PARAMS(arg_node) = TRAVopt(FUNDEF_PARAMS(arg_node), arg_info);
  
  FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

  DBUG_RETURN(arg_node);
  
}

// Changes the while-loop into a dowhile-loop..
node *TWwhile( node* arg_node, info * arg_info) {

  DBUG_ENTER("TWwhile");

  arg_node = TBmakeDowhile(WHILE_COND(arg_node), WHILE_BLOCK(arg_node));

  DBUG_RETURN(arg_node);

}

/*
 * Traversal start function
 */

node *TWdoTransformWhile( node *syntaxtree)
{

  DBUG_ENTER("TWdoTransformWhile");

  info *arg_info = MakeInfo();

  TRAVpush( TR_tw);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
