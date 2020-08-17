/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 15:31:40 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/28 20:19:18 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	size_t				chunk_size;
	unsigned long long	chunk;

	chunk = 0;
	chunk_size = sizeof(unsigned long long);
	i = chunk_size / sizeof(unsigned char);
	while (i > 0)
	{
		chunk <<= 8;
		chunk |= (unsigned long long)(unsigned char)c;
		i--;
	}
	i = 0;
	while (len >= chunk_size && i < (len - chunk_size))
	{
		*(unsigned long long *)&(((unsigned char *)b)[i]) = chunk;
		i += chunk_size;
	}
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
