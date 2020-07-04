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
	struct s_program_prereq		all_arg;
	t_builtin					*builtin;
	t_error						err;

	ft_bzero(&all_arg, sizeof(all_arg));
	err = exec__set_arguments(&all_arg, command, env);
	if (is_error(err))
	{
		ft_dprintf(2, "tosh: %s\n", err.msg);
		exit(-1);
	}
	builtin = exec__identify_builtin(all_arg.argv[0]);
	if (builtin != NULL)
	{
		exit(builtin(all_arg.arg_count, all_arg.argv, env));
	}
	else
	{
		exec__identify_executable(&all_arg, env);
	}
}

static t_error	create_fork(t_list_meta *const pid_list,
					const int fd_transform[2],
					const struct s_simple_command *const command,
					t_env *const env)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		return (errorf("failed to fork"));
	}
	if (pid == 0)
	{
		if (fd_transform[read_from] != STDIN_FILENO)
		{
			if (dup2(fd_transform[read_from], STDIN_FILENO) == -1)
				ft_dprintf(2, "failed to dup pipes in fork");
		}
		if (fd_transform[write_to] != STDOUT_FILENO)
		{
			if (dup2(fd_transform[write_to], STDOUT_FILENO) == -1)
				ft_dprintf(2, "failed to dup pipes in fork");
		}
		handle_execution(command, env);
		exit(-1);
	}
	return (exec__expand_family(pid_list, pid));
}

static t_error	loop_sequence(t_list_meta *const pid_list,
					const struct s_pipe_sequence *sequence,
					t_env *const env)
{
	int			pipette[2];
	int			input_fd;
	t_error		err;

	err = error_none();
	input_fd = STDIN_FILENO;
	while (sequence && is_error(err) == false)
	{
		if (sequence->pipe_sequence == NULL)
			pipette[write_to] = STDOUT_FILENO;
		else if (pipe(pipette) == -1)
		{
			err = errorf("failed to create pipe");
			break ;
		}
		err = create_fork(pid_list, (int[2]){input_fd, pipette[write_to]},
			sequence->simple_command, env);
		close(pipette[write_to]);
		if (input_fd != STDIN_FILENO)
			close(input_fd);
		input_fd = pipette[read_from];
		sequence = sequence->pipe_sequence;
	}
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	return (err);
}

t_error			exec__sequence(struct s_exec_state *const status,
					const struct s_pipe_sequence *const sequence,
					t_env *const env)
{
	t_error		err;

	err = loop_sequence(&status->pid_list, sequence, env);
	if (is_error(err))
	{
		exec__kill_all_children(&status->pid_list, SIGTERM);
		env_set_exit_status(env, -1);
		return (err);
	}
	err = exec__child_process_control(env, status);
	return (err);
}
