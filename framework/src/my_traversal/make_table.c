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


#include "make_table.h"

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
  node* self;
  node* next;
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
  INFO_NEXT(result) = NULL;

  DBUG_RETURN( result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}

void addSymbol(char* name, type type, info* arg_info) {

  int nestinglevel = 0;
  node* currentSymbolEntry = INFO_NEXT(arg_info);

  if (currentSymbolEntry) {
    // Go to the last entry in the symbol table
    while (SYMBOLTABLEENTRY_NEXT(currentSymbolEntry) != NULL) {
      nestinglevel++;
      currentSymbolEntry = SYMBOLTABLEENTRY_NEXT(currentSymbolEntry);
    }
    
    node* symbolEntry = TBmakeSymboltableentry(name, type, nestinglevel, NULL);
    SYMBOLTABLEENTRY_NEXT(currentSymbolEntry) = symbolEntry;

  } else {

    node* symbolEntry = TBmakeSymboltableentry(name, type, nestinglevel, NULL);
    INFO_NEXT(arg_info) = symbolEntry;

  }
}


/*
 * Traversal functions
 */

node *MTprogram (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTprogram");

  printf("Test33333");

  //INFO_ST(arg_info) = TBmakeSymboltable("Global", NULL);
  if (PROGRAM_DECLS(arg_node) == NULL) {
    printf("\nis null!! \n\n");
  } else {

    switch (NODE_TYPE(DECLS_DECL(PROGRAM_DECLS(arg_node))))
    {
      case N_fundef:
        printf("fundef");
        break;
      
      case N_globdecl:
        printf("globdecl");
        break;

      case N_globdef:
        printf("def");
        break;
    }
  }

  DBUG_RETURN(arg_node);
  
}

node *MTfundef (node *arg_node, info *arg_info){
  
  DBUG_ENTER("MTfundef");
  
  printf("Test123");

  // When reaching a function definition, add this to the current symbol table
  char* name = FUNDEF_NAME(arg_node);
  type type = FUNDEF_TYPE(arg_node);
  addSymbol(name, type, arg_info);

  node* current_table = INFO_ST(arg_info);

  // Then create a new symbol table for the function.
  INFO_ST(arg_info) = TBmakeSymboltable(name, NULL);

  // Add the params to the new symbol table
  if (FUNDEF_PARAMS(arg_node)) {
    node* current_param = FUNDEF_PARAMS(arg_node);
    while (current_param) {
      name = PARAM_NAME(current_param);
      type = PARAM_TYPE(current_param);
      addSymbol(name, type, arg_info);
      current_param = PARAM_NEXT(current_param); 
    }
  }

  // If the function has a body, traverse the funbody with the new table
  //FUNDEF_FUNBODY(arg_node) = TRAVopt(arg_node, arg_info);

  // Maak nieuwe symbol table --> Sla daar params en alle variabelen in de funbody op.


  DBUG_RETURN(arg_node);
  
}

node *MTglobdecl (node *arg_node, info *arg_info) {

  DBUG_ENTER("MTglobdecl");

  char* name = GLOBDECL_NAME(arg_node);
  type type = GLOBDECL_TYPE(arg_node);
  addSymbol(name, type, arg_info);

  printf("Entering symbol %s in symbol table with the name: %s \n", name, SYMBOLTABLE_NAME(INFO_ST(arg_info)));
  
  DBUG_RETURN(arg_node);
  
}
node *MTglobdef (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTglobdef");

  char* name = GLOBDEF_NAME(arg_node);
  type type = GLOBDEF_TYPE(arg_node);
  addSymbol(name, type, arg_info);
  
  printf("Entering symbol %s in symbol table with the name: %s \n", name, SYMBOLTABLE_NAME(INFO_ST(arg_info)));

  DBUG_RETURN(arg_node);

}


node *MTvardecl (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTvardecl");

  char* name = VARDECL_NAME(arg_node);
  type type = VARDECL_TYPE(arg_node);
  addSymbol(name, type, arg_info);

  printf("Entering symbol %s in symbol table with the name: %s \n", name, SYMBOLTABLE_NAME(INFO_ST(arg_info)));

  DBUG_RETURN(arg_node);
  
  }

node * MTvar(node *arg_node, info *arg_info) {

  DBUG_ENTER("MTvar");

  printf("Hoi\n");

  DBUG_RETURN(arg_node);

}


/*
 * Traversal start function
 */

node *MTdoMakeTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("MTdoMakeTable");

  printf("test");

  arg_info = MakeInfo();

  TRAVpush( TR_mt);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
