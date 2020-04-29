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

#include "private.h"

static t_error	hook_up_fork(t_list_meta *const pid_list,
					const int *const fd_transform[2],
					const struct s_simple_command *const command,
					const t_env *const env)
{
	__pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		return (errorf("failed to fork"));
	}
	if (pid == 0)
	{
		if (fd_transform[0] != NULL)
		{
			if (dup2(*fd_transform[0], 0) == -1)
				ft_dprintf(2, "failed to dup pipes in fork");
		}
		if (fd_transform[1] != NULL)
		{
			if (dup2(dup2(*fd_transform[1], 1) == -1))
				ft_dprintf(2, "failed to dup pipes in fork");
		}
		//insert further exec module here
		exit (-1);
	}
	return (exec__expand_family(pid_list, pid));
}

static t_error	loop_sequence(struct s_exec_state *const status,
					const int all_pipe[2][2],
					const struct s_pipe_sequence *sequence,
					const t_env *const env)
{
	t_error	err;
	bool	pipe_switch;
	int		*wires[2];

	err = error_none();
	pipe_switch = 0;
	wires[0] = NULL;
	wires[1] = &(all_pipe[1][1]);
	while (sequence)
	{
		if (!sequence->pipe_sequence)
		{
			wires[1] = NULL;
		}
		err = hook_up_fork(&(status->pid_list), wires,
				sequence->simple_command, env);
		if (is_error(err))
		{
			return (err) ;
		}
		wires[0] = &(all_pipe[!pipe_switch][0]);
		wires[1] = &(all_pipe[pipe_switch][1]);
		pipe_switch = !pipe_switch;
		sequence = sequence->pipe_sequence;
	}
	return (err);
}

t_error			exec__sequence(struct s_exec_state *const status,
					const struct s_pipe_sequence *sequence,
					t_env *const env)
{
	int		all_pipe[2][2];
	t_error	err;

	err = error_none();
	if (pipe(all_pipe[0]) == -1 || pipe(all_pipe[1]) == -1)
	{
		env_set_exit_status(env, 255);
		return(errorf("failed to create pipe"));
	}
	err = loop_sequence(status, all_pipe, sequence, env);
	close(all_pipe[0][0]);
	close(all_pipe[0][1]);
	close(all_pipe[1][0]);
	close(all_pipe[1][1]);
	if (is_error(err))
	{
		env_set_exit_status(env, 255);
		return (err);
	}
	return (exec__child_process_control(&status->pid_list, env, status));
}
