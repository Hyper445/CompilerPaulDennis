#ifndef _TYPE_CHECK_H_
#define _TYPE_CHECK_H_

#include "types.h"

extern node *TCprogram (node *arg_node, info *arg_info);
extern node *TCfundef (node *arg_node, info *arg_info);
extern node *TCbinop (node *arg_node, info *arg_info);
extern node *TCfuncall (node *arg_node, info *arg_info);
extern node *TCassign (node *arg_node, info *arg_info);
extern node *TCvardef (node *arg_node, info *arg_info);
extern node *TCvardecl (node *arg_node, info *arg_info);
extern node *TCglobdef (node *arg_node, info *arg_info);
extern node *TCnum (node *arg_node, info *arg_info);
extern node *TCfloat (node *arg_node, info *arg_info);
extern node *TCbool (node *arg_node, info *arg_info);
extern node *TCvar (node *arg_node, info *arg_info);
extern node *TCvarlet (node *arg_node, info *arg_info);
extern node *TCmonop (node *arg_node, info *arg_info);
extern node *TCcast (node *arg_node, info *arg_info);

extern node *TCdoTypeCheck( node *syntaxtree);

#endif
