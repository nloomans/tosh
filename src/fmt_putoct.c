/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putoct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 20:43:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/28 01:33:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include "fmt.h"
#include <stdarg.h>
#include <stdio.h>


void			fmt_putoct(t_writer *writer, t_token *token, va_list vlist)
{
	char				buf[128];
	size_t				idx;
	size_t				actual_size;
	t_number			number;

	intern_pop_wildcards(token, vlist);
	number.value = va_arg(vlist, unsigned long long);
	intern_auto_floor(token, &number.value);
	number.base = 8U;
	idx = intern_ntoa(buf, number, 0);
	actual_size = idx;
	if (token->flags & FLAGS_HASH)
		actual_size++;
	if (token->flags & FLAGS_PRECISION)
	{
		actual_size = ft_max(actual_size, token->precision);
		if (token->precision == 0)
			actual_size = 0;
	}
	intern_fmt_pad_left(writer, token, ' ', actual_size);
	if (token->flags & FLAGS_HASH && number.value != 0)
		writer_write(writer, "0", 1);
	if (token->flags & FLAGS_PRECISION)
		intern_fmt_pad_auto(writer, '0', token->precision, idx + !!(token->flags & FLAGS_HASH));
	/* writing part */
	if (token->flags & FLAGS_PRECISION && token->precision != 0)
		writer_write(writer, buf, idx);
	/* ------------ */

	intern_fmt_pad_right(writer, token, ' ', actual_size);
}
