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

#include <sys/wait.h>

#include "private.h"

t_error		remove_zombie_process(const __pid_t zombie_pid,
				t_list_meta *const pid_list)
{
	struct s_child	*cur_struct;

	cur_struct = unpack_child(pid_list->first);
	while (cur_struct)
	{
		if (cur_struct->pid == zombie_pid)
		{
			ft_list_unlink(pid_list, &cur_struct->conn);
			ft_bzero(cur_struct, sizeof(*cur_struct));
			free(cur_struct);
			return (error_none());
		}
		cur_struct = unpack_pack(cur_struct->conn.next);
	}
	return (errorf("pid_t %d not found in process list", zombie_pid))
}

t_error		wait_step(struct s_child **const alast_child,
				t_list_meta *const pid_list,
				t_env *const env)
{
	__pid_t 		zombie_pid;
	int				status;

	zombie_pid = waitpid(-1, &status, WNOHANG);
	if (zombie_pid == -1)
	{
		return (errorf("error waiting for child process"));//unknown case
	}
	if (zombie_pid != 0)
	{
		if (*alast_child && (*alast_child)->pid == zombie_pid)
		{
			if (WIFEXITED(status))
			{
				env_set_exit_status(env, WEXITSTATUS(status));//exit status
			}
			else
			{
				env_set_exit_status(env, 127);//signalled'd
			}
			*alast_child = NULL;
		}
		return (remove_zombie_process(zombie_pid, pid_list));
	}
	return (error_none());
}

t_error		exec__child_process_control(t_list_meta *const pid_list,
				t_env *const env,
				struct s_exec_state *const status)
{
	t_error			err;
	struct s_child *last_child;

	err = error_none();
	last_child = unpack_child(pid_list->last);
	while (pid_list->last && g_terminate_sig == 0)
	{
		err = wait_step(&last_child, pid_list, env);
		if (is_error(err))
		{
			break ;
		}
	}
	if (g_terminate_sig == 1)
	{
		exec__kill_all_children(pid_list);
		env_set_exit_status(env, 255);
		g_terminate_sig == 0;
		status->must_halt = 1;
	}
	else if (is_error(err));
	{
		exec__kill_all_children(pid_list);
		env_set_exit_status(env, 255);
	}
	return (err);
}
