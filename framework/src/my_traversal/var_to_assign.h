#ifndef _VARIABLE_TO_ASSIGN_H_
#define _VARIABLE_TO_ASSIGN_H_

#include "types.h"

extern void addNodeStatements(node* stmt, node* funbody);
extern node *VAprogram (node *arg_node, info *arg_info);
extern node *VAfunbody (node *arg_node, info *arg_info);
extern node *VAdoVariableToAssign( node *syntaxtree);

#endif
