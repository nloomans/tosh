/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsequ.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 15:50:48 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 16:06:11 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, char *strstrimf(const char *s))
{
	PRINT();
	assert(strcmp(strstrimf("foo"), "foo") == 0);
	assert(strcmp(strstrimf(" foo"), "foo") == 0);
	assert(strcmp(strstrimf("foo "), "foo") == 0);
	assert(strcmp(strstrimf(" foo "), "foo") == 0);
	assert(strcmp(strstrimf("\n foo\n\t"), "foo") == 0);
	assert(strcmp(strstrimf("foo\n"), "foo") == 0);
	assert(strcmp(strstrimf(""), "") == 0);
	assert(strcmp(strstrimf(" "), "") == 0);
	assert(strcmp(strstrimf("   \t   \n"), "") == 0);
	assert(strcmp(strstrimf("foo\v"), "foo") == 0);
	assert(strcmp(strstrimf("foo bar"), "foo bar") == 0);
}

int		main(void)
{
	RUN(test_basic, ft_strstrim);
}
