/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:52:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 17:01:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "fmt.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

static size_t	num_size(long long n)
{
	if (n / 10)
		return (1 + num_size(n / 10));
	return (1);
}

void			intern_fmt_putnbr(t_writer *writer, long long n, t_size s)
{
	char	c;

	if (n / 10)
		intern_fmt_putnbr(writer, n / 10, s);
	c = '0' + (n % 10);
	writer_write(writer, &c, 1);
}

void			fmt_putnbr(t_writer *writer, t_token *token, va_list vlist)
{
	long long	n;
	size_t		len;
	size_t		len_after_prec;
	char		pad_char;

	//TODO: handle size
	intern_pop_wildcards(token, vlist);
	n = va_arg(vlist, long long);
	len = num_size(n);
	len_after_prec = token->flags & FLAGS_PRECISION
		? ft_max(token->precision, len)
		: len;
	pad_char = token->flags & FLAGS_ZEROPAD ? '0' : ' ';
	if ((token->flags & FLAGS_LEFTALIGN) == 0 &&
		len_after_prec < (size_t)token->width)
		intern_fmt_pad(writer, pad_char, token->width - len_after_prec);
	if (token->flags & FLAGS_PRECISION && len < (size_t)token->precision)
		intern_fmt_pad(writer, '0', token->precision - len);
	intern_fmt_putnbr(writer, ft_abs(n), E_N);
	if ((token->flags & FLAGS_LEFTALIGN) &&
		len_after_prec < (size_t)token->width)
		intern_fmt_pad(writer, pad_char, token->width - len_after_prec);
}
