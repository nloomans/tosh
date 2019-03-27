/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 13:01:05 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(	test_equal,
		int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("foo", "foo", sizeof("foo")) == 1);
}

TEST(	test_not_equal_ascii,
		int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("foo0", "foo1", sizeof("foo0")) == 0);
	assert(strnequf("foo5", "foo0", sizeof("foo5")) == 0);
}

TEST(	test_not_equal_non_ascii,
		int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("foo\x90", "foo\x91", sizeof("foo\x90")) == 0);
	assert(strnequf("foo\x95", "foo\x90", sizeof("foo\x90")) == 0);
}

TEST(test_empty, int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("", "", 0) == 1);
	assert(strnequf("", "", 1) == 1);
	assert(strnequf("foo", "", 0) == 1);
	assert(strnequf("foo", "", 5) == 0);
}

TEST(	test_n_short,
		int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("foo0", "foo1", 3) == 1);
}

TEST(	test_n_long,
		int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("foo0", "foo1", 10) == 0);
	assert(strnequf("foo", "foo", 10) == 1);
}

TEST(	test_n_0,
		int strnequf(const char *s1, const char *s2, size_t n))
{
	PRINT();
	assert(strnequf("foo", "bar", 0) == 1);
}

int		main(void)
{
	RUN(test_equal, ft_strnequ);
	RUN(test_not_equal_ascii, ft_strnequ);
	RUN(test_not_equal_non_ascii, ft_strnequ);
	RUN(test_empty, ft_strnequ);
	RUN(test_n_short, ft_strnequ);
	RUN(test_n_long, ft_strnequ);
	RUN(test_n_0, ft_strnequ);
}
