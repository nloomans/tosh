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
#include <ft_printf.h>
#include "private.h"

static void				swap(size_t *a, size_t *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

t_error					input__action_cut(struct s_input__state *state)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (state->select_start == -1)
		return (error_none());
	start = state->select_start;
	end = state->cursor_position;
	if ((size_t)state->select_start > state->cursor_position)
		swap(&start, &end);
	input__action_copy(state);
	ft_asprintf(&new, "%.*s%s",
		start, state->buffer,
		state->buffer + end);
	if (new == NULL)
		return (errorf("out of memory"));
	ft_strreplace(&state->buffer, new);
	if ((size_t)state->select_start < state->cursor_position)
		state->cursor_position -= end - start;
	return (error_none());
}
