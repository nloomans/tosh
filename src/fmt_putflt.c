/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putflt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 00:44:24 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/21 16:10:27 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include "writer.h"
#include "token.h"
#include "fmt.h"

/*
** Calculate the size a float will be (excluding padding). This ashumes that
** precision has been set to the default if it was unset.
**
** If n < 0 we count 1 extra to account for the `-'.
** If precision > 0 we count 1 extra to account for the `.'.
*/

static size_t	float_size(t_token *token, size_t before_dot, long double n)
{
	size_t	size;

	size = 0;
	if (n < 0 || token->flags & FLAGS_PLUS || token->flags & FLAGS_SPACE)
		size++;
	size += before_dot;
	if (token->precision > 0)
		size++;
	size += token->precision;
	return (size);
}

static void		print_real_float(
	t_writer *writer,
	t_token *token,
	long double n)
{
	char		buf[128];
	t_number	num;
	double		fract;
	size_t		idx;
	size_t		size;

	num.base = 10U;
	num.sign = n > 0 ? 1 : -1;
	num.value = intern_abs((long long)n);
	fract = n - (long long)n;
	idx = intern_ntoa(buf, num, 0);
	size = float_size(token, idx, n);
	intern_number_prefix(writer, token, num, size);
	writer_write(writer, buf, idx);
	if (token->precision > 0)
		writer_write(writer, ".", 1);
	// TODO: (required for deepthought) round the last digit
	while (token->precision > 0)
	{
		fract *= 10;
		num.value = (unsigned long long)fract;
		fract -= num.value;
		idx = intern_ntoa(buf, num, 0);
		writer_write(writer, buf, idx);
		token->precision--;
	}
	intern_fmt_pad_right(writer, token, intern_pad_char(token->flags), size);
}

static void		print_fake_float(
	t_writer *writer,
	t_token *token,
	long double n)
{
	if (token->flags & FLAGS_CAPITAL)
	{
		if (n != n)
			writer_write(writer, "NAN", 3);
		else if (n == 1.0 / 0.0)
			writer_write(writer, "INF", 3);
		else if (n == -1.0 / 0.0)
			writer_write(writer, "-INF", 4);
		else
			assert(0);
	}
	else
	{
		if (n != n)
			writer_write(writer, "nan", 3);
		else if (n == 1.0 / 0.0)
			writer_write(writer, "inf", 3);
		else if (n == -1.0 / 0.0)
			writer_write(writer, "-inf", 4);
		else
			assert(0);
	}
}

void			fmt_putflt(t_writer *writer, t_token *token, va_list vlist)
{
	long double		n;

	intern_pop_wildcards(token, vlist);
	if (!(token->flags & FLAGS_PRECISION))
		token->precision = 6;
	n = intern_read_float(token->size, vlist);
	if (n != n || n == 1.0 / 0.0 || n == -1.0 / 0.0)
		print_fake_float(writer, token, n);
	else
		print_real_float(writer, token, n);
}
