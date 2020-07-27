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

#include "private.h"

void		exec__kill_all_children(t_list_meta *const pid_list, const int sig)
{
	struct s_child	*child_process;

	while (pid_list->first)
	{
		child_process = unpack_child(pid_list->first);
		ft_list_unlink(pid_list, &child_process->conn);
		exec__kill_child(child_process, sig);
	}
}
