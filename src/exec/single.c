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

#include "private.h"

static t_error	create_fork(struct s_program_prereq *const all_arg,
					struct s_exec__state *const status,
					t_env *const env)
{
	t_error					err;
	pid_t					pid;

	pid = fork();
	if (pid == -1)
	{
		return (errorf("failed to fork"));
	}
	if (pid == 0)
	{
		exec__identify_executable(all_arg, env);
		exit(-1);
	}
	err = exec__expand_family(&(status->pid_list), pid);
	if (is_error(err))
	{
		exec__kill_all_children(&(status->pid_list));
		return (err);
	}
	return (exec__child_process_control(env, status));
}

t_error			exec__single(struct s_exec__state *const status,
					const struct s_simple_command *const command,
					t_env *const env)
{
	struct s_program_prereq	all_arg;
	t_builtin				*builtin;
	t_error					err;

	ft_bzero(&all_arg, sizeof(all_arg));
	err = exec__set_arguments(&all_arg, command, env);
	if (is_error(err))
	{
		return (err);
	}
	builtin = exec__identify_builtin(all_arg.arg[0]);
	if (builtin != NULL)
	{
		env_set_exit_status(env,\
			builtin(all_arg.arg_count, all_arg.arg, env));
	}
	else
	{
		err = create_fork(&all_arg, status, env);
	}
	exec__clear_arguments(&all_arg);
	return (err);
}
