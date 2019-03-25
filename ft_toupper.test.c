/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.test.c                                  :+:    :+:            */
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

TEST(test_from_upper, int toupperf(int c))
{
	PRINT();
	assert(toupperf('A') == 'A');
	assert(toupperf('F') == 'F');
	assert(toupperf('Z') == 'Z');
}

TEST(test_from_lower, int toupperf(int c))
{
	PRINT();
	assert(toupperf('a') == 'A');
	assert(toupperf('f') == 'F');
	assert(toupperf('z') == 'Z');
}

TEST(test_from_other, int toupperf(int c))
{
	PRINT();
	assert(toupperf('.') == '.');
	assert(toupperf('@') == '@');
	assert(toupperf('\0') == '\0');
	assert(toupperf('\x91') == '\x91');
}

int		main(void)
{
	RUN2(test_from_upper, ft_toupper, toupper);
	RUN2(test_from_lower, ft_toupper, toupper);
	RUN2(test_from_other, ft_toupper, toupper);
}
