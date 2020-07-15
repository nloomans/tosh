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

#ifndef INPUT_H
# define INPUT_H

# include "../error/error.h"
# include "../history/history.h"
# include "../term/term.h"

/*
** e_input_exit_reason describes the reason input_read finished.
**
** INPUT_EXIT_REASON_NONE:   We didn't exit yet. Only used internally.
** INPUT_EXIT_REASON_SUBMIT: The user pressed return.
** INPUT_EXIT_REASON_CANCEL: The user pressed control + c or an internal error
**                           occurred.
** INPUT_EXIT_REASON_DONE:   The user pressed control + d at the start of the
**                           line.
*/
enum		e_input_exit_reason
{
	INPUT_EXIT_REASON_NONE,
	INPUT_EXIT_REASON_SUBMIT,
	INPUT_EXIT_REASON_CANCEL,
	INPUT_EXIT_REASON_DONE,
};

struct		s_input_read_result
{
	enum e_input_exit_reason	exit_reason;
	char						*text;
};

/*
** history        opaque struct for managing the history. Can be NULL for
**                disabled history support.
** copied_text    the text to be pasted if the user wishes so.
*/

struct		s_input_persistent
{
	t_history	*history;
	char		*copied_text;
};

/*
** input_read reads a single line of input. prompt contains the text to
** display before the input.
**
** Text wrapping is handled automatically.
*/
t_error		input_read(struct s_input_read_result *dest,
				struct s_input_persistent *persistent_state,
				struct s_term_formatted_string prompt);

/*
** input_debug prints useful debug information about the current keys pressed.
** It can be accessed using 'tosh -d input'
*/
int			input_debug(void);

#endif
