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

#include "../private.h"

const struct s_redirection_kvp	g_redir_tbl[] = {
	[REDIRECT_IN] = {.default_fd = 0, .handler = &redirect_in},// O_WRONLY
	[REDIRECT_IN_AND] = {.default_fd = 0, .handler = &redirect_in_and},
	[REDIRECT_OUT] = {.default_fd = 1, .handler = &redirect_out}, // O_RDONLY | O_TRUNC | O_CREAT
	[REDIRECT_OUT_APPEND] = {.default_fd = 1, .handler = &redirect_out_append}, // O_RDONLY | O_APPEND | O_CREAT
	[REDIRECT_OUT_AND] = {.default_fd = 1, .handler = &redirect_out_and},
};

static t_error	redirect(t_list_meta *const tracker_lst,
					const struct s_io_redirect *const redir,
					const t_env *const env)
{
	int								first_fd;
	const struct s_redirection_kvp	*redir_type;

	first_fd = redir->fd;
	if (redir->file)
	{
		redir_type = &g_redir_tbl[redir->file->type];
		if (first_fd == -1)
			first_fd = redir_type->default_fd;
		if (exec__is_protected_fd(first_fd) == true)
			return (errorf("%d is a protected fd", redir->fd));
		return (redir_type->handler(tracker_lst, first_fd, redir->file));
	}
	else
	{
		if (first_fd == -1)
			first_fd = 0;
		if (exec__is_protected_fd(first_fd) == true)
			return (errorf("%d is a protected fd", redir->fd));
		return (redirect_heredoc(tracker_lst, first_fd, redir->here, env));
	}
}

static t_error	recurse_prefix(t_list_meta *const tracker_lst,
					const struct s_cmd_prefix *const prefix,
					const t_env *const env)
{
	t_error		err;

	if (prefix == NULL)
	{
		return (error_none());
	}
	if (prefix->prefix)
	{
		err = recurse_prefix(tracker_lst, prefix, env);
		if (is_error(err))
		{
			return (err);
		}
	}
	err = redirect(tracker_lst, prefix->redirect, env);
	return (err);
}

static t_error	backup_fds(void)
{
	if (dup2(STDIN_FILENO, BACKUP_STDIN) == -1)
	{
		return (errorf("failed to duplicate stdinr"));
	}
	if (dup2(STDOUT_FILENO, BACKUP_STDOUT) == -1)
	{
		close(BACKUP_STDIN);
		return (errorf("failed to duplicate stdout"));
	}
	if (dup2(STDERR_FILENO, BACKUP_STDERR) == -1)
	{
		close(BACKUP_STDIN);
		close(BACKUP_STDOUT);
		return (errorf("failed to duplicate stderr"));
	}
	return (error_none());
}

t_error			exec__handle_redirections(
					t_list_meta *const tracker_lst,
					const struct s_simple_command *const command,
					const t_env *const env)
{
	t_error				err;
	struct s_cmd_suffix	*suffix;

	err = backup_fds();
	if (is_error(err))
		return (err);
	err = recurse_prefix(tracker_lst, command->prefix, env);
	if (is_error(err))
		return (err);
	suffix = command->suffix;
	while (suffix)
	{
		if (suffix->redirect)
		{
			err = redirect(tracker_lst, suffix->redirect, env);
			if (is_error(err))
			{
				return (err);
			}
		}
		suffix = suffix->suffix;
	}
	return (err);
}
