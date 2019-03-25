/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:07:46 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_basic, int isprintf(int c))
{
	PRINT();
	assert(isprintf(' '));
	assert(isprintf('~'));
	assert(isprintf('@'));
	assert(!isprintf('\n'));
	assert(!isprintf('\r'));
	assert(!isprintf('\0'));
}

int		main(void)
{
	RUN2(test_basic, ft_isprint, isprint);
}
