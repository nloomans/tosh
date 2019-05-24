/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:26:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 20:20:31 by nmartins      ########   odam.nl         */
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
	printf("printf returned <%d>, ft_printf returned <%d>\n", res, res2); \
} while (0)

int	main(void)
{
	char *dest;
	int	len;

	len = ft_aprintf(&dest, "%cHello\n", '\0');
	ft_printf("%m\n", dest, len);	

	return (0);
}
