/**
 * @file net.c Network Testcode
 */
#include <re.h>
#include "test.h"


#define DEBUG_MODULE "test_net"
#define DEBUG_LEVEL 5
#include <re_dbg.h>


int test_net_dst_source_addr_get(void)
{
	struct sa dst;
	struct sa ip;
	int err;

	sa_init(&dst, AF_INET);
	sa_init(&ip, AF_UNSPEC);

	sa_set_str(&dst, "127.0.0.1", 53);

	err = net_dst_source_addr_get(&dst, &ip);
	if (err)
		return err;

	TEST_ASSERT(sa_is_loopback(&ip));

	sa_init(&dst, AF_INET6);
	sa_init(&ip, AF_UNSPEC);
	sa_set_str(&dst, "::1", 53);

	err = net_dst_source_addr_get(&dst, &ip);
	if (err)
		return err;

	TEST_ASSERT(sa_is_loopback(&ip));

out:
	return err;
}
