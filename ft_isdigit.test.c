/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.test.c                                  :+:    :+:            */
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

TEST(test_basic, int isdigitf(int c))
{
	PRINT();
	assert(isdigitf('0'));
	assert(isdigitf('5'));
	assert(isdigitf('9'));
	assert(!isdigitf('a'));
	assert(!isdigitf('\0'));
	assert(!isdigitf('!'));
}

int		main(void)
{
	RUN2(test_basic, ft_isdigit, isdigit);
}
