/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:26:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 01:39:03 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define TEST(fmt, ...) do { \
	printf("-- Test for >> %s", fmt);\
	int res = printf(fmt, __VA_ARGS__);\
	int res2 = ft_printf(fmt, __VA_ARGS__);\
	printf("printf returned <%d>, ft_printf returned <%d>\n", res, res2);\
} while (0)

#define LEN 64
#define MCMPARE(fmt, ...) do { \
	const char buff[LEN] = {};\
	int res = snprintf(buff, LEN, (char*)fmt, __VA_ARGS__);\
	ft_printf("PRINTF:\n%#m\n", (char*)buff, LEN);\
	int res2 = ft_snprintf(buff, LEN, (char*)fmt, __VA_ARGS__);\
	ft_printf("FT_PRINTF:\n%#m\n", (char*)buff, LEN);\
	printf("printf returned <%d>, ft_printf returned <%d>\n", res, res2); \
} while(0)

int	main(void)
{
	MCMPARE("%#-*.*X", -40, 10, -4);
	return (0);
}
