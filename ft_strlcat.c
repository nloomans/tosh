/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 16:47:53 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 16:39:39 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static size_t	strlen_max(const char *s, size_t max_len)
{
	size_t	len;

	len = 0;
	while (len < max_len && s[len] != '\0')
		len++;
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dst_initial_len;
	unsigned long	src_index;

	dst_initial_len = strlen_max(dst, size);
	src_index = 0;
	while (dst_initial_len + src_index + 1 < size && src[src_index] != '\0')
	{
		dst[dst_initial_len + src_index] = src[src_index];
		src_index++;
	}
	if (dst_initial_len + src_index < size)
		dst[dst_initial_len + src_index] = '\0';
	return (dst_initial_len + ft_strlen(src));
}
