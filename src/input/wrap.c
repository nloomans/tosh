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

#include <assert.h>
#include <libft.h>
#include "private.h"

static size_t	chunk_width(size_t max_width, const char *buffer)
{
	size_t width;

	width = ft_strlen(buffer);
	if (width > max_width)
		return (max_width);
	return (width);
}

size_t			input__wrap(
					char ***dest,
					size_t terminal_width,
					size_t prompt_width,
					const char *buffer)
{
	size_t	line_count;
	size_t	width;

	assert(prompt_width <= terminal_width); // TODO: probably not a good idea.
	*dest = ft_memalloc(ft_strlen(buffer) * sizeof(**dest));
	if (*dest == NULL)
		return (-1);
	line_count = 0;
	while (*buffer != '\0')
	{
		width = chunk_width(
			line_count == 0 ? terminal_width - prompt_width : terminal_width,
			buffer);
		(*dest)[line_count] = ft_strsub(buffer, 0, width);
		buffer += width;
		line_count++;
	}
	return (line_count);
}
