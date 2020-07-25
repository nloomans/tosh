/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 15:35:12 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/28 20:18:48 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	return (s1);
}
