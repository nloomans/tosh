/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:31:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 14:19:45 by nmartins      ########   odam.nl         */
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

void	intern_auto_floor(t_token *token, unsigned long long *n)
{
	if (token->size == E_HH)
		*n = (unsigned long long)(unsigned char)*n;
	if (token->size == E_H)
		*n = (unsigned long long)(unsigned short)*n;
	if (token->size == E_N)
		*n = (unsigned long long)(unsigned int)*n;
	if (token->size == E_L)
		*n = (unsigned long long)(unsigned long)*n;
}
