/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, void *memsetf(void *b, int c, size_t len))
{
	PRINT();
	char dst[10];
	char dst_goal[] = { '@', '@', '@', '@', '@', '@', '@', '@', '@', '@' };
	
	assert(memsetf(dst, '@', sizeof(dst)) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

TEST(test_null, void *memsetf(void *b, int c, size_t len))
{
	PRINT();
	char dst[10];
	char dst_goal[] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	
	assert(memsetf(dst, '\0', sizeof(dst)) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

TEST(test_no_ascii, void *memsetf(void *b, int c, size_t len))
{
	PRINT();
	char dst[10];
	char dst_goal[] = { '\x9A', '\x9A', '\x9A', '\x9A', '\x9A', '\x9A', '\x9A', '\x9A', '\x9A', '\x9A' };
	
	assert(memsetf(dst, '\x9A', sizeof(dst)) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}



int		main(void)
{
	RUN2(test_basic, ft_memset, memset);
	RUN2(test_null, ft_memset, memset);
	RUN2(test_no_ascii, ft_memset, memset);
}
