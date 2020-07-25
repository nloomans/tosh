/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:50:15 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/27 17:26:38 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strange_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	while (strange_is_space(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s);
	while (end > 0 && strange_is_space(s[end - 1]))
		end--;
	return (ft_strsub(s, start, end - start));
}
