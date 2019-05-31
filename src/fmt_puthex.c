/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_puthex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:45:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 17:38:30 by nloomans      ########   odam.nl         */
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
	unsigned long long	n;
	t_number			number;
	char				buf[128];
	size_t				idx;

	intern_pop_wildcards(token, vlist);
	n = va_arg(vlist, unsigned long long);
	n = intern_auto_floor(token->size, n);
	number.value = n;
	number.base = 16U;
	own_hex_size = ((token->flags & FLAGS_HASH) != 0) * 2;
	idx = intern_ntoa(buf, number, token->flags & FLAGS_CAPITAL);
	own_hex_size += idx;
	own_hex_size = token->flags & FLAGS_PRECISION
		? (size_t)ft_max(token->precision, own_hex_size)
		: own_hex_size;
	intern_fmt_pad_left(writer, token, ' ', own_hex_size);
	if (token->flags & FLAGS_HASH)
		writer_write(writer,
			token->flags & FLAGS_CAPITAL ? "0X" : "0x", 2);
	if (token->flags & FLAGS_PRECISION && idx < (size_t)token->precision)
		intern_fmt_pad(writer, '0', token->precision - idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, token, ' ', own_hex_size);
}
