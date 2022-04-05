#ifndef _MAKE_TABLE_HELPER_H_
#define _MAKE_TABLE_HELPER_H_

#include "types.h"

extern void addSymbol(char* name, type type, info* arg_info, node* params, bool isFunction);
extern node* get_entry(char* name, node* current_ST, bool isFunction);
extern node* get_entry_scope(char* name, node* current_ST, bool isFunction);
node* get_entry_node(node* stLink, node* current_ST, bool isFunction);




#endif
