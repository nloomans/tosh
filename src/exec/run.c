/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ft_printf.h>

#include "private.h"

__sig_atomic_t		g_terminate_sig = 0;

void		exec_run(
				const struct s_complete_command *const complete_command,
				const t_env *const env)
{
	struct s_exec_state	status;
	t_error				err;
	const struct s_list	*list;

	list = complete_command->list;
	status.must_halt = false;
	while (list && status.must_halt == 1)
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
	g_terminate_sig = 0; //nonsense if handling background proccesses
}
