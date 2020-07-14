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

#include "../private.h"

#include <stdio.h>
t_error			exec__add_tracker(const int dest_fd,
					const int new_fd,
					t_list_meta *const tracker_lst)
{
	struct s_redirection	*new_entry;

	new_entry = ft_memalloc(sizeof(*new_entry));
	if (new_entry == NULL)
	{
		return (errorf("failed to allocate memory"));
	}
	new_entry->origin_fd = new_fd;
	new_entry->dest_fd = dest_fd;
	dprintf(2, "dupping %d to %d\n", new_entry->origin_fd, new_entry->dest_fd);
	if (dup2(new_entry->origin_fd, new_entry->dest_fd) == -1)
	{
		free(new_entry);
		return (errorf("failed to duplicate fd"));
	}
	ft_list_insert(tracker_lst, tracker_lst->last, &new_entry->conn);
	return (error_none());
}

t_error			exec__undo_and_del_redir(t_list_meta *const tracker_lst)
{
	struct s_redirection	*iter;

	while (tracker_lst->len != 0)
	{
		iter = unpack_tracker(tracker_lst->first);
		ft_list_unlink(tracker_lst, tracker_lst->first);
		close(iter->origin_fd);
		close(iter->dest_fd);
		free(iter);
	}
	if (dup2(BACKUP_STDIN, STDIN_FILENO) == -1)
	{
		return (errorf("failed to restore STDIN"));
	}
	if (dup2(BACKUP_STDOUT, STDOUT_FILENO) == -1)
	{
		return (errorf("failed to restore STDOUT"));
	}
	if (dup2(BACKUP_STDERR, STDERR_FILENO) == -1)
	{
		return (errorf("failed to restore STDERR"));
	}
	return (error_none());
}
