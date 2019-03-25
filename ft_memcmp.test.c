/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 12:02:44 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:25:37 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_equal, int memcmpf(const  void *s1, const void *s2, size_t n))
{
	PRINT();
	assert(memcmpf("foo", "foo", sizeof("foo")) == 0);
}

TEST(test_not_equal_ascii, int memcmpf(const  void *s1, const void *s2, size_t n))
{
	PRINT();
	assert(memcmpf("foo0", "foo1", sizeof("foo@")) < 0);
	assert(memcmpf("foo5", "foo0", sizeof("foo@")) > 0);
}

TEST(test_not_equal_non_ascii, int memcmpf(const  void *s1, const void *s2, size_t n))
{
	PRINT();
	assert(memcmpf("foo\x90", "foo\x91", sizeof("foo@")) < 0);
	assert(memcmpf("foo\x95", "foo\x90", sizeof("foo@")) > 0);
}

TEST(test_empty, int memcmpf(const  void *s1, const void *s2, size_t n))
{
	PRINT();
	assert(memcmpf("", "", 0) == 0);
	assert(memcmpf("foo", "", 0) == 0);
	assert(memcmpf("foo", "", 1) > 0);
}

int		main(void)
{
	RUN2(test_equal, ft_memcmp, memcmp);
	RUN2(test_not_equal_ascii, ft_memcmp, memcmp);
	RUN2(test_not_equal_non_ascii, ft_memcmp, memcmp);
	RUN2(test_empty, ft_memcmp, memcmp);
}
