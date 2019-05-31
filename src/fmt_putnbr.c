/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:52:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 13:49:06 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "fmt.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

static unsigned long long	intern_abs(long long source)
{
	if (source >= 0)
		return ((unsigned long long)source);
	else
		return (-((unsigned long long)source));
}

char						*intern_sign_for(t_number *number)
{
	if (number->sign == -1)
		return ("-");
	if (number->sign == 1)
		return ("+");
	return (NULL);
}

void						intern_split_sign(
	t_token *token,
	t_number *number,
	long long value,
	unsigned char base)
{
	intern_auto_floor_signed(token, &value);
	number->sign = value > 0 ? 1 : -1;
	number->value = intern_abs(value);
	number->base = base;
}

char						intern_pad_char(t_token *token)
{
	return ((token->flags & FLAGS_ZEROPAD) ? '0' : ' ');
}

static size_t				calculate_actual_size(
	const t_token	*tok,
	size_t			number_width,
	const t_number	*number)
{
	size_t		actual_size;

	if (tok->flags & FLAGS_PRECISION)
		actual_size = ft_max(number_width, tok->precision);
	else
		actual_size = number_width;
	if (number->value &&
		(number->sign == -1 || tok->flags & (FLAGS_PLUS | FLAGS_SPACE)))
		actual_size++;
	return (actual_size);
}

void						fmt_putnbr(
	t_writer *writer,
	t_token *tok,
	va_list vlist)
{
	char		buf[128];
	t_number	n;
	size_t		idx;
	size_t		actual_size;

	intern_pop_wildcards(tok, vlist);
	intern_split_sign(tok, &n, va_arg(vlist, long long), 10U);
	idx = intern_ntoa(buf, n, 0);
	actual_size = calculate_actual_size(tok, idx, &n);
	if (tok->flags & FLAGS_PRECISION && tok->precision < tok->width)
		tok->flags &= ~FLAGS_ZEROPAD;
	if ((tok->flags & FLAGS_ZEROPAD) == 0)
		intern_fmt_pad_left(writer, tok, intern_pad_char(tok), actual_size);
	if (n.value != 0 && (n.sign == -1 || tok->flags & FLAGS_PLUS))
		writer_write(writer, intern_sign_for(&n), 1);
	if (n.value && n.sign == 1 && !(tok->flags & FLAGS_PLUS) &&
		(tok->flags & FLAGS_SPACE))
		writer_write(writer, " ", 1);
	if (tok->flags & FLAGS_ZEROPAD)
		intern_fmt_pad_left(writer, tok, intern_pad_char(tok), actual_size);
	if (tok->flags & FLAGS_PRECISION)
		intern_fmt_pad_auto(writer, '0', tok->precision, idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, tok, intern_pad_char(tok), actual_size);
}
