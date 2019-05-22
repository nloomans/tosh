/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:27:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 21:00:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parser.h"
#include <libft.h>

int			st_handle_any(t_fsm *st, t_token *dest, char **stream)
{
	if (**stream == '%')
	{
		*st = ST_PARAM;
		dest->size = E_N;
	}
	else
	{
		*st = ST_STR_LIT;
		dest->type = E_STRING;
		dest->value = *stream;
		dest->length = 1;
	}
	(*stream)++;
	return (1);
}

int			st_handle_str_lit(t_fsm *st, t_token *dest, char **stream)
{
	(void)st;
	if (**stream == '%')
		return (0);
	dest->length++;
	(*stream)++;
	return (1);
}

int			st_handle_param(t_fsm *st, t_token *dest, char **stream)
{
	(void)st;
	if (**stream == '%')
	{
		dest->type = E_PERCENT;
		(*stream)++;
		return (0);
	}
	if (ft_strchr("diouxXcsp", **stream))
	{
		if (**stream == 'd' || **stream == 'i')
			dest->type = E_INT;
		if (**stream == 's')
			dest->type = E_STR;
		if (**stream == 'u')
			dest->type = E_UNS;
		if (**stream == 'o')
			dest->type = E_OCT;
		if (**stream == 'p')
			dest->type = E_PTR;
		if (**stream == 'c')
			dest->type = E_CHR;
		if (**stream == 'x' || **stream == 'X')
		{
			dest->type = E_HEX;
			dest->capitalization = **stream == 'X';
		}
		(*stream)++;
		return (0);
	}
	else
	{
		if (**stream == 'l')
			dest->size =
				dest->size == E_L ? E_LL : E_L;
		else if (**stream == 'h')
			dest->size =
				dest->size == E_H ? E_HH : E_H;
		else if (**stream == '#')
			dest->prefix = 1;
		else
		{
			return (0);
		}
		(*stream)++;
		return (1);
	}
}

int			handle_state(t_fsm *st, t_token *dest, char **stream)
{
	const t_st_handler handlers[] = {
		st_handle_any,
		st_handle_param,
		st_handle_str_lit,
	};

	return ((handlers[*st])(st, dest, stream));
}

int			parse_token(t_token *dest, char **stream)
{
	t_fsm		st;
	int			ret;

	ret = 1;
	ft_memset(dest, 0, sizeof(t_token));
	st = ST_ANY;
	while (**stream)
	{
		ret = handle_state(&st, dest, stream);
		if (ret == 0)
			return (1);
	}
	return (0);
}
