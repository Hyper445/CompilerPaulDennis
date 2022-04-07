#ifndef _RESTRUCTURE_FORLOOP_H_
#define _RESTRUCTURE_FORLOOP_H_

#include "types.h"

extern node *RFfundef (node *arg_node, info *arg_info);
extern node *RFvar (node *arg_node, info *arg_info);
extern node *RFvarlet (node *arg_node, info *arg_info);
extern node *RFfor (node *arg_node, info *arg_info);
extern node *RFdoRestructureForLoop( node *syntaxtree);

#endif
