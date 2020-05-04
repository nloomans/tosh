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
# include "input.h"
# include "../term/term.h"

/*
** terminal_columns the current width of the terminal.
** buffer           the text that the user has entered. Does not contain line
**                  wrapping.
** cursor_postion   the position of the cursor relative to the buffer. Does not
**                  contain line wrapping.
*/
struct				s_input__state
{
	size_t	terminal_columns;
	char	*buffer;
	size_t	cursor_position;
};

void				input__draw(struct s_input__state state,
						const struct s_input_formatted_string *prompt);

/*
** input__wrap_cursor will calculate the cursor position after the wrapping was
** applied. term_pos is relative to the first user input.
*/
struct s_term_pos	input__wrap_cursor(
						size_t terminal_width,
						size_t prompt_width,
						size_t cursor_pos);

#endif
