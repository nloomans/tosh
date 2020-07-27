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

static int						read_char(char *c, t_read_func read_func)
{
	*c = '\0';
	return (read_func(BACKUP_STDIN, c, 1));
}

static enum e_input__read_type	cursor_key(char c)
{
	if (c == 'D')
		return (INPUT__READ_ARROW_LEFT);
	if (c == 'C')
		return (INPUT__READ_ARROW_RIGHT);
	if (c == 'A')
		return (INPUT__READ_ARROW_UP);
	if (c == 'B')
		return (INPUT__READ_ARROW_DOWN);
	if (c == 'H')
		return (INPUT__READ_HOME);
	if (c == 'F')
		return (INPUT__READ_END);
	return (INPUT__READ_NONE);
}

/*
** Reference: https://invisible-island.net/xterm/ctlseqs/ctlseqs.html
**            #h2-PC-Style-Function-Keys
*/

static int						read_modifier(
									struct s_input__keypress *keypress,
									t_read_func read_func)
{
	char	c;

	if (read_char(&c, read_func) == -1)
		return (-1);
	if (c != ';')
		return (0);
	if (read_char(&c, read_func) == -1)
		return (-1);
	if (c == '2')
		keypress->modifier = INPUT__MODIFIER_SHIFT;
	else if (c == '5')
		keypress->modifier = INPUT__MODIFIER_CONTROL;
	else if (c == '6')
		keypress->modifier = INPUT__MODIFIER_SHIFT | INPUT__MODIFIER_CONTROL;
	else
		return (0);
	if (read_char(&c, read_func) == -1)
		return (-1);
	keypress->type = cursor_key(c);
	return (0);
}

static int						read_escape(struct s_input__keypress *keypress,
									t_read_func read_func)
{
	char c;

	if (read_char(&c, read_func) == -1)
		return (-1);
	if (c == '[')
	{
		if (read_char(&c, read_func) == -1)
			return (-1);
		if (c == '1')
			return (read_modifier(keypress, read_func));
		keypress->type = cursor_key(c);
	}
	return (0);
}

int								input__read_keypress(
									struct s_input__keypress *keypress,
									t_read_func read_func)
{
	char	c;

	ft_memset(keypress, '\0', sizeof(*keypress));
	if (read_char(&c, read_func) == -1)
		return (-1);
	if (c == '\x1b')
		return (read_escape(keypress, read_func));
	if (c == '\x7f')
		keypress->type = INPUT__READ_BACKSPACE;
	else if (c == '\n')
		keypress->type = INPUT__READ_RETURN;
	else if (c == '\t')
		keypress->type = INPUT__READ_TAB;
	else if (c >= 1 && c <= 1 + 'Z' - 'A')
	{
		keypress->modifier = INPUT__MODIFIER_CONTROL;
		keypress->type = INPUT__READ_TEXT;
		keypress->c = c + 'A' - 1;
	}
	else if (ft_isprint(c))
	{
		keypress->type = INPUT__READ_TEXT;
		keypress->c = c;
	}
	return (0);
}
