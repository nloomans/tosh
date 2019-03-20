/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strdup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:28:47 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/20 11:45:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;
	
	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(*dup) * len);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
