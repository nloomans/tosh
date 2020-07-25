/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:38:10 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/20 12:25:44 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}
