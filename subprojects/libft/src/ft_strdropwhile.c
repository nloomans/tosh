/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdropwhile.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 17:52:31 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 18:38:45 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdropwhile(const char *str, int should_skip(int c))
{
	while (should_skip(*str) && *str != '\0')
		str++;
	return ((char *)str);
}
