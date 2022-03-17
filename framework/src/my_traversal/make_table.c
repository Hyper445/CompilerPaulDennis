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

  INFO_ST(result) = TBmakeSymboltable("Global", NULL, NULL);

  DBUG_RETURN( result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}

void addSymbol(char* name, type type, info* arg_info) {

  node* currentSymbolTable = INFO_ST(arg_info);
  node* currentSymbolEntry = SYMBOLTABLE_ENTRIES(currentSymbolTable);

  // Gets the correct nesting level.
  int nestinglevel = 0;
  while (SYMBOLTABLE_PARENT(currentSymbolTable) != NULL) {
    nestinglevel ++;
    currentSymbolTable = SYMBOLTABLE_PARENT(currentSymbolTable);
  }

  if (currentSymbolEntry) {
    // Go to the last entry in the symbol table
    while (SYMBOLTABLEENTRY_NEXT(currentSymbolEntry) != NULL) {
      currentSymbolEntry = SYMBOLTABLEENTRY_NEXT(currentSymbolEntry);
    }
    
    node* symbolEntry = TBmakeSymboltableentry(name, type, nestinglevel, NULL);
    SYMBOLTABLEENTRY_NEXT(currentSymbolEntry) = symbolEntry;

  } else {

    node* symbolEntry = TBmakeSymboltableentry(name, type, nestinglevel, NULL);
    SYMBOLTABLE_ENTRIES(INFO_ST(arg_info)) = symbolEntry;

  }

  printf("Symbol %s \t, nesting %d \t-> tabel %s \n", name, nestinglevel, SYMBOLTABLE_NAME(INFO_ST(arg_info)));

}

node* get_entry(char* name, info* arg_info) {
  DBUG_ENTER("addLink");

  // gets ST and it's first entry.
  node* current_ST = INFO_ST(arg_info);
  node* current_ST_entry;

  // Loops through the symboltables until the function decleration has been found.
  while(current_ST != NULL) {
    current_ST_entry = SYMBOLTABLE_ENTRIES(current_ST);
    // loops through all entries at current nesting.
    while(current_ST_entry != NULL) {
      // If the decleration has been found. A link to the decleration is added to the funcall.
      if (STReq(name, SYMBOLTABLEENTRY_NAME(current_ST_entry))) {
        return current_ST_entry;
      }

    current_ST_entry = SYMBOLTABLEENTRY_NEXT(current_ST_entry);
    }

  current_ST = SYMBOLTABLE_PARENT(current_ST);
  }

  return NULL;
}

/*
 * Traversal functions
 */

node *MTifelse (node *arg_node, info *arg_info) {
  DBUG_ENTER("MTifelse");

  char* name = "ifelse";

  node* parent_table = INFO_ST(arg_info);

  // Creates new scope. Current scope stored in arg_info is set to this new scope
  INFO_ST(arg_info) = TBmakeSymboltable(name, NULL, parent_table);

  // Traverse through both the 'then' and 'else' block.
  IFELSE_THEN(arg_node) = TRAVopt(IFELSE_THEN(arg_node), arg_info);
  IFELSE_ELSE(arg_node) = TRAVopt(IFELSE_ELSE(arg_node), arg_info);

  // The scope in arg_info is set back to the scope of the parent.
  INFO_ST(arg_info) = parent_table;

  DBUG_RETURN(arg_node);
}

node *MTfundef (node *arg_node, info *arg_info){
  
  DBUG_ENTER("MTfundef");
  
  // When reaching a function definition, add this to the current symbol table
  char* name = FUNDEF_NAME(arg_node);
  type type = FUNDEF_TYPE(arg_node);
  addSymbol(name, type, arg_info);

  node* parent_table = INFO_ST(arg_info);

  // Then create a new symbol table for the function.
  INFO_ST(arg_info) = TBmakeSymboltable(name, NULL, parent_table);

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

  //If the function has a body, traverse the funbody with the new table
  FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

  INFO_ST(arg_info) = parent_table;

  DBUG_RETURN(arg_node);
  
}

node *MTglobdecl (node *arg_node, info *arg_info) {

  DBUG_ENTER("MTglobdecl");

  char* name = GLOBDECL_NAME(arg_node);
  type type = GLOBDECL_TYPE(arg_node);
  addSymbol(name, type, arg_info);
  
  DBUG_RETURN(arg_node);
  
}

node *MTglobdef (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTglobdef");

  char* name = GLOBDEF_NAME(arg_node);
  type type = GLOBDEF_TYPE(arg_node);
  addSymbol(name, type, arg_info);

  DBUG_RETURN(arg_node);

}

node *MTvardecl (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTvardecl");

  char* name = VARDECL_NAME(arg_node);
  type type = VARDECL_TYPE(arg_node);
  addSymbol(name, type, arg_info);

  VARDECL_INIT(arg_node) = TRAVopt(VARDECL_INIT(arg_node), arg_info);

  VARDECL_NEXT(arg_node) = TRAVopt(VARDECL_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
  
  }

// For every function call, a link is added to the function's decleration.
node *MTfuncall(node *arg_node, info *arg_info) {
  DBUG_ENTER("MTfuncall");

  char* name = FUNCALL_NAME(arg_node);
  node* ST_entry = get_entry(name, arg_info);
  
  if(ST_entry != NULL) {
    FUNCALL_DECL(arg_node) = ST_entry;
    printf("link added from %s\t to %s \t with nesting %d\n", name, SYMBOLTABLEENTRY_NAME(ST_entry), SYMBOLTABLEENTRY_NESTINGLEVEL(ST_entry));
  }
  else {
    // If decleration was not found, an error is thrown.
    CTIerror("funcall %s is not in scope\n", name);
  }

  // Traverse through the arguments of the function.
  FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

// For every varlet, a link is added to the varlet's decleration
node *MTvarlet(node *arg_node, info *arg_info) {
  DBUG_ENTER("MTvarlet");

  char* name = VARLET_NAME(arg_node);
  node* ST_entry = get_entry(name, arg_info);

  if(ST_entry != NULL) {
    VARLET_DECL(arg_node) = ST_entry;
    printf("link added from %s\t to %s \t with nesting %d\n", name, SYMBOLTABLEENTRY_NAME(ST_entry), SYMBOLTABLEENTRY_NESTINGLEVEL(ST_entry));
  }
  else {
    // If decleration was not found, an error is thrown.
    CTIerror("varlet %s is not in scope\n", name);
  }

  DBUG_RETURN(arg_node);
}

node *MTvar(node *arg_node, info *arg_info) {
  DBUG_ENTER("MTvar");
  
  char* name = VAR_NAME(arg_node);
  node* ST_entry = get_entry(name, arg_info);

  if(ST_entry != NULL) {
    VAR_DECL(arg_node) = ST_entry;
    printf("link added from %s\t to %s \t with nesting %d\n", name, SYMBOLTABLEENTRY_NAME(ST_entry), SYMBOLTABLEENTRY_NESTINGLEVEL(ST_entry));
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

node *MTdoMakeTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("MTdoMakeTable");

  arg_info = MakeInfo();

  TRAVpush( TR_mt);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
