/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putoct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 20:43:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 00:47:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

ssize_t			intern_fmt_putoct(t_writer *writer, unsigned value)
{
	size_t	written;
	char	c;

	written = 0;
	if (value > 8)
	{
		written += intern_fmt_putoct(writer, value / 8);
	}
	c = '0' + (value % 8);
	written += writer_write(writer, &c, 1);
	return (written);
}

ssize_t			fmt_putoct(t_writer *writer, t_token *token, va_list vlist)
{
	size_t			written;
	unsigned int	n;

	written = 0;
	n = va_arg(vlist, unsigned int);
	if (token->flags & FLAGS_HASH && n != 0)
	{
		written += writer_write(writer, "0", 1);
	}
	return (written + intern_fmt_putoct(writer, n));
}
