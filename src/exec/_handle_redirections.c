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
#include <unistd.h>

#include "private.h"

#include <stdio.h>
static t_error	redirect(struct s_all_redirection *const tracker,
					const struct s_io_redirect *const redir)
{
	(void)redir; //ignoring redir for now
	(void)tracker;
	if (redir->file)
	{
		printf("%s\n", redir->file->filename);
	}
	
	return (error_none());
}

static t_error	recurse_prefix(struct s_all_redirection *const tracker,
					const struct s_cmd_prefix *const prefix)
{
	t_error		err;

	if (prefix == NULL)
	{
		return (error_none());
	}
	if (prefix->prefix)
	{
		err = recurse_prefix(tracker, prefix);
		if (is_error(err))
		{
			return (err);
		}
	}
	err = redirect(tracker, prefix->redirect); //might need to be iff protected
	return (err);
}

static t_error	backup_fds(struct s_all_redirection *const tracker)
{
	tracker->back_up_fd[STDIN_FILENO] = dup2(STDIN_FILENO, BACKUP_STDIN);
	if (tracker->back_up_fd[STDIN_FILENO] != -1)
	{
		tracker->back_up_fd[STDOUT_FILENO] = dup2(STDOUT_FILENO, BACKUP_STDOUT);
		if (tracker->back_up_fd[STDOUT_FILENO] != -1)
		{
			tracker->back_up_fd[STDERR_FILENO] = dup2(STDERR_FILENO, BACKUP_STDERR);
			if (tracker->back_up_fd[STDERR_FILENO] != -1)
			{
				return (error_none());
			}
			close(tracker->back_up_fd[STDOUT_FILENO]);
		}
		close(tracker->back_up_fd[STDIN_FILENO]);
	}
	return (errorf("failed to duplicate File Descriptor"));
}

// static t_error	backup_fds(struct s_all_redirection *const tracker)
// {
// 	tracker->back_up_fd[STDIN_FILENO] = dup2(STDIN_FILENO, BACKUP_STDIN);
// 	if (tracker->back_up_fd[STDIN_FILENO] == -1)
// 	{
// 		return (errorf("failed to duplicate File Descriptor"));
// 	}
// 	tracker->back_up_fd[STDOUT_FILENO] = dup2(STDOUT_FILENO, BACKUP_STDOUT);
// 	if (tracker->back_up_fd[STDOUT_FILENO] == -1)
// 	{
// 		close(tracker->back_up_fd[STDIN_FILENO]);
// 		return (errorf("failed to duplicate File Descriptor"));
// 	}
// 	tracker->back_up_fd[STDERR_FILENO] = dup2(STDERR_FILENO, BACKUP_STDERR);
// 	if (tracker->back_up_fd[STDERR_FILENO] == -1)
// 	{
// 		close(tracker->back_up_fd[STDIN_FILENO]);
// 		close(tracker->back_up_fd[STDOUT_FILENO]);
// 		return (errorf("failed to duplicate File Descriptor"));
// 	}
// 	return (error_none());
// }

t_error			exec__handle_redirections(
					struct s_all_redirection *const tracker,
					const struct s_simple_command *const command)
{
	t_error				err;
	struct s_cmd_suffix	*suffix;

	err = backup_fds(tracker);
	if (is_error(err))
		return (err);
	err = recurse_prefix(tracker, command->prefix);
	if (is_error(err))
		return (err);
	suffix = command->suffix;
	while (suffix)
	{
		if (suffix->redirect)
		{
			err = redirect(tracker, suffix->redirect);
			if (is_error(err))
			{
				return (err);
			}
		}
		suffix = suffix->suffix;
	}
	return (err);
}