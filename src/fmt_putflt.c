/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putflt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 00:44:24 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/14 12:39:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include "fmt.h"
#include <stdarg.h>
#include <stdio.h>

void			fmt_putflt(t_writer *writer, t_token *token, va_list vlist)
{
	long double			n;
	double				fract;
	t_number			num;
	char				buf[128];
	size_t				idx;

	intern_pop_wildcards(token, vlist);
	if (!(token->flags & FLAGS_PRECISION))
		token->precision = 6;
	n = intern_read_float(token->size, vlist);
	num.base = 10U;
	num.value = intern_abs((long long)n);
	fract = n - (long long)n;
	idx = intern_ntoa(buf, num, 0);
	if (n < 0)
		writer_write(writer, "-", 1);
	writer_write(writer, buf, idx);
	if (token->precision > 0)
		writer_write(writer, ".", 1);
	while (token->precision > 0)
	{
		fract *= 10;
		num.value = (unsigned long long)fract;
		fract -= num.value;
		idx = intern_ntoa(buf, num, 0);
		writer_write(writer, buf, idx);
		token->precision--;
	}
}
