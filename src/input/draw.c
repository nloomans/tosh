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
#include <unistd.h>

#include "../term/term.h"
#include "private.h"

void		input__draw(
				struct s_input__state state,
				t_term *term,
				struct s_term_formatted_string prompt)
{
	term->cursor_goto(term, term->saved_pos);
	term->clear_to_end();
	term->print(term, prompt);
	term->print(term, (struct s_term_formatted_string){
		state.buffer, ft_strlen(state.buffer)});
	term->cursor_goto(term, term_wrap(term->terminal_size.column,
		term->saved_pos, prompt.width + state.cursor_position));
}
