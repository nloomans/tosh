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

static void	reposition_cursor(size_t current_cursor_row, struct s_term_pos dest)
{
	size_t	amount_to_move;
	size_t	i;

	amount_to_move = current_cursor_row;
	i = 0;
	while (i < amount_to_move)
	{
		term_cursor_move(TERM_MOVE_UP);
		i++;
	}
	term_cursor_move(TERM_MOVE_LINE_START);
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

static void	draw_text(struct s_input__draw_state *draw_state,
				struct s_input__state state, const char *prompt)
{
	size_t		line_count;
	char		**lines;

	reposition_cursor(draw_state->cursor_row, (struct s_term_pos){0, 0});
	draw_state->cursor_row = 0;
	line_count = input__wrap(&lines,
		state.terminal_rows, ft_strlen(prompt), state.buffer);
	draw_state->claimed_columns = draw_state->claimed_columns > line_count
		? draw_state->claimed_columns
		: line_count;
	ft_dprintf(STDERR_FILENO, "%{green}%s%{reset}", prompt);
	while (true)
	{
		term_clearline();
		ft_dprintf(STDERR_FILENO, "%s", lines[draw_state->cursor_row]);
		if (draw_state->cursor_row + 1 < draw_state->claimed_columns)
		{
			term_cursor_move(TERM_MOVE_DOWN);
			draw_state->cursor_row++;
		}
		else
			break ;
	}
	ft_arraydel((void ***)&lines, ft_memdel);
}

void		input__draw(struct s_input__draw_state *draw_state,
				struct s_input__state state)
{
	const char	prompt[] = "tosh $ ";

	draw_text(draw_state, state, prompt);
	reposition_cursor(draw_state->cursor_row,
		input__wrap_cursor(state.terminal_rows, ft_strlen(prompt),
			state.cursor_position));
}
