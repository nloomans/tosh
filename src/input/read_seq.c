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

t_error					input__read_seq(struct s_input__read_seq *seq)
{
	ssize_t				read_amount;
	char				buffer[4 + 1];

	ft_memset(&buffer, '\0', sizeof(buffer));
	read_amount = read(STDIN_FILENO, &buffer, sizeof(buffer) - 1);
	if (read_amount == -1)
		return (errorf("read syscall failed"));
	if (read_amount == 0)
	{
		seq->type = INPUT__READ_TYPE_NONE;
		seq->c = '\0';
	}
	else if (buffer[0] == '\x1b' && buffer[1] == '[')
	{
		seq->type = buffer[3] == '~'
			? INPUT__READ_TYPE_ESC_SQL
			: INPUT__READ_TYPE_ESC;
		seq->c = buffer[2];
	}
	else
	{
		seq->type = INPUT__READ_TYPE_REG;
		seq->c = buffer[0];
	}
	return (error_none());
}
