#ifndef _CODE_GENERATION_H_
#define _CODE_GENERATION_H_

#include "types.h"

// extern node *MTprogram (node *arg_node, info *arg_info);
extern node *CGprogram (node *arg_node, info *arg_info);
extern node *CGfundef (node *arg_node, info *arg_info);
extern node *CGassign (node *arg_node, info *arg_info);
extern node *CGbinop (node *arg_node, info *arg_info);
extern node *CGvar (node *arg_node, info *arg_info);
extern node *CGnum (node *arg_node, info *arg_info);
extern node *CGfloat (node *arg_node, info *arg_info);
extern node *CGdoCodeGeneration( node *syntaxtree);



#endif