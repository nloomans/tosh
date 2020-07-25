/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:28:47 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/28 20:14:57 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = ft_strnew(len);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
