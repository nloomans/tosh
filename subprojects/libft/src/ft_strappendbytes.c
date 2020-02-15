/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappendbytes.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:26 by nloomans       #+#    #+#                */
/*   Updated: 2019/04/09 17:32:34 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Append len bytes from to_append to str.
**
** str will be reallocated.
**
** Returns 1 on success and 0 on error.
*/

int		ft_strappendbytes(char **str, char *to_append, size_t len)
{
	char *new_str;

	new_str = ft_strnew(ft_strlen(*str) + len);
	if (new_str == NULL)
		return (0);
	ft_strcpy(new_str, *str);
	ft_strncat(new_str, to_append, len);
	ft_strdel(str);
	*str = new_str;
	return (1);
}
