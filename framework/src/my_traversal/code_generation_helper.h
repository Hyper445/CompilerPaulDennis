#ifndef _CODE_GENERATION_HELPER_H_
#define _CODE_GENERATION_HELPER_H_

#include "types.h"

extern node* in_table(node* value_node, node* constant_table);
extern char* type_to_char(int type);
extern char* type_to_string(int type);
extern char* binop_to_char(binop binop);
extern void print_constants(node* constant);
extern void print_funs(node* symbolTable);
extern void print_globals(node* symbolTable);
extern char* optimise_constant(node* arg_node);
extern int optimise_assign(node *arg_node, node *constant_table);
extern void write_assembly(char *assembly);

//TODO: monop to char


#endif