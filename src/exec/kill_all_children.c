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
#include <stdlib.h>
#include <signal.h>

#include <assert.h>

#include "private.h"

void		exec__kill_all_children(t_list_meta *const pid_list)
{
	struct s_child	*child_process;
	__pid_t			ret;

	while (pid_list->first)
	{
		child_process = unpack_child(pid_list->first);
		ft_list_unlink(pid_list, pid_list->first);
		kill(child_process->pid, SIGINT);
		ret = 0;
		while (ret != 0)
		{
			ret = waitpid(child_process->pid, NULL, WNOHANG);//think about zombies and error return
		}
		assert(ret != -1); //programming error;
		ft_bzero(child_process, sizeof(*child_process));
		free(child_process);
	}
}
