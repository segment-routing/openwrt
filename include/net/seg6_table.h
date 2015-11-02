/*
 *  SR-IPv6 implementation
 *
 *  Author:
 *  David Lebrun <david.lebrun@uclouvain.be>
 *
 *
 *  This program is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU General Public License
 *      as published by the Free Software Foundation; either version
 *      2 of the License, or (at your option) any later version.
 */

#ifndef _NET_SEG6_TABLE_H
#define _NET_SEG6_TABLE_H

#include <net/flow.h>
#include <net/ip6_fib.h>
#include <net/sock.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/route.h>
#include <net/seg6.h>

struct s6ib_node {
	struct s6ib_node *children[2];
	struct s6ib_node *parent;

	struct seg6_info *s6info;

	u8 bit;
	u8 count;
};

struct s6ib_node *seg6_route_lookup(struct s6ib_node *root,
			struct in6_addr *addr);
struct s6ib_node *seg6_route_insert(struct s6ib_node *root,
			struct seg6_info *s6info);
int seg6_route_delete(struct s6ib_node *root, struct in6_addr *addr, int plen);

#endif
