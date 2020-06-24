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
# include <termios.h>
# include "../error/error.h"

struct					s_term_pos
{
	size_t	row;
	size_t	column;
};

/*
** s_term_formatted_string is a string with possibly control codes embedded
** in it. The width represents the amount of columns the cursor will move
** forward when printing the string.
*/
struct					s_term_formatted_string
{
	const char	*string;
	size_t		width;
};

/*
** t_term is a class-ish for drawing to the terminal. Only one instance of
** t_term may exist at a time. An instance can be created using term_setup and
** most be destroyed using term_restore.
**
** The cursor position is saved on setup. It is automatically kept up-to-date
** when using cursor_goto and print.
**
** Call handle_resize every time the terminal resizes. The cursor position will
** restored to the saved position.
**
** clear_to_end wipes out the terminal from the cursor position to the end of
** the terminal.
*/
typedef struct s_term	t_term;

struct					s_term
{
	struct s_term_pos	cursor_pos;
	struct s_term_pos	saved_pos;
	struct s_term_pos	terminal_size;
	struct termios		original_termios;
	t_error				(*handle_resize)(t_term *self);
	void				(*cursor_goto)(t_term *self,
							struct s_term_pos new_pos);
	void				(*print)(t_term *self,
							struct s_term_formatted_string formatted_string);
	void				(*clear_to_end)(void);
};

/*
** term_setup creates a initializes and saves the t_term instance. Calling this
** function when a t_term already exists results in undefined behavior.
*/
t_error					term_setup(t_term **out, const char *term_env);

/*
** term_restore restores the terminal configuration to before term_setup was
** called. t_term is always replaced with NULL and term_setup may be called
** again, even when term_restore returns an error.
*/
t_error					term_restore(t_term **out);

int						term_getsize(struct s_term_pos *out);

struct s_term_pos		term_wrap(size_t terminal_width,
							struct s_term_pos start, size_t width);

#endif
