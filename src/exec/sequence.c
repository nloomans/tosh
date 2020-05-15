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
#include <stdlib.h>

#include <ft_printf.h>
#include "private.h"

static void		handle_execution(const struct s_simple_command *const command,
					t_env *const env)
{
	struct s_program_prereqs	all_arg;
	t_builtin				*builtin;
	t_error					err;

	ft_bzero(&all_arg, sizeof(all_arg));
	err = exec__set_arguments(&all_arg, command, env);
	if (is_error(err))
	{
		ft_dprintf(2, "tosh: %s\n", err.msg);
		exit (-1); //arg creation err
	}
	builtin = exec__identify_builtin(all_arg.arg[0]);
	if (builtin != NULL)
	{
		exit(builtin(all_arg.arg_count, all_arg.arg, env));
	}
	else
	{
		exec__identify_executable(&all_arg);
	}
}

static t_error	hook_up_fork(t_list_meta *const pid_list,
					const int *const fd_transform[2],
					const struct s_simple_command *const command,
					t_env *const env)
{
	__pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		return (errorf("failed to fork"));
	}
	if (pid == 0)
	{
		if (fd_transform[read_from] != NULL)
		{
			if (dup2(*fd_transform[read_from], 0) == -1)
				ft_dprintf(2, "failed to dup pipes in fork");
		}
		if (fd_transform[write_to] != NULL)
		{
			if (dup2(*fd_transform[write_to], 1) == -1)
				ft_dprintf(2, "failed to dup pipes in fork");
		}
		handle_execution(command, env);
		exit(-1);
	}
	return (exec__expand_family(pid_list, pid));
}

static t_error	loop_over_sequence(t_list_meta *const pid_list,
					int all_pipe[2][2],
					const struct s_pipe_sequence *sequence,
					t_env *const env)
{
	enum e_pipe_ends	pipe_flip;
	const int			*redirs[2];
	t_error				err;

	err = error_none();
	pipe_flip = read_from;
	while (sequence)
	{
		if (sequence->pipe_sequence)
		{
			if (pipe(all_pipe[pipe_flip]) == -1)
			{
				err = errorf("failed to create pipe");
				break ;
			}
			redirs[write_to] = &all_pipe[pipe_flip][write_to];
		}
		redirs[read_from] = &all_pipe[!pipe_flip][read_from];
		err = hook_up_fork(pid_list, redirs, sequence->simple_command, env);
		if (is_error(err))
		{
			break ;
		}
		close(all_pipe[!pipe_flip][0]);
		close(all_pipe[!pipe_flip][1]);
		pipe_flip = !pipe_flip;
		sequence = sequence->pipe_sequence;
	}
	return (err);
}

t_error			exec__sequence(struct s_exec__state *const status,
					const struct s_pipe_sequence *sequence,
					t_env *const env)
{
	int					all_pipe[2][2];
	t_error				err;

	if (pipe(all_pipe[write_to]) == -1)
	{
		return (errorf("failed to create pipe"));
	}
	err = hook_up_fork(&status->pid_list,\
			(const int *[2]){NULL, &all_pipe[write_to][1]},\
			sequence->simple_command, env);
	if (is_error(err))
	{
		close(all_pipe[write_to][0]);
		close(all_pipe[write_to][1]);
		exec__kill_all_children(&status->pid_list);
		return (err);
	}
	err = loop_over_sequence(&status->pid_list, all_pipe, sequence->pipe_sequence, env);
	close(all_pipe[read_from][0]);
	close(all_pipe[read_from][1]);
	close(all_pipe[write_to][0]);
	close(all_pipe[write_to][1]);
	if (is_error(err))
	{
		exec__kill_all_children(&status->pid_list);
		return (err);
	}
	return (exec__child_process_control(env, status));
}
