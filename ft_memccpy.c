/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 15:52:31 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/23 17:06:05 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	unsigned char	uc_c;
	unsigned long	i;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		if (uc_src[i] == uc_c)
			return (void *)(uc_dst + i + 1);
		i++;
	}
	return (NULL);
}
