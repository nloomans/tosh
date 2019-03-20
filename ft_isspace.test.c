/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:07:46 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 18:13:04 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_basic, int isspacef(int c))
{
	PRINT();
	assert(isspacef(' '));
	assert(isspacef('\t'));
	assert(isspacef('\v'));
	assert(!isspacef('h'));
	assert(!isspacef('4'));
	assert(!isspacef('\0'));
}

int		main(void)
{
	RUN(test_basic, ft_isspace, isspace);
}