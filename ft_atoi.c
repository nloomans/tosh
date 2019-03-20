/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 10:38:48 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 19:06:50 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_atoi_consume_plus_minus(const char *str, int *is_positive)
{
	*is_positive = 1;
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		*is_positive = 0;
		str++;
	}
	return ((char *)str);
}

int			ft_atoi(const char *str)
{
	int nb;
	int is_positive;

	str = ft_strdropwhile(str, ft_isspace);
	str = ft_atoi_consume_plus_minus(str, &is_positive);
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb -= *str - 48;
		str++;
	}
	if (is_positive)
		return (-1 * nb);
	else
		return (nb);
}
