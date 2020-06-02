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
# include <unistd.h>
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
** cursor_position  the position of the cursor relative to the buffer. Does not
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
** e_input__read_type contains the type of input that was read by read(2).
**
** INPUT__READ_TYPE_NONE:
**     Nothing was read.
** INPUT__READ_TYPE_REG:
**     Just a normal chracter, like 'a', '$', and '\n'.
** INPUT__READ_TYPE_ESC:
**     A character prefixed by the '\x1b[' escape sequence.
** INPUT__READ_TYPE_ESC_SQL:
**     A character prefixed by the '\x1b[' escape sequence and suffixed by a
**     '~'.
*/
enum					e_input__read_type
{
    INPUT__READ_TYPE_NONE,
	INPUT__READ_TYPE_REG,
	INPUT__READ_TYPE_ESC,
	INPUT__READ_TYPE_ESC_SQL,
};

/*
** s_input__keypress contains the processed input read by input__read_keypress.
*/
struct					s_input__keypress
{
	enum e_input__read_type	type;
	char					c;
};

/*
**
*/
typedef ssize_t			t_read_func(int, void *, size_t);

/*
** input__read_keypress reads input using read(2) and processes it to a
** s_input__read_keypress. seq->type will be INPUT__READ_TYPE_NONE if nothing was
** read.
*/
t_error					input__read_keypress(
							struct s_input__keypress *keypress,
							t_read_func read_func);

/*
** input__action_update_width reads out the width from the terminal and stores
** it in the state.
*/
t_error					input__action_update_width(
							struct s_input__state *state);

/*
** input__action_{left,right} moves the cursor by one. No action is taken if the
** cursor is already at the edge.
*/
t_error					input__action_left(struct s_input__state *state);
t_error					input__action_right(struct s_input__state *state);

/*
** input__action_insert inserts the character c at the cursor position.
*/
t_error					input__action_insert(struct s_input__state *state,
							char c);
t_error					input__action_backspace(struct s_input__state *state);

t_error					input__run_next_action(
							struct s_input__state *state,
							bool *did_invalidate,
							t_read_func read_func);

#endif
