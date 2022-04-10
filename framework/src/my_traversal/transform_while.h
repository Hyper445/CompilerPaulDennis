#ifndef _TRANSFORM_WHILE_H_
#define _TRANSFORM_WHILE_H_

#include "types.h"

extern node *TWprogram (node *arg_node, info *arg_info);
extern node *TWfundef (node *arg_node, info *arg_info);
extern node *TWwhile (node *arg_node, info *arg_info);
extern node *TWdoTransformWhile( node *syntaxtree);

#endif
