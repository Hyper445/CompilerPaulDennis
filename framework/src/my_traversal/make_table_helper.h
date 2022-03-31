#ifndef _MAKE_TABLE_HELPER_H_
#define _MAKE_TABLE_HELPER_H_

#include "types.h"

extern void addSymbol(char* name, type type, info* arg_info, node* params);
extern node* get_entry(char* name, node* current_ST);


#endif
