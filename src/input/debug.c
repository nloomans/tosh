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
#include <ft_printf.h>
#include "private.h"

int input_debug(void)
{
	t_error				error;
	ssize_t				read_amount;
	char				buffer[4 + 1];

	error = input__configure(INPUT__CONFIGURE_SETUP);
	if (is_error(error))
	{
		return (ft_eprintf(1, "tosh: failed to configure terminal for "
			"interactive input: %s", error.msg));
	}
	while (true)
	{
		ft_memset(&buffer, '\0', sizeof(buffer));
		read_amount = read(STDIN_FILENO, &buffer, sizeof(buffer) - 1);
		if (read_amount == -1)
			return (ft_eprintf(1, "tosh: read syscall failed"));
		if (read_amount == 0)
			continue ;
		if (read_amount == 1 && buffer[0] == 'q')
			break ;
		ft_printf("%m", buffer, read_amount);
	}
	error = input__configure(INPUT__CONFIGURE_RESTORE);
	if (is_error(error))
	{
		return (ft_eprintf(1, "tosh: failed to restore terminal to previous "
			"state: %s", error.msg));
	}
	return (0);
}
