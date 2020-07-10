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

t_error					input__action_copy(struct s_input__state *state)
{
	size_t	start;
	size_t	end;

	if (state->select_start == -1)
		return (error_none());
	start = state->select_start;
	end = state->cursor_position;
	if ((size_t)state->select_start > state->cursor_position)
		swap(&start, &end);
	ft_strreplace(&state->copied_buffer, ft_strsub(state->buffer,
		start, end - start));
	if (state->copied_buffer == NULL)
		return (errorf("out of memory"));
	return (error_none());
}
