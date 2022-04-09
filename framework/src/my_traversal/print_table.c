/*****************************************************************************
 *
 * Module: enter_symbol_table
 *
 * Prefix: EST
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "print_table.h"
#include "make_table_helper.h"
#include "print.h"

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
  node* Symboltable;
};

/*
 * INFO macros
 */

#define INFO_ST(n) ((n)->Symboltable)
#define INFO_NEXT(n) ((n)->next)

/*
 * INFO functions
 */

static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_ST(result) = NULL;

  DBUG_RETURN( result);
}

/*
 * Traversal functions
 */

// Prints the symboltable.
node *PTsymboltable (node *arg_node, info *arg_info) {
  DBUG_ENTER("PTsymboltable");

  printf("=== %s ===\n", SYMBOLTABLE_NAME(arg_node));
  SYMBOLTABLE_ENTRIES(arg_node) = TRAVopt(SYMBOLTABLE_ENTRIES(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

// Prints a symboltableEntry.
node *PTsymboltableentry (node *arg_node, info *arg_info) {
  DBUG_ENTER("PTsymboltableentry");

  printf("  %s ", SYMBOLTABLEENTRY_NAME(arg_node));
  if (SYMBOLTABLEENTRY_ISFUNCTION(arg_node)) {
    printf("with params: ");
    node* param = SYMBOLTABLEENTRY_PARAMS(arg_node);
    while (param) {
      printf("%s ", PARAM_NAME(param));
      param = PARAM_NEXT(param);
    }

  }
  printf("\n");
  SYMBOLTABLEENTRY_NEXT(arg_node) = TRAVopt(SYMBOLTABLEENTRY_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

/*
 * Traversal start function
 */

node *PTdoPrintTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("PTdoPrintTable");

  arg_info = MakeInfo();

  TRAVpush( TR_pt);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
