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

#ifndef TERM_H
# define TERM_H

# include <stddef.h>

# include "../error/error.h"

struct				s_term_pos
{
	size_t	row;
	size_t	column;
};

enum				e_term_configure_action
{
	TERM_CONFIGURE_SETUP,
	TERM_CONFIGURE_RESTORE,
};

/*
** term_init loads the termcap entry. Call this before all other term_*
** functions.
**
** Returns 0 on success and -1 on error.
*/
int					term_init(const char *term_env);

/*
** term_configure changes the termios table in ways needed for precise terminal
** manipulation.
*/
t_error				term_configure(enum e_term_configure_action action);

/*
** term_getsize gets the size of the terminal. The returned struct s_term_pos
** is equal to the maximum cursor row and column plus 1.
*/
int					term_getsize(struct s_term_pos *out);

void				term_clear_to_end(void);

enum				e_term_move
{
	TERM_MOVE_UP,
	TERM_MOVE_DOWN,
	TERM_MOVE_LINE_START,
	TERM_MOVE_RIGHT,
	TERM_MOVE_SAVE,
	TERM_MOVE_RESTORE,
};

void				term_cursor_move(enum e_term_move direction);

#endif
