/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 15:50:48 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 16:06:21 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, char *strtrimf(const char *s))
{
	PRINT();
	assert(strcmp(strtrimf("foo"), "foo") == 0);
	assert(strcmp(strtrimf(" foo"), "foo") == 0);
	assert(strcmp(strtrimf("foo "), "foo") == 0);
	assert(strcmp(strtrimf(" foo "), "foo") == 0);
	assert(strcmp(strtrimf("\n foo\n\t"), "foo") == 0);
	assert(strcmp(strtrimf("foo\n"), "foo") == 0);
	assert(strcmp(strtrimf(""), "") == 0);
	assert(strcmp(strtrimf(" "), "") == 0);
	assert(strcmp(strtrimf("   \t   \n"), "") == 0);
	assert(strcmp(strtrimf("foo\v"), "foo\v") == 0);
	assert(strcmp(strtrimf("foo bar"), "foo bar") == 0);
}

int		main(void)
{
	RUN(test_basic, ft_strtrim);
}
