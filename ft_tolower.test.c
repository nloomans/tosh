/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 10:50:15 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_from_upper, int tolowerf(int c))
{
	PRINT();
	assert(tolowerf('A') == 'a');
	assert(tolowerf('F') == 'f');
	assert(tolowerf('Z') == 'z');
}

TEST(test_from_lower, int tolowerf(int c))
{
	PRINT();
	assert(tolowerf('a') == 'a');
	assert(tolowerf('f') == 'f');
	assert(tolowerf('z') == 'z');
}

TEST(test_from_other, int tolowerf(int c))
{
	PRINT();
	assert(tolowerf('.') == '.');
	assert(tolowerf('@') == '@');
	assert(tolowerf('\0') == '\0');
	assert(tolowerf('\x91') == '\x91');
}

int		main(void)
{
	RUN2(test_from_upper, ft_tolower, tolower);
	RUN2(test_from_lower, ft_tolower, tolower);
	RUN2(test_from_other, ft_tolower, tolower);
}
