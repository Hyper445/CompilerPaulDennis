/*****************************************************************************
 *
 * Module: make_export_table
 *
 * Prefix: MET
 *
 * Description:
 *
 * This module implements creates an export table
 *
 *****************************************************************************/


#include "make_constant_table.h"

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
  node* exportfun;
  node* externfun;
  int int_result;
  float float_result;
};



/*
 * INFO macros
 */

#define INFO_E(n) ((n)->exportfun)
#define INFO_EXT(n) ((n)->externfun)
#define INFO_INT(n) ((n)->int_result)
#define INFO_FLOAT(n) ((n)->float_result)


/*
 * INFO functions
 */


static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_E(result) = NULL;
  INFO_EXT(result) = NULL;

  DBUG_RETURN( result);
}

/*
 * Traversal functions
 */

void addExport(node* arg_node, info* arg_info) {
  
  int index = 0;
  if (INFO_E(arg_info)) {
    node* current_export = INFO_E(arg_info);
    node* previous_export = current_export;
    while (current_export) {
      index++;
      previous_export = current_export;
      current_export = EXPORT_NEXT(current_export);
      
    }

    EXPORT_NEXT(previous_export) = TBmakeExport(index, arg_node, NULL);

  } else {
    INFO_E(arg_info) = TBmakeExport(index, arg_node, NULL);
  }

}

void addExtern(node* arg_node, info* arg_info) {
  
  int index = 0;
  if (INFO_EXT(arg_info)) {
    node* current_extern = INFO_EXT(arg_info);
    node* previous_extern = current_extern;
    while (current_extern) {
      index++;
      previous_extern = current_extern;
      current_extern = EXTERN_NEXT(current_extern);
      
    }
    EXTERN_NEXT(previous_extern) = TBmakeExtern(index, arg_node, NULL);

  } else {
    INFO_EXT(arg_info) = TBmakeExtern(index, arg_node, NULL);
  }

}


node* METprogram(node *arg_node, info *arg_info) {

  DBUG_ENTER("MCTprogram");

  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);
  //PROGRAM_CONSTANTTABLE(arg_node) = INFO_C(arg_info);
  PROGRAM_EXPORTTABLE(arg_node) = INFO_E(arg_info);
  PROGRAM_EXTERNTABLE(arg_node) = INFO_EXT(arg_info);

  DBUG_RETURN(arg_node);
}


node* METfundef (node* arg_node, info* arg_info) {


    DBUG_ENTER("METfundef");

    if (FUNDEF_ISEXPORT(arg_node)) {
        addExport(arg_node, arg_info);
    } else if (FUNDEF_ISEXTERN(arg_node)) {
        addExtern(arg_node, arg_info);
    }

    DBUG_RETURN(arg_node);
}




/*
 * Traversal start function
 */

node *METdoMakeExportTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("METdoMakeeExportTable(");

  arg_info = MakeInfo();

  TRAVpush( TR_met);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
