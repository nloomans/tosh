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

const struct s_redirection_kvp	g_redir_tbl[] = {
	[REDIRECT_IN] = {.default_fd = 0, .handler = NULL},// O_WRONLY
	[REDIRECT_IN_AND] = {.default_fd = 0, .handler = NULL},
	[REDIRECT_OUT] = {.default_fd = 1, .handler = NULL}, // O_RDONLY | O_TRUNC | O_CREAT
	[REDIRECT_OUT_APPEND] = {.default_fd = 1, .handler = NULL}, // O_RDONLY | O_APPEND | O_CREAT
	[REDIRECT_OUT_AND] = {.default_fd = 1, .handler = NULL},
};

static t_error	redirect(struct s_all_redirection *const tracker,
					const struct s_io_redirect *const redir)
{
	int								first_fd;
	const struct s_redirection_kvp	*redir_type;

	if (redir->file)
	{
		redir_type = &g_redir_tbl[redir->file->type];
		first_fd = (redir->fd == -1) ? redir_type->default_fd : redir->fd;
		if (exec__is_protected_fd(first_fd) == true)
		{
			return (errorf("%d is a protected fd", redir->fd));
		}
		return (redir_type->handler(tracker, redir));
	}
	else
	{
		first_fd = (redir->fd == -1) ? 0 : redir->fd;
		if (exec__is_protected_fd(first_fd) == true)
		{
			return (errorf("%d is a protected fd", redir->fd));
		}
		//return (setup_heredoc(tracker, redir));
		assert(!"Help this is a heredoc i'm not qualified for that");
	}
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
	err = redirect(tracker, prefix->redirect);
	return (err);
}

static t_error	backup_fds(struct s_all_redirection *const tracker)
{
	tracker->back_up_fd[STDIN_FILENO] = dup2(STDIN_FILENO, BACKUP_STDIN);
	if (tracker->back_up_fd[STDIN_FILENO] == -1)
	{
		return (errorf("failed to duplicate stdinr"));
	}
	tracker->back_up_fd[STDOUT_FILENO] = dup2(STDOUT_FILENO, BACKUP_STDOUT);
	if (tracker->back_up_fd[STDOUT_FILENO] == -1)
	{
		close(tracker->back_up_fd[STDIN_FILENO]);
		return (errorf("failed to duplicate stdout"));
	}
	tracker->back_up_fd[STDERR_FILENO] = dup2(STDERR_FILENO, BACKUP_STDERR);
	if (tracker->back_up_fd[STDERR_FILENO] == -1)
	{
		close(tracker->back_up_fd[STDIN_FILENO]);
		close(tracker->back_up_fd[STDOUT_FILENO]);
		return (errorf("failed to duplicate stderr"));
	}
	return (error_none());
}

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
