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

extern volatile sig_atomic_t	g_input__sigwinch;

enum					e_input__configure_action
{
	INPUT__CONFIGURE_SETUP,
	INPUT__CONFIGURE_RESTORE,
};

t_error					input__configure(t_term **term,
							enum e_input__configure_action action);

/*
** buffer           the text that the user has entered. Does not contain line
**                  wrapping.
** cursor_position  the position of the cursor relative to the buffer. Does not
**                  contain line wrapping.
** finished         set to true when the user finished by pressing return.
*/
struct					s_input__state
{
	char		*buffer;
	size_t		cursor_position;
	bool		finished;
	t_history	*history;
};

void					input__draw(struct s_input__state state,
							t_term *term,
							struct s_term_formatted_string prompt);

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
** Some special types include:
**
** INPUT__READ_NONE
**     Either nothing was read or something unrecognized was read.
** INPUT__READ_TEXT
**     Just a normal character, like 'a' and '$'.
*/
enum					e_input__read_type
{
	INPUT__READ_NONE,
	INPUT__READ_TEXT,
	INPUT__READ_ARROW_LEFT,
	INPUT__READ_ARROW_RIGHT,
	INPUT__READ_ARROW_UP,
	INPUT__READ_ARROW_DOWN,
	INPUT__READ_CONTROL_ARROW_LEFT,
	INPUT__READ_CONTROL_ARROW_RIGHT,
	INPUT__READ_CONTROL_A,
	INPUT__READ_CONTROL_E,
	INPUT__READ_BACKSPACE,
	INPUT__READ_RETURN,
	INPUT__READ_HOME,
	INPUT__READ_END,
};

/*
** s_input__keypress contains the processed input read by input__read_keypress.
**
** if .type == INPUT__READ_TEXT then .c contains the the char read.
*/
struct					s_input__keypress
{
	enum e_input__read_type	type;
	char					c;
};

/*
** t_read_func is a typedef of read used for depency injection.
*/
typedef ssize_t			t_read_func(int fildes, void *buf, size_t nbyte);

/*
** input__read_keypress reads input using read(2) and processes it to a
** s_input__read_keypress. seq->type will be INPUT__READ_TYPE_NONE if nothing
** was read.
*/
int						input__read_keypress(
							struct s_input__keypress *keypress,
							t_read_func read_func);

t_error					input__action_resize(t_term *term);

/*
** input__action_{left,right} moves the cursor by one. No action is taken if the
** cursor is already at the edge.
*/
t_error					input__action_left(struct s_input__state *state);
t_error					input__action_right(struct s_input__state *state);

/*
** input__action_word_{left,right} move the cursor word by word.
*/
t_error					input__action_word_left(struct s_input__state *state);
t_error					input__action_word_right(struct s_input__state *state);

/*
** input__action_max_{left,right} move the cursor to the start and end of the
** buffer.
*/
t_error					input__action_max_left(struct s_input__state *state);
t_error					input__action_max_right(struct s_input__state *state);

/*
** input__action_history_{up,down} moves through the history.
*/
t_error					input__action_history_up(struct s_input__state *state);
t_error					input__action_history_down(
							struct s_input__state *state);

/*
** input__action_insert inserts the character c at the cursor position.
*/
t_error					input__action_insert(struct s_input__state *state,
							char c);
t_error					input__action_backspace(struct s_input__state *state);

/*
** input__action_return is called when the return key is pressed and finishes
** the input.
*/
t_error					input__action_return(struct s_input__state *state);

t_error					input__run_next_action(
							struct s_input__state *state,
							t_term *term,
							bool *did_invalidate,
							t_read_func read_func);

#endif
