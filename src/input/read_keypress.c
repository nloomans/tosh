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

#include <unistd.h>
#include <libft.h>

#include "private.h"

static int				read_char(char *c, t_read_func read_func)
{
	*c = '\0';
	return (read_func(STDIN_FILENO, c, 1));
}

static int				read_escape(struct s_input__keypress *keypress,
							t_read_func read_func)
{
	char c;

	if (read_char(&c, read_func) == -1)
		return (-1);
	if (c == '[')
	{
		if (read_char(&c, read_func) == -1)
			return (-1);
		if (c == 'D')
			keypress->type = INPUT__READ_ARROW_LEFT;
		else if (c == 'C')
			keypress->type = INPUT__READ_ARROW_RIGHT;
		else if (c == 'A')
			keypress->type = INPUT__READ_ARROW_UP;
		else if (c == 'B')
			keypress->type = INPUT__READ_ARROW_DOWN;
	}
	return (0);
}

int						input__read_keypress(
							struct s_input__keypress *keypress,
							t_read_func read_func)
{
	char	c;

	ft_memset(keypress, '\0', sizeof(*keypress));
	if (read_char(&c, read_func) == -1)
		return (-1);
	if (c == '\x1b')
	{
		if (read_escape(keypress, read_func) == -1)
			return (-1);
	}
	else if (c == '\x7f')
		keypress->type = INPUT__READ_BACKSPACE;
	else if (c == '\n')
		keypress->type = INPUT__READ_RETURN;
	else if (ft_isprint(c))
	{
		keypress->type = INPUT__READ_TEXT;
		keypress->c = c;
	}
	return (0);
}
