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

#include <assert.h>
#include <ft_printf.h>

#include "private.h"

extern volatile sig_atomic_t	g_terminate_sig;

void		exec_run(
				const struct s_complete_command *const complete_command,
				t_env *const env)
{
	struct s_exec__state	status;
	t_error					err;
	const struct s_list		*list;

	g_terminate_sig = 0; //remove later
	list = complete_command->list;
	ft_bzero(&status, sizeof(status));
	while (list && status.must_halt == 0)
	{
		assert(list->pipe_sequence != NULL); //parser error?
		err = error_none();
		if (list->pipe_sequence->pipe_sequence)
		{
			err = exec__sequence(&status, list->pipe_sequence, env);
		}
		else
		{
			err = exec__single(&status, list->pipe_sequence->simple_command, env);
		}
		if (is_error(err))
		{
			ft_dprintf(2, "Tosh: %s\n", err.msg); //malloc, fork err etc
		}
		list = list->list;
	}
	g_terminate_sig = 0; //nonsense if handling background proccesses(?)
}
