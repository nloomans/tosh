/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:07:46 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 12:43:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_basic, int isalnumf(int c))
{
	PRINT();
	assert(isalnumf('a'));
	assert(isalnumf('Z'));
	assert(isalnumf('5'));
	assert(!isalnumf('@'));
	assert(!isalnumf('.'));
	assert(!isalnumf('\0'));
}

int		main(void)
{
	RUN(test_basic, ft_isalnum, isalnum);
}
