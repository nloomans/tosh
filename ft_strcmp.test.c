/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/22 11:19:47 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_equal, int strcmpf(const char *s1, const char *s2))
{
	PRINT();
	assert(strcmpf("foo", "foo") == 0);
}

TEST(test_not_equal_ascii, int strcmpf(const char *s1, const char *s2))
{
	PRINT();
	assert(strcmpf("foo0", "foo1") < 0);
	assert(strcmpf("foo5", "foo0") > 0);
}

TEST(test_not_equal_non_ascii, int strcmpf(const char *s1, const char *s2))
{
	PRINT();
	assert(strcmpf("foo\x90", "foo\x91") < 0);
	assert(strcmpf("foo\x95", "foo\x90") > 0);
}

int		main(void)
{
	RUN(test_equal, ft_strcmp, strcmp);
	RUN(test_not_equal_ascii, ft_strcmp, strcmp);
	RUN(test_not_equal_non_ascii, ft_strcmp, strcmp);
}
