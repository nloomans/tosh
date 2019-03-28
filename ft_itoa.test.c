/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:06:17 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/28 12:14:21 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>
#include <limits.h>

TEST(test_0, char *itoaf(int n))
{
	PRINT();
	assert(strcmp(itoaf(0), "0") == 0);
}

TEST(test_positive, char *itoaf(int n))
{
	PRINT();
	assert(strcmp(itoaf(1), "1") == 0);
	assert(strcmp(itoaf(10), "10") == 0);
	assert(strcmp(itoaf(101), "101") == 0);
	assert(strcmp(itoaf(9090), "9090") == 0);
	assert(strcmp(itoaf(164616), "164616") == 0);
}

TEST(test_negative, char *itoaf(int n))
{
	PRINT();
	assert(strcmp(itoaf(-1), "-1") == 0);
	assert(strcmp(itoaf(-10), "-10") == 0);
	assert(strcmp(itoaf(-101), "-101") == 0);
	assert(strcmp(itoaf(-9090), "-9090") == 0);
	assert(strcmp(itoaf(-164616), "-164616") == 0);
}

TEST(test_limits, char *itoaf(int n))
{
	PRINT();
	assert(strcmp(itoaf(INT_MAX), "2147483647") == 0);
	assert(strcmp(itoaf(INT_MIN), "-2147483648") == 0);
}

int		main(void)
{
	RUN(test_0, ft_itoa);
	RUN(test_positive, ft_itoa);
	RUN(test_negative, ft_itoa);
	RUN(test_limits, ft_itoa);
}
