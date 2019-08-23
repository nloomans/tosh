/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:16:01 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 18:26:18 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, '\0', size);
	return (dst);
}
