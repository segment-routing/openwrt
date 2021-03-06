#ifndef _UAPI_LINUX_SEG6_GENL_H
#define _UAPI_LINUX_SEG6_GENL_H

#define SEG6_GENL_NAME		"SEG6"
#define SEG6_GENL_VERSION	0x1

enum {
	SEG6_ATTR_UNSPEC,
	SEG6_ATTR_DST,
	SEG6_ATTR_DSTLEN,
	SEG6_ATTR_SEGLISTID,
	SEG6_ATTR_FLAGS,
	SEG6_ATTR_HMACKEYID,
	SEG6_ATTR_SEGMENTS,
	SEG6_ATTR_SEGLEN,
	SEG6_ATTR_SEGINFO,
	SEG6_ATTR_SECRET,
	SEG6_ATTR_SECRETLEN,
	SEG6_ATTR_ALGID,
	SEG6_ATTR_HMACINFO,
	SEG6_ATTR_BIND_OP,
	SEG6_ATTR_BIND_DATA,
	SEG6_ATTR_BIND_DATALEN,
	SEG6_ATTR_BINDINFO,
	SEG6_ATTR_PACKET_DATA,
	SEG6_ATTR_PACKET_LEN,
	SEG6_ATTR_POLICY_DATA,
	SEG6_ATTR_POLICY_LEN,
	__SEG6_ATTR_MAX,
};

#define SEG6_ATTR_MAX (__SEG6_ATTR_MAX - 1)

enum {
	SEG6_CMD_UNSPEC,
	SEG6_CMD_SETHMAC,
	SEG6_CMD_DUMPHMAC,
	SEG6_CMD_ADDBIND,
	SEG6_CMD_DELBIND,
	SEG6_CMD_FLUSHBIND,
	SEG6_CMD_DUMPBIND,
	SEG6_CMD_PACKET_IN,
	SEG6_CMD_PACKET_OUT,
	SEG6_CMD_SET_TUNSRC,
	SEG6_CMD_GET_TUNSRC,
	__SEG6_CMD_MAX,
};

#define SEG6_CMD_MAX (__SEG6_CMD_MAX - 1)

/* Binding-SID Information Base */
#define SEG6_BIND_NEXT 0 /* aka no-op, classical sr processing */
#define SEG6_BIND_ROUTE 1 /* force route through given next hop */
#define SEG6_BIND_INSERT 2 /* push segments in srh */
#define SEG6_BIND_TRANSLATE 3 /* translate source/dst ? */
#define SEG6_BIND_SERVICE 4 /* send packet to virtual service */
#define SEG6_BIND_OVERRIDE_NEXT 5 /* override next segment (break HMAC) */

#define SEG6_BIND_FLAG_ASYM	0x01
#define SEG6_BIND_FLAG_OVERRIDE	0x02 /* remove current action if exist */

#endif
