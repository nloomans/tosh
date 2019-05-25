/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_puthex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:45:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/25 01:23:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "fmt.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

char			intern_to_hex(char num, int caps)
{
	char hex_starter;

	hex_starter = caps ? 'A' : 'a';
	if (num >= 10 && num <= 15)
		return (hex_starter + (num - 10));
	else if (num >= 0 && num <= 9)
		return ('0' + num);
	else
		return ('\0');
}

int		intern_hex_size(long long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n / 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void			intern_fmt_puthex(t_writer *writer, unsigned long long value, int caps)
{
	char	c;

	if (value >= 16)
		intern_fmt_puthex(writer, value / 16, caps);
	c = intern_to_hex(value % 16, caps);
	writer_write(writer, &c, 1);
}

void			fmt_puthex(t_writer *writer, t_token *token, va_list vlist)
{
	unsigned long long	own_hex_size;
	unsigned long long n;

	(void)token;
	n = va_arg(vlist, unsigned long long);
	own_hex_size = ((token->flags & FLAGS_HASH) != 0) * 2 + intern_hex_size(n);
	if ((unsigned long long)token->width > own_hex_size)
		intern_fmt_pad(writer, ' ', token->width - own_hex_size);
	if (token->flags & FLAGS_HASH)
		writer_write(writer,
			token->flags & FLAGS_CAPITAL ? "0X" : "0x", 2);
	intern_fmt_puthex(writer, n, token->flags & FLAGS_CAPITAL);
}
