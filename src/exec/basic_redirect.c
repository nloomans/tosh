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

#include <assert.h>

#include "private.h"

const int g_default_fd_tbl[] = {
	[REDIRECT_IN] = 0, // O_WRONLY
	[REDIRECT_IN_AND] = 0,
	[REDIRECT_OUT] = 1, // O_RDONLY | O_TRUNC | O_CREAT
	[REDIRECT_OUT_APPEND] = 1, // O_RDONLY | O_APPEND | O_CREAT
	[REDIRECT_OUT_AND] = 1,
};

static bool	is_protected_fd(const int fd)
{
	if (fd == BACKUP_STDIN || fd == BACKUP_STDOUT || fd == BACKUP_STDERR)
	{
		return (true);
	}
	return (false);
}

t_error		exec__basic_redirect(struct s_all_redirection *const tracker,
				const struct s_io_redirect *const redir)
{
	int		first_fd;

	if (is_protected_fd(redir->fd) == true)
	{
		return (errorf("%d is a protected fd", redir->fd));
	}
	first_fd = (redir->fd == -1) ? g_default_fd_tbl[redir->file->type] : redir->fd;
	// if (redir->file->type == REDIRECT_IN)
	// {
	// 	// fd is 0
	// }
	// else if (redir->file->type == REDIRECT_IN_AND)
	// {
	// 	// fd is 0 cannot open files
	// }
	// else if (redir->file->type == REDIRECT_OUT)
	// {
	// 	// fd is 1
	// }
	// else if (redir->file->type == REDIRECT_OUT_APPEND)
	// {
	// 	//fd is 1
	// }
	// else if (redir->file->type == REDIRECT_OUT_AND)
	// {
	// 	// fd is 1 cannot open files
	// }
	(void)tracker;
	assert(!"WIP");
}
