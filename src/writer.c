/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:04:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/20 16:01:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "writer.h"

ssize_t	writer_write(t_writer *writer, char *str, size_t length)
{
	return (writer->write(writer->state, str, length));
}

ssize_t	writer_fd_write(void *state, char *str, size_t length)
{
	return (write(*(t_writer_fd_state *)state, str, length));
}

ssize_t	writer_alloc_write(void *void_state, char *str, size_t length)
{
	t_writer_alloc_state	*state;
	char					*new;

	state = (t_writer_alloc_state*)void_state;
	new = ft_realloc(*state->str_ptr, state->len, state->len + length);
	if (new == NULL)
		return (-1);
	*state->str_ptr = new;
	if (ft_memcpy(*state->str_ptr + state->len, str, length) == NULL)
		return (-1);
	state->len += length;
	return (length);
}
