
/**
 * @file free_node.h
 *
 * Functions to free node structures
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: copy_node.h.xsl 296 2008-02-26 01:52:31Z sah $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_COPY_NODE_H_
#define _SAC_COPY_NODE_H_

#include "types.h"

extern node    *COPYarrexpr(node * arg_node, info * arg_info);
extern node    *COPYassign(node * arg_node, info * arg_info);
extern node    *COPYbinop(node * arg_node, info * arg_info);
extern node    *COPYbool(node * arg_node, info * arg_info);
extern node    *COPYcast(node * arg_node, info * arg_info);
extern node    *COPYdecls(node * arg_node, info * arg_info);
extern node    *COPYdowhile(node * arg_node, info * arg_info);
extern node    *COPYerror(node * arg_node, info * arg_info);
extern node    *COPYexprstmt(node * arg_node, info * arg_info);
extern node    *COPYexprs(node * arg_node, info * arg_info);
extern node    *COPYfloat(node * arg_node, info * arg_info);
extern node    *COPYfor(node * arg_node, info * arg_info);
extern node    *COPYfunbody(node * arg_node, info * arg_info);
extern node    *COPYfuncall(node * arg_node, info * arg_info);
extern node    *COPYfundef(node * arg_node, info * arg_info);
extern node    *COPYfundefs(node * arg_node, info * arg_info);
extern node    *COPYglobdecl(node * arg_node, info * arg_info);
extern node    *COPYglobdef(node * arg_node, info * arg_info);
extern node    *COPYids(node * arg_node, info * arg_info);
extern node    *COPYifelse(node * arg_node, info * arg_info);
extern node    *COPYmonop(node * arg_node, info * arg_info);
extern node    *COPYnum(node * arg_node, info * arg_info);
extern node    *COPYparam(node * arg_node, info * arg_info);
extern node    *COPYprogram(node * arg_node, info * arg_info);
extern node    *COPYreturn(node * arg_node, info * arg_info);
extern node    *COPYstmts(node * arg_node, info * arg_info);
extern node    *COPYsymboltable(node * arg_node, info * arg_info);
extern node    *COPYsymboltableentry(node * arg_node, info * arg_info);
extern node    *COPYvar(node * arg_node, info * arg_info);
extern node    *COPYvardecl(node * arg_node, info * arg_info);
extern node    *COPYvarlet(node * arg_node, info * arg_info);
extern node    *COPYwhile(node * arg_node, info * arg_info);

#endif				/* _SAC_COPY_NODE_H_ */
