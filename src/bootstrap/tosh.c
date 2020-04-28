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

#include <stdlib.h>
#include <ft_printf.h>
#include <unistd.h>
#include "../error/error.h"
#include "../term/term.h"
#include "../input/input.h"

void	tosh(void)
{
	char				*input;
	t_error				error;

	term_init(getenv("TERM"));
	error = input_read(&input, "TOSH $ ", 7);
	if (is_error(error))
	{
		ft_dprintf(STDERR_FILENO, "unable to read input: %s\n", error.msg);
		return ;
	}
}
