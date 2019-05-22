/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 00:11:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 00:12:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "parser.h"

int	parse_atoi(char **stream)
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