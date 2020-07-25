/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstrim.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:50:15 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/27 17:28:09 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrim(const char *s)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	while (ft_isspace(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s);
	while (end > 0 && ft_isspace(s[end - 1]))
		end--;
	return (ft_strsub(s, start, end - start));
}
