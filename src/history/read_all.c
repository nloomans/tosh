/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh-21Shell                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

#include "private.h"

static char		*strdup_size(const char *str, size_t len)
{
	char	*dup;

	dup = ft_strnew(len);
	if (dup == NULL)
		return (NULL);
	if (str)
		ft_strlcpy(dup, str, len + 1);
	return (dup);
}

t_error			history__read_all(char **out, int fd)
{
	int		ret;
	size_t	offset;
	size_t	size;

	size = 32;
	offset = 0;
	while (true)
	{
		size *= 2;
		ft_strreplace(out, strdup_size(*out, size));
		if (*out == NULL)
			return (errorf("out of memory"));
		ret = read(fd, *out + offset, size / 2);
		if (ret == -1)
		{
			ft_strdel(out);
			return (errorf("read syscall failed"));
		}
		if (ret == 0)
			return (error_none());
		offset += ret;
	}
}
