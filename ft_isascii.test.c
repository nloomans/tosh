/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:07:46 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 12:53:56 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_basic, int isasciif(int c))
{
	PRINT();
	assert(isasciif('\n'));
	assert(isasciif('a'));
	assert(isasciif('4'));
	assert(isasciif('@'));
	assert(isasciif('\0'));
	assert(!isasciif('\x80'));
	assert(!isasciif('\x95'));
	assert(!isasciif('\xF4'));
}

int		main(void)
{
	RUN(test_basic, ft_isascii, isascii);
}
