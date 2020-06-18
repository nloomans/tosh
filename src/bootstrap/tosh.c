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
#include "../input/input.h"

/*
** TODO: Consider using ft_getline if TERM is unknown.
*/

void	tosh(void)
{
	char				*input;
	t_error				error;
	char				prompt[32];

	ft_snprintf(prompt, sizeof(prompt), "%{green}TOSH $ %{reset}");
	while (true)
	{
		error = input_read(&input,
			(struct s_term_formatted_string){prompt, 7});
		if (is_error(error))
		{
			ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to read input: %s\n",
				error.msg);
			exit(1);
		}
		ft_printf("input_read: %s\n", input);
	}
}
