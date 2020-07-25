/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:50:15 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/30 18:04:34 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *dup;

	dup = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (dup == NULL)
		return (NULL);
	ft_strcat(dup, s1);
	ft_strcat(dup, s2);
	return (dup);
}
