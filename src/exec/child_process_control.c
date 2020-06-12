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
#include <sys/wait.h>
#include <assert.h>

#include "private.h"

static t_error	remove_zombie_process(const pid_t zombie_pid,
					t_list_conn *const cur_node,
					t_list_meta *const pid_list)
{
	struct s_child	*child_process;
	t_error			err;

	if (cur_node == NULL)
	{
		return (errorf("pid_t %d not found in process list", zombie_pid));
	}
	child_process = unpack_child(cur_node);
	if (child_process->pid == zombie_pid)
	{
		ft_list_unlink(pid_list, &child_process->conn);
		ft_bzero(child_process, sizeof(*child_process));
		free(child_process);
		return (error_none());
	}
	err = remove_zombie_process(zombie_pid, cur_node->next, pid_list);
	if (is_error(err))
	{
		return (err);
	}
	ft_list_unlink(pid_list, &child_process->conn);
	exec__kill_child(child_process, SIGTERM);
	return (error_none());
}

static t_error	wait_step(struct s_child **const alast_child,
					t_list_meta *const pid_list,
					t_env *const env)
{
	pid_t		zombie_pid;
	int			status;

	zombie_pid = waitpid(-1, &status, WNOHANG);
	if (zombie_pid == -1)
	{
		return (errorf("error waiting for child process"));
	}
	if (zombie_pid == 0)
	{
		return (error_none());
	}
	if (*alast_child && (*alast_child)->pid == zombie_pid)
	{
		if (WIFEXITED(status))
		{
			env_set_exit_status(env, WEXITSTATUS(status));
		}
		else
		{
			env_set_exit_status(env, 127);
		}
		*alast_child = NULL;
	}
	return (remove_zombie_process(zombie_pid, pid_list->first, pid_list));
}

t_error			exec__child_process_control(t_env *const env,
					struct s_exec_state *const status)
{
	t_error			err;
	struct s_child	*last_child;

	assert(status->pid_list.len != 0);
	last_child = unpack_child(status->pid_list.last);
	while (status->pid_list.len != 0 && g_terminate_sig == 0)
	{
		err = wait_step(&last_child, &status->pid_list, env);
		if (is_error(err))
			break ;
	}
	if (is_error(err))
	{
		exec__kill_all_children(&status->pid_list, SIGTERM);
		env_set_exit_status(env, 255);
		return (err);
	}
	if (g_terminate_sig == 1)
	{
		exec__kill_all_children(&status->pid_list, SIGINT);
		env_set_exit_status(env, 255);
		g_terminate_sig = 0;
		status->must_halt = 1;
	}
	return (error_none());
}
