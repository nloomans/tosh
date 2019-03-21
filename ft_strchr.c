/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:24:59 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 18:48:54 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if ((int)*s == c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
