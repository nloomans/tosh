/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 11:39:41 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 13:43:17 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *new_str;

	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	return (ft_strncpy(new_str, s + start, len));
}
