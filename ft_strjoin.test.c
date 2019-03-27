/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 14:36:35 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 17:55:36 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, char *strjoinf(const char *s1, const char *s2))
{
	PRINT();
	assert(memcmp(strjoinf("foo", "bar"), "foobar", 3 /* foo */ + 3 /* bar */ + 1 /* \0 */) == 0);
}

TEST(test_no_s2, char *strjoinf(const char *s1, const char *s2))
{
	PRINT();
	assert(memcmp(strjoinf("foo", ""), "foo", 3 /* foo */ + 1 /* \0 */) == 0);
}


int		main(void)
{
	RUN(test_basic, ft_strjoin);
	RUN(test_no_s2, ft_strjoin);
}
