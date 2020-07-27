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

static t_error	print_input(void)
{
	char				buffer[16 + 1];
	ssize_t				read_amount;

	while (true)
	{
		ft_memset(&buffer, '\0', sizeof(buffer));
		read_amount = read(BACKUP_STDIN, &buffer, sizeof(buffer) - 1);
		if (read_amount == -1)
			return (errorf("read syscall failed"));
		if (read_amount == 0)
			continue ;
		if (read_amount == 1 && buffer[0] == 'q')
			break ;
		ft_printf("%m", buffer, read_amount);
	}
	return (error_none());
}

int				input_debug(void)
{
	t_error				error;
	t_term				*term;

	error = input__configure(&term, INPUT__CONFIGURE_SETUP);
	if (is_error(error))
	{
		return (ft_eprintf(1, "tosh: failed to configure terminal for "
			"interactive input: %s\n", error.msg));
	}
	error = print_input();
	if (is_error(error))
		return (ft_eprintf(1, "tosh: %s\n", error.msg));
	error = input__configure(&term, INPUT__CONFIGURE_RESTORE);
	if (is_error(error))
	{
		return (ft_eprintf(1, "tosh: failed to restore terminal to previous "
			"state: %s\n", error.msg));
	}
	return (0);
}
