/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:27:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 16:48:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parser.h"
#include <libft.h>

# include <stdio.h>

int			st_handle_any(t_fsm *st, t_token *dest, char **stream)
{
	if (**stream == '%')
		*st = ST_PARAM;
	else
	{
		*st = ST_STR_LIT;
		dest->type = E_LITERAL;
		dest->value.as_literal.type = E_STRING;
		dest->value.as_literal.value = *stream;
		dest->value.as_literal.length = 1;
	}
	(*stream)++;
	return (1);
}

int			st_handle_str_lit(t_fsm *st, t_token *dest, char **stream)
{
	(void)st;
	if (**stream == '%')
		return (0);
	dest->value.as_literal.length++;
	(*stream)++;
	return (1);
}

int			st_handle_param(t_fsm *st, t_token *dest, char **stream)
{
	if (**stream == '%')
	{
		dest->type = E_LITERAL;
		dest->value.as_literal.type = E_PERCENT;
		(*stream)++;
		return (0);
	}
	dest->type = E_PARAMETER;
	if (**stream == 'd')
		dest->value.as_parameter.type = E_INT;
	if (**stream == 's')
		dest->value.as_parameter.type = E_STR;
	(void)st;
	(void)dest;
	(*stream)++;
	return (0);
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
	const char	*lookup[] = {
		"ST_ANY",
		"ST_PARAM",
		"ST_STR_LIT",
	};

	ret = 1;
	ft_memset(dest, 0, sizeof(t_token));
	st = ST_ANY;
	while (**stream)
	{
		printf("State: \x1b[36m%18s\x1b[0m;\tStream: \x1b[32m%s\x1b[0m\n",
			lookup[st], *stream);
		ret = handle_state(&st, dest, stream);
		if (ret == 0)
			return (1);
	}
	return (0);
}
