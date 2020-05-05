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
# include <signal.h>
# include "input.h"
# include "../term/term.h"

volatile sig_atomic_t	g_input__sigwinch;

enum					e_input__configure_action
{
	INPUT__CONFIGURE_SETUP,
	INPUT__CONFIGURE_RESTORE,
};

t_error					input__configure(enum e_input__configure_action action);

/*
** terminal_columns the current width of the terminal.
** buffer           the text that the user has entered. Does not contain line
**                  wrapping.
** cursor_postion   the position of the cursor relative to the buffer. Does not
**                  contain line wrapping.
*/
struct					s_input__state
{
	size_t	terminal_columns;
	char	*buffer;
	size_t	cursor_position;
};

void					input__draw(struct s_input__state state,
						const struct s_input_formatted_string *prompt);

/*
** input__wrap_cursor will calculate the cursor position after the wrapping was
** applied. term_pos is relative to the first user input.
*/
struct s_term_pos		input__wrap_cursor(
							size_t terminal_width,
							size_t prompt_width,
							size_t cursor_pos);

/*
** t_input__action is a function which will perform a certain action on the
** state. Example actions include moving the cursor and updating the terminal
** size.
*/
typedef t_error			(*t_input__action)(struct s_input__state *state);

/*
** input__action_update_width reads out the width from the terminal and stores
** it in the state.
*/
t_error					input__action_update_width(
							struct s_input__state *state);

t_error					input__next_action(t_input__action *action);

#endif
