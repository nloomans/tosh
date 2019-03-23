/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:00:50 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/23 15:27:53 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	size_t			needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	while (1)
	{
		if (i > len - needle_len)
			return (NULL);
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
		if (haystack[i] == '\0')
			return (NULL);
		i++;
	}
}
