/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:27:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/26 00:29:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parser.h"
#include <libft.h>
# include <stdio.h>
# include <stdlib.h>

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
		dest->type = E_TXT;
		dest->s_value = *stream;
		dest->s_length = 1;
	}
	(*stream)++;
	return (1);
}

int			st_handle_str_lit(t_fsm *st, t_token *dest, char **stream)
{
	(void)st;
	if (**stream == '%')
		return (0);
	dest->s_length++;
	(*stream)++;
	return (1);
}

int			st_handle_param(t_fsm *st, t_token *dest, char **stream)
{
	(void)st;
	dest->width = 0;
	dest->flags = 0;
	if (**stream == '{')
	{
		(*stream)++;
		dest->type = E_COLOR;
		dest->s_value = *stream;
		while (**stream && **stream != '}')
		{
			dest->s_length++;
			(*stream)++;
		}
		(*stream)++;
		return (0);
	}
	if (**stream == '#')
	{
		dest->flags |= FLAGS_HASH;
		(*stream)++;
	}
	if (**stream == ' ')
	{
		dest->flags |= FLAGS_SPACE;
		(*stream)++;
	}
	if (**stream == '0')
	{
		dest->flags |= FLAGS_ZEROPAD;
		(*stream)++;
	}
	if (**stream == '+')
	{
		dest->flags |= FLAGS_PLUS;
		(*stream)++;
	}
	if (**stream == '-')
	{
		dest->flags |= FLAGS_LEFTALIGN;
		(*stream)++;
	}
	if (ft_isdigit(**stream))
		dest->width = parse_atoi(stream);
	else if (**stream == '*')
	{
		dest->width = -1;
		(*stream)++;
	}
	if (**stream == '.')
	{
		(*stream)++;
		dest->flags |= FLAGS_PRECISION;
		if (ft_isdigit(**stream))
			dest->precision = parse_atoi(stream);
		else if (**stream == '*')
		{
			dest->precision = -1;
			(*stream)++;
		}
	}
	if (**stream == 'h')
	{
		(*stream)++;
		if (**stream == 'h')
		{
			(*stream)++;
			dest->size = E_HH;
		}
		else
			dest->size = E_H;
	}
	else if (**stream == 'l')
	{
		(*stream)++;
		if (**stream == 'l')
		{
			(*stream)++;
			dest->size = E_LL;
		}
		else
			dest->size = E_L;
	}
	else
		dest->size = E_N;
	while (**stream)
	{
		if (ft_strchr("disopc%xXfFmMu", **stream))
		{
			if (**stream == 'd' || **stream == 'i')
				dest->type = E_INT;
			else if (**stream == 's')
				dest->type = E_STR;
			else if (**stream == 'o')
				dest->type = E_OCT;
			else if (**stream == 'u')
				dest->type = E_UNS;
			else if (**stream == 'p')
				dest->type = E_PTR;
			else if (**stream == 'c')
				dest->type = E_CHR;
			else if (**stream == '%')
				dest->type = E_PERCENT;
			else if (**stream == 'm' || **stream == 'M')
			{
				dest->type = E_MEMORY;
				dest->flags |= **stream == 'M' ? FLAGS_CAPITAL : 0;
			}
			else if (**stream == 'x' || **stream == 'X')
			{
				dest->type = E_HEX;
				dest->flags |= **stream == 'X' ? FLAGS_CAPITAL : 0;
			}
			else if (**stream == 'f' || **stream == 'F')
			{
				dest->type = E_FLOAT;
				dest->flags |= **stream == 'F' ? FLAGS_CAPITAL : 0;
			}
			(*stream)++;
			return (0);
		}
		else
		{
			if (ft_isdigit(**stream))
				dest->width = parse_atoi(stream);
			else if (ft_strchr(" ", **stream))
			{
				(*stream)++;
			}
			else
			{
				printf("- Something went wrong -\n");
				exit(0);
			}
		}
	}
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
