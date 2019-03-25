/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.test.c                                  :+:    :+:            */
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

TEST(	test_equal,
		int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("foo", "foo", sizeof("foo")) == 0);
}

TEST(	test_not_equal_ascii,
		int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("foo0", "foo1", sizeof("foo0")) < 0);
	assert(strncmpf("foo5", "foo0", sizeof("foo5")) > 0);
}

TEST(	test_not_equal_non_ascii,
		int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("foo\x90", "foo\x91", sizeof("foo\x90")) < 0);
	assert(strncmpf("foo\x95", "foo\x90", sizeof("foo\x90")) > 0);
}

TEST(test_empty, int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("", "", 0) == 0);
	assert(strncmpf("", "", 1) == 0);
	assert(strncmpf("foo", "", 0) == 0);
	assert(strncmpf("foo", "", 5) > 0);
}

TEST(	test_n_short,
		int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("foo0", "foo1", 3) == 0);
}

TEST(	test_n_long,
		int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("foo0", "foo1", 10) < 0);
	assert(strncmpf("foo", "foo", 10) == 0);
}

TEST(	test_n_0,
		int strncmpf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strncmpf("foo", "bar", 0) == 0);
}

int		main(void)
{
	RUN2(test_equal, ft_strncmp, strncmp);
	RUN2(test_not_equal_ascii, ft_strncmp, strncmp);
	RUN2(test_not_equal_non_ascii, ft_strncmp, strncmp);
	RUN2(test_empty, ft_strncmp, strncmp);
	RUN2(test_n_short, ft_strncmp, strncmp);
	RUN2(test_n_long, ft_strncmp, strncmp);
	RUN2(test_n_0, ft_strncmp, strncmp);
}
