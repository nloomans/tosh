/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putoct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 20:43:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 15:19:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include "fmt.h"
#include <stdarg.h>
#include <stdio.h>

void			intern_fmt_putoct(t_writer *writer, unsigned value)
{
	char	c;

	if (value > 8)
		intern_fmt_putoct(writer, value / 8);
	c = '0' + (value % 8);
	writer_write(writer, &c, 1);
}

void			fmt_putoct(t_writer *writer, t_token *token, va_list vlist)
{
	unsigned long long	n;
	char				buf[128];
	size_t				idx;
	t_number			number;
	int					prefix;

	intern_pop_wildcards(token, vlist);
	n = va_arg(vlist, unsigned long long);
	intern_auto_floor(token, &n);
	number.base = 8U;
	number.value = n;
	idx = intern_ntoa(buf, number, 0);
	prefix = token->flags & FLAGS_HASH && n != 0;
	intern_fmt_pad_left(writer, token, ' ', idx + prefix);
	if (token->flags & FLAGS_HASH && n != 0)
		writer_write(writer, "0", 1);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, token, ' ', idx + prefix);
}
