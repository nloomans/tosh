/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:26:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 20:09:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <limits.h>

#define TEST(fmt, ...) do { \
	printf("-- Test for >> %s", fmt);\
	int res = printf(fmt, __VA_ARGS__);\
	int res2 = ft_printf(fmt, __VA_ARGS__);\
	printf("printf returned <%d>, ft_printf returned <%d>\n", res, res2); \
} while (0)

int	main(void)
{
	TEST("The number is %-5d!\n", 42);
	TEST("The number is %5d!\n", 42);
	TEST("The number is %-5.3d!\n", 42);
	TEST("The number is %5.3d!\n", 42);
	TEST("The number is %10.0d!\n", 42);
	TEST("The number is %0.10d!\n", 42);
	TEST("The number is %-99d!\n", 42);
	TEST("The number is %ld\n", -5234L);
	return (0);
}
