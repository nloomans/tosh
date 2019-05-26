/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_ntoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 00:06:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 01:25:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include <libft.h>

size_t	intern_ntoa(char *buf_out, unsigned long long n, unsigned base, int caps)
{
	char	buf[128];
	char 	dig;
	size_t	len;

	len = 0;
	while (len < 128u)
	{
		dig = n % base;
		buf[len] = intern_to_hex(dig, caps);
		len++;
		n /= base;
		if (!n)
			break ;
	}
	buf[len] = '\0';
	ft_strrev(buf);
	ft_memcpy(buf_out, buf, len);
	return (len);
}