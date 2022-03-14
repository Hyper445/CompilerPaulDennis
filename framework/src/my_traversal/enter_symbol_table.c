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


#include "identifiers_storer.h"

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
  lut_t* lut;
};

struct idval {
  char* id;
  int val;
};


/*
 * INFO macros
 */

#define INFO_LUT(n) ((n)->lut)
#define IDVAL_ID(n) ((n)->id)
#define IDVAL_VAL(n) ((n)->val)


/*
 * INFO functions
 */

static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_LUT(result) = LUTgenerateLut();

  DBUG_RETURN( result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  INFO_LUT(info) = LUTremoveLut(INFO_LUT(info));
  info = MEMfree( info);

  DBUG_RETURN( info);
}



// Makes and inserts a struct if identifier isn't in the LUT, updates LUT if it is.
void UpdateCurrentLUT(char* identifier, void** value, info* arg_info) {

  if (value != NULL) {
    ((struct idval *)*value)->val += 1;

    LUTupdateLutS(INFO_LUT(arg_info), identifier, *value, value);

  } else {
    struct idval* idval = MakeIdval();
    idval->id = identifier;
    
    INFO_LUT(arg_info) = LUTinsertIntoLutS(INFO_LUT(arg_info), identifier, idval);

  }
}


/*
 * Traversal functions
 */

node *ISvar (node *arg_node, info *arg_info) {
	
	DBUG_ENTER("ISvar");

  char* identifier = STRcpy(VAR_NAME(arg_node));
  void** value = LUTsearchInLutS(INFO_LUT(arg_info), identifier);

  UpdateCurrentLUT(identifier, value, arg_info);

  // /* Return value */
	DBUG_RETURN(arg_node);
}


node *ISvarlet (node *arg_node, info *arg_info) {
	
	DBUG_ENTER("ISvarlet");

  char* identifier = STRcpy(VARLET_NAME(arg_node));
  void** value = LUTsearchInLutS(INFO_LUT(arg_info), identifier);

  UpdateCurrentLUT(identifier, value, arg_info);

  // /* Return value */
	DBUG_RETURN(arg_node);
}

/*
 * Traversal start function
 */

void* print(void* x) {
  printf("%d = amount of %s's\n", ((struct idval *)x)->val, ((struct idval *)x)->id);
  FreeIdval(x);
  return NULL;
}

node *ESTdoEnterSymbolTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("ESTdoEnterSymbolTable");

  arg_info = MakeInfo();

  TRAVpush( TR_est);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  INFO_LUT(arg_info) = LUTmapLutS(INFO_LUT(arg_info), print);
  if (INFO_LUT(arg_info)) FreeInfo( arg_info);

  DBUG_RETURN( syntaxtree);
}
