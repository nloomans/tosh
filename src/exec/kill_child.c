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
#include <signal.h>
#include <stdlib.h>
#include <assert.h>

#include "private.h"

void	exec__kill_child(struct s_child *const child_process, const int sig)
{
	pid_t			ret;

	kill(child_process->pid, sig);
	ret = waitpid(child_process->pid, NULL, 0);
	assert(ret != -1);
	ft_bzero(child_process, sizeof(*child_process));
	free(child_process);
}
