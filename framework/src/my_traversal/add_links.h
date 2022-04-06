#ifndef _ADD_LINKS_H_
#define _ADD_LINKS_H_

#include "types.h"

extern node *ALprogram (node *arg_node, info *arg_info);
extern node *ALfundef (node *arg_node, info *arg_info);
extern node *ALglobdecl (node *arg_node, info *arg_info);
extern node *ALglobdef (node *arg_node, info *arg_info);
extern node *ALvardecl (node *arg_node, info *arg_info);
extern node *ALvarlet (node *arg_node, info *arg_info);
extern node *ALvar (node *arg_node, info *arg_info);
extern node *ALfuncall (node *arg_node, info *arg_info);

extern node *ALdoAddLinks (node *syntaxtree);

#endif
