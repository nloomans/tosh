/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:26:49 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/23 16:41:04 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, void *memcpyf(void *dst, const void *src, size_t n))
{
	PRINT();
	char src[] = "Hello, World!";
	char dst[sizeof(src)];

	assert(memcpyf(dst, src, sizeof(src)) == dst);
	assert(memcmp(src, dst, sizeof(src)) == 0);
}

TEST(test_n_0, void *memcpyf(void *dst, const void *src, size_t n))
{
	PRINT();
	char src[] = "foo";
	char dst[] = "bar";
	
	assert(memcpyf(dst, src, 0) == dst);
	assert(memcmp(dst, "bar", sizeof(dst)) == 0);	
}

int		main(void)
{
	RUN(test_basic, ft_memcpy, memcpy);
	RUN(test_n_0, ft_memcpy, memcpy);
}
