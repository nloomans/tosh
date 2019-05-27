/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 00:11:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 17:51:02 by nloomans      ########   odam.nl         */
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
