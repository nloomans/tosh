/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:18:06 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/20 13:42:05 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	i;
	int				has_reached_end;

	i = 0;
	has_reached_end = 0;
	while (i < len)
	{
		if (!has_reached_end && src[i] == '\0')
			has_reached_end = 1;
		if (has_reached_end)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
