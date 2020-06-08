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

static void	reposition_cursor(struct s_term_pos dest)
{
	size_t	amount_to_move;
	size_t	i;

	term_cursor_move(TERM_MOVE_RESTORE);
	amount_to_move = dest.row;
	i = 0;
	while (i < amount_to_move)
	{
		term_cursor_move(TERM_MOVE_DOWN);
		i++;
	}
	amount_to_move = dest.column;
	i = 0;
	while (i < amount_to_move)
	{
		term_cursor_move(TERM_MOVE_RIGHT);
		i++;
	}
}

void		input__draw(struct s_input__state state,
				const struct s_input_formatted_string *prompt)
{
	struct s_term_pos	cursor_pos;

	reposition_cursor((struct s_term_pos){0, 0});
	term_clear_to_end();
	ft_dprintf(STDERR_FILENO, "%s%s", prompt->string, state.buffer);
	cursor_pos = input__wrap_cursor(state.terminal_columns, prompt->width,
			state.cursor_position);
	reposition_cursor(cursor_pos);
}
