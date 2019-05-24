/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:31:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 17:02:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"


// TODO: add auto-padding detector
void			intern_fmt_pad(t_writer *writer, char c, size_t amt)
{
	size_t i;

	i = 0;
	while (i < amt)
	{
		writer_write(writer, &c, 1);
		i++;
	}
}

void			intern_fmt_pad_auto(t_writer *writer, char c, size_t pad_amount, size_t length)
{
	size_t	i;

	i = 0;
	if (pad_amount > length)
	{
		while (i < (pad_amount - length))
		{
			writer_write(writer, &c, 1);
			i++;
		}
	}
}

void			intern_pop_wildcards(t_token *token, va_list vlist)
{
	if (token->width == DEFERRED_WILDCARD)
		token->width = va_arg(vlist, int);
	if (token->flags & FLAGS_PRECISION && token->precision == DEFERRED_WILDCARD)
		token->precision = va_arg(vlist, int);
}
