/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:07:46 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 12:33:09 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_basic, int isalphaf(int c))
{
	PRINT();
	assert(isalphaf('a'));
	assert(isalphaf('x'));
	assert(isalphaf('Y'));
	assert(!isalphaf('?'));
	assert(!isalphaf('\0'));
	assert(!isalphaf('!'));
}

int		main(void)
{
	RUN(test_basic, ft_isalpha, isalpha);
}
