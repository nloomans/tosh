/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 11:09:32 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/28 20:17:32 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s;
	unsigned char		uc_c;

	i = 0;
	uc_s = s;
	uc_c = c;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
			return ((void *)(uc_s + i));
		i++;
	}
	return (NULL);
}
