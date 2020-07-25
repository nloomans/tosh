/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:49:53 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/30 18:03:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char f(char))
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = ft_strdup(s);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = f(s[i]);
		i++;
	}
	return (dup);
}
