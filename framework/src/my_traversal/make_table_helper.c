#include "make_table.h"
#include "make_table_helper.h"

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
  type type;
  node* Symboltable;
};

/*
 * INFO macros
 */

#define INFO_ST(n) ((n)->Symboltable)
#define INFO_NEXT(n) ((n)->next)

void addSymbol(char* name, type type, info* arg_info, node* params, bool isFunction) {

  node* currentSymbolTable = INFO_ST(arg_info);
  node* currentSymbolEntry = SYMBOLTABLE_ENTRIES(currentSymbolTable);

  if (get_entry_scope(name, INFO_ST(arg_info), isFunction)) {
  
    CTIerror("%s is already declared!", name);

  }

  // Gets the correct nesting level.
  int nestinglevel = 0;
  while (SYMBOLTABLE_PARENT(currentSymbolTable) != NULL) {
    nestinglevel ++;
    currentSymbolTable = SYMBOLTABLE_PARENT(currentSymbolTable);
  }

  int indexlevel = 0;
  if (currentSymbolEntry) {
    indexlevel++;
    // Go to the last entry in the symbol table
    while (SYMBOLTABLEENTRY_NEXT(currentSymbolEntry) != NULL) {
      currentSymbolEntry = SYMBOLTABLEENTRY_NEXT(currentSymbolEntry);
      indexlevel++;
    }
    
    node* symbolEntry = TBmakeSymboltableentry(name, type, nestinglevel, indexlevel, params, isFunction, NULL);
    SYMBOLTABLEENTRY_NEXT(currentSymbolEntry) = symbolEntry;

  } else {

    node* symbolEntry = TBmakeSymboltableentry(name, type, nestinglevel, indexlevel, params, isFunction, NULL);
    SYMBOLTABLE_ENTRIES(INFO_ST(arg_info)) = symbolEntry;

  }

}

// Compare links when entry has already been added and link has been provided
node* get_entry_node(node* stLink, node* current_ST, bool isFunction) {

  // gets ST and it's first entry.
  // node* current_ST = INFO_ST(arg_info);
  node* current_ST_entry;
  
  // Loops through the symboltables until the function decleration has been found.
  while(current_ST != NULL) {
    current_ST_entry = SYMBOLTABLE_ENTRIES(current_ST);

    // loops through all entries at current nesting.
    while(current_ST_entry != NULL) {

      // If the decleration has been found. A link to the decleration is added to the funcall.
      if (stLink == current_ST_entry) {
        
        if (isFunction && SYMBOLTABLEENTRY_ISFUNCTION(current_ST_entry)) {
          return current_ST_entry;
        } else if (!isFunction && !SYMBOLTABLEENTRY_ISFUNCTION(current_ST_entry)) {
          return current_ST_entry;        
        }
      }

    current_ST_entry = SYMBOLTABLEENTRY_NEXT(current_ST_entry);
    }

    current_ST = SYMBOLTABLE_PARENT(current_ST);
  }

  return NULL;
}

// Get entry by name
node* get_entry(char* name, node* current_ST, bool isFunction) {

  // gets ST and it's first entry.
  // node* current_ST = INFO_ST(arg_info);
  node* current_ST_entry;
  
  // Loops through the symboltables until the function decleration has been found.
  while(current_ST != NULL) {
    current_ST_entry = SYMBOLTABLE_ENTRIES(current_ST);

    // loops through all entries at current nesting.
    while(current_ST_entry != NULL) {
      // If the decleration has been found. A link to the decleration is added to the funcall.
      if (STReq(name, SYMBOLTABLEENTRY_NAME(current_ST_entry))) {
        
        if (isFunction && SYMBOLTABLEENTRY_ISFUNCTION(current_ST_entry)) {
          return current_ST_entry;
        } else if (!isFunction && !SYMBOLTABLEENTRY_ISFUNCTION(current_ST_entry)) {
          return current_ST_entry;        
        }
      }

    current_ST_entry = SYMBOLTABLEENTRY_NEXT(current_ST_entry);
    }

    current_ST = SYMBOLTABLE_PARENT(current_ST);
  }
  return NULL;
}

// Check if entry is in the current scope
node* get_entry_scope(char* name, node* current_ST, bool isFunction) {

  // gets ST and it's first entry.
  // node* current_ST = INFO_ST(arg_info);
  node* current_ST_entry;
  
  // Loops through the symboltables until the function decleration has been found.
  while(current_ST != NULL) {
    current_ST_entry = SYMBOLTABLE_ENTRIES(current_ST);

    // loops through all entries at current nesting.
    while(current_ST_entry != NULL) {

      // If the decleration has been found. A link to the decleration is added to the funcall.
      if (STReq(name, SYMBOLTABLEENTRY_NAME(current_ST_entry))) {
        if (isFunction && SYMBOLTABLEENTRY_PARAMS(current_ST_entry) != NULL) {
          return current_ST_entry;
        } else if (!isFunction && SYMBOLTABLEENTRY_PARAMS(current_ST_entry) == NULL) {
          return current_ST_entry;        
        }
      }

    current_ST_entry = SYMBOLTABLEENTRY_NEXT(current_ST_entry);
    }

    current_ST = NULL;
  }

  return NULL;
}