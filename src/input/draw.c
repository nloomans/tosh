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
#include <ft_printf.h>

#include "../term/term.h"
#include "private.h"

static void	print_with_selection(t_term *term,
				const char *buffer, size_t start, size_t end)
{
	char	*marked_buffer;

	assert(start <= end);
	assert(end <= ft_strlen(buffer));
	ft_asprintf(&marked_buffer, "%.*s%{underline}%.*s%{reset}%s",
		start, buffer,
		end - start, buffer + start,
		buffer + end);
	term->print(term,
		(struct s_term_formatted_string){marked_buffer, ft_strlen(buffer)});
	ft_strdel(&marked_buffer);
}

void		input__draw(
				struct s_input__state state,
				t_term *term,
				struct s_term_formatted_string prompt)
{
	term->cursor_goto(term, term->saved_pos);
	term->clear_to_end();
	term->print(term, prompt);
	if (state.select_start == -1)
		term->print(term, (struct s_term_formatted_string){
			state.buffer, ft_strlen(state.buffer)});
	else if ((size_t)state.select_start < state.cursor_position)
		print_with_selection(term, state.buffer,
			state.select_start, state.cursor_position);
	else
		print_with_selection(term, state.buffer,
			state.cursor_position, state.select_start);
	term->cursor_goto(term, term_wrap(term->terminal_size.column,
		term->saved_pos, prompt.width + state.cursor_position));
}
