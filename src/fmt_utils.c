/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:31:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/20 15:57:56 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

void	intern_pop_wildcards(t_token *token, va_list vlist)
{
	if (token->width == DEFERRED_WILDCARD)
	{
		token->width = va_arg(vlist, int);
		if (token->width < 0)
		{
			token->width = -token->width;
			token->flags |= FLAGS_LEFTALIGN;
		}
	}
	if (token->flags & FLAGS_PRECISION && token->precision == DEFERRED_WILDCARD)
		token->precision = va_arg(vlist, int);
}

char	intern_pad_char(t_flags flags)
{
	return ((flags & FLAGS_ZEROPAD) ? '0' : ' ');
}

char	*intern_sign_for(t_number *number)
{
	if (number->sign == -1)
		return ("-");
	if (number->sign == 1)
		return ("+");
	return (NULL);
}

void	intern_number_prefix(
	t_writer *writer,
	t_token *token,
	t_number n,
	size_t size)
{
	if (!(token->flags & FLAGS_ZEROPAD))
		intern_fmt_pad_left(writer, token, intern_pad_char(token->flags), size);
	if (n.value != 0 && (n.sign == -1 || token->flags & FLAGS_PLUS))
		writer_write(writer, intern_sign_for(&n), 1);
	if (n.value != 0 && n.sign == 1 && (token->flags & FLAGS_SPACE))
		writer_write(writer, " ", 1);
	if (token->flags & FLAGS_ZEROPAD)
		intern_fmt_pad_left(writer, token, intern_pad_char(token->flags), size);
}
