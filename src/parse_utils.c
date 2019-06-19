/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 00:11:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/19 15:28:53 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "parser.h"
#include "token.h"

int		parse_atoi(char **stream)
{
	int	sum;

	sum = 0;
	while (ft_isdigit(**stream))
	{
		sum = sum * 10 + (**stream - '0');
		(*stream)++;
	}
	return (sum);
}

int		parse_atoi_wildcard(char **stream)
{
	if (**stream == '*')
	{
		(*stream)++;
		return (DEFERRED_WILDCARD);
	}
	else if (ft_isdigit(**stream))
		return (parse_atoi(stream));
	else
		return (0);
}

void	truncate_flags(t_token *dest)
{
	if (dest->flags & FLAGS_PRECISION)
		dest->flags &= ~FLAGS_ZEROPAD;
	if (dest->flags & FLAGS_PLUS)
		dest->flags &= ~FLAGS_SPACE;
	if (dest->flags & FLAGS_LEFTALIGN)
		dest->flags &= ~FLAGS_ZEROPAD;
}
