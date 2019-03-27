/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 12:56:31 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_equal, int strequf(const char *s1, const char *s2))
{
	PRINT();
	assert(strequf("foo", "foo") == 1);
}

TEST(test_not_equal_ascii, int strequf(const char *s1, const char *s2))
{
	PRINT();
	assert(strequf("foo0", "foo1") == 0);
	assert(strequf("foo5", "foo0") == 0);
}

TEST(test_not_equal_non_ascii, int strequf(const char *s1, const char *s2))
{
	PRINT();
	assert(strequf("foo\x90", "foo\x91") == 0);
	assert(strequf("foo\x95", "foo\x90") == 0);
}

TEST(test_empty, int strequf(const char *s1, const char *s2))
{
	PRINT();
	assert(strequf("", "") == 1);
	assert(strequf("foo", "") == 0);
}

int		main(void)
{
	RUN(test_equal, ft_strequ);
	RUN(test_not_equal_ascii, ft_strequ);
	RUN(test_not_equal_non_ascii, ft_strequ);
	RUN(test_empty, ft_strequ);
}
