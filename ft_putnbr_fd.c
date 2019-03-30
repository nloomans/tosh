/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 19:39:33 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 17:40:31 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		digit_to_char(int n)
{
	return (n + '0');
}

static void		ft_putnbr_fd_c(int n, int fd)
{
	if (n / 10 != 0)
		ft_putnbr_fd_c(n / 10, fd);
	ft_putchar_fd(digit_to_char(-(n % 10)), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n *= -1;
	ft_putnbr_fd_c(n, fd);
}
