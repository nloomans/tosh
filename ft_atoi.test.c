/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:39:53 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 19:11:13 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "test_macros.h"

TEST(test_basic, int atoif(const char *str))
{
	PRINT();
	assert(atoif("42") == 42);
	assert(atoif("+42") == 42);
	assert(atoif("-42") == -42);
}

TEST(test_tricky, int atoif(const char *str))
{
	PRINT();
	assert(atoif("\t  +42hello") == 42);
	assert(atoif("\t  +42\n42") == 42);
	assert(atoif("0") == 0);
}

TEST(test_invalid, int atoif(const char *str))
{
	PRINT();
	assert(atoif("++42") == 0);
	assert(atoif("+-42") == 0);
	assert(atoif("-+42") == 0);
	assert(atoif("--42") == 0);
	assert(atoif("+ 42") == 0);
	assert(atoif("") == 0);
	assert(atoif("h42") == 0);
}

int main(void)
{
	RUN(test_basic, ft_atoi, atoi);
	RUN(test_tricky, ft_atoi, atoi);
	RUN(test_invalid, ft_atoi, atoi);
}
