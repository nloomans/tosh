/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:31:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 17:42:52 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"


void				intern_pop_wildcards(t_token *token, va_list vlist)
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

unsigned long long	intern_auto_floor(t_size size, unsigned long long n)
{
	if (size == E_HH)
		return ((unsigned long long)(unsigned char)n);
	if (size == E_H)
		return ((unsigned long long)(unsigned short)n);
	if (size == E_N)
		return ((unsigned long long)(unsigned int)n);
	if (size == E_L)
		return ((unsigned long long)(unsigned long)n);
	return (n);
}

long long			intern_auto_floor_signed(t_size size, long long n)
{
	if (size == E_HH)
		return ((long long)(char)n);
	if (size == E_H)
		return ((long long)(short)n);
	if (size == E_N)
		return ((long long)(int)n);
	if (size == E_L)
		return ((long long)(long)n);
	return (n);
}

char				intern_pad_char(t_flags flags)
{
	return ((flags & FLAGS_ZEROPAD) ? '0' : ' ');
}
