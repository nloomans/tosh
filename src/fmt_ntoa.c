/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_ntoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 00:06:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 15:16:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "number.h"
#include <libft.h>

size_t	intern_ntoa(char *buf_out, t_number number, int caps)
{
	char	buf[128];
	char 	dig;
	size_t	len;

	len = 0;
	while (len < 128u)
	{
		dig = number.value % number.base;
		buf[len] = intern_to_hex(dig, caps);
		len++;
		number.value /= number.base;
		if (!number.value)
			break ;
	}
	buf[len] = '\0';
	ft_strrev(buf);
	ft_memcpy(buf_out, buf, len);
	return (len);
}
