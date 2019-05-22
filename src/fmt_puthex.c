/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_puthex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:45:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 00:47:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

char			to_hex(char num, int caps)
{
	char hex_starter;

	hex_starter = caps ? 'A' : 'a';
	if (num >= 10 && num <= 15)
	{
		return (hex_starter + (num - 10));
	}
	else if (num >= 0 && num <= 9)
	{
		return ('0' + num);
	}
	else
	{
		return ('\0');
	}
}

ssize_t			intern_fmt_puthex(t_writer *writer, unsigned value, int caps)
{
	size_t	written;
	char	c;

	written = 0;
	if (value > 16)
	{
		written += intern_fmt_puthex(writer, value / 16, caps);
	}
	c = to_hex(value % 16, caps);
	written += writer_write(writer, &c, 1);
	return (written);
}

ssize_t			fmt_puthex(t_writer *writer, t_token *token, va_list vlist)
{
	size_t			written;
	unsigned int	n;

	(void)token;
	written = 0;
	if (token->flags & FLAGS_HASH)
		written += writer_write(writer,
			token->flags & FLAGS_CAPITAL ? "0X" : "0x", 2);
	n = va_arg(vlist, unsigned int);
	return (written + intern_fmt_puthex(writer, n, token->flags & FLAGS_CAPITAL));
}
