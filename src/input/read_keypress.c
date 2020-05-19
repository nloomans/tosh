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

t_error					input__read_keypress(
							struct s_input__keypress *keypress,
							t_read_func read_func)
{
	ssize_t				read_amount;
	char				buffer[4 + 1];

	ft_memset(&buffer, '\0', sizeof(buffer));
	read_amount = read_func(STDIN_FILENO, &buffer, sizeof(buffer) - 1);
	if (read_amount == -1)
		return (errorf("read syscall failed"));
	if (read_amount == 0)
	{
		keypress->type = INPUT__READ_TYPE_NONE;
		keypress->c = '\0';
	}
	else if (buffer[0] == '\x1b' && buffer[1] == '[')
	{
		keypress->type = buffer[3] == '~'
			? INPUT__READ_TYPE_ESC_SQL
			: INPUT__READ_TYPE_ESC;
		keypress->c = buffer[2];
	}
	else
	{
		keypress->type = INPUT__READ_TYPE_REG;
		keypress->c = buffer[0];
	}
	return (error_none());
}
