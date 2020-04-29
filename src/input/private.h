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

#ifndef PRIVATE_H
# define PRIVATE_H

# include <stddef.h>
# include "../term/term.h"

/*
** terminal_rows    the current width of the terminal.
** buffer           the text that the user has entered. Does not contain line
**                  wrapping.
** cursor_postion   the position of the cursor relative to the buffer. Does not
**                  contain line wrapping.
*/
struct		s_input__state
{
	size_t	terminal_rows;
	char	*buffer;
	size_t	cursor_position;
};

/*
** This struct contains information that needs to be preserved between draw
** calls. input__draw may write to this.
**
** claimed_columns  the amount of columns we use for drawing. This number can
**                  only go up.
** cursor_row       the row relative to the input line the cursor is right now.
*/

struct		s_input__draw_state
{
	size_t	claimed_columns;
	size_t	cursor_row;
};

void		input__draw(struct s_input__draw_state *draw_state,
				struct s_input__state state);

/*
** input__wrap places the newlines at the best position in the buffer. buffer
** shall not contain any newlines. The prompt width is taken into account.
**
** The return value equals the amount of lines and dest contains the wrapped
** buffer.
*/

size_t			input__wrap(
					char ***dest,
					size_t terminal_width,
					size_t prompt_width,
					const char *buffer);

/*
** input__wrap_cursor will calculate the cursor position after the wrapping was
** applied. term_pos is relative to the first user input.
*/
struct s_term_pos	input__wrap_cursor(
						size_t terminal_width,
						size_t prompt_width,
						size_t cursor_pos);

#endif
