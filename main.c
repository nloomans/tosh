/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:26:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 21:05:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{	
	int res = ft_printf("Hello, %s, %p, %#X\n", "World", "", 0XDEADBEEF);
	ft_printf("Returned: %d\n", res);
	return (0);
}
