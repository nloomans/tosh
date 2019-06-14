/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:31:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/14 12:29:08 by nloomans      ########   odam.nl         */
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
