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
#include "../history/history.h"
#include "../input/input.h"

/*
** TODO: Consider using ft_getline if TERM is unknown.
*/

void			tosh(void)
{
	t_error				error;
	char				*input;
	char				prompt[32];
	t_history			*history;

	error = history_create(&history);
	if (is_error(error))
	{
		ft_dprintf(STDERR_FILENO,
			"tosh: failed to enable history support: %s\n", error.msg);
	}
	ft_snprintf(prompt, sizeof(prompt), "%{green}TOSH $ %{reset}");
	while (true)
	{
		error = input_read(&input, history,
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
