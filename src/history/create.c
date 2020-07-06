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

#include <libft.h>
#include <ft_printf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "private.h"

static t_error	fill_list(t_list_meta *list, const char *input)
{
	const char				*newline;
	struct s_history__line	*new;

	while (true)
	{
		newline = ft_strchr(input, '\n');
		if (newline == NULL)
			return (error_none());
		new = ft_memalloc(sizeof(*new));
		if (new == NULL)
			return (errorf("out of memory"));
		new->buffer = ft_strsub(input, 0, newline - input);
		if (new->buffer == NULL)
		{
			ft_memdel((void **)&new);
			return (errorf("out of memory"));
		}
		ft_list_insert(list, list->last, &new->conn);
		input = newline + 1;
	}
}

static t_error	initialize(t_history *self, const char *history_file_path)
{
	t_error	error;
	char	*contents;

	contents = NULL;
	self->fd = open(history_file_path, O_RDWR | O_APPEND | O_CREAT, 0600);
	if (self->fd == -1)
		return (errorf("unable to open %s", history_file_path));
	error = history__read_all(&contents, self->fd);
	if (is_error(error))
	{
		close(self->fd);
		return (errorf("unable to read %s: %s", history_file_path, error.msg));
	}
	error = fill_list(&self->lines, contents);
	ft_strdel(&contents);
	if (is_error(error))
	{
		close(self->fd);
		return (errorf("unable to parse %s: %s", history_file_path, error.msg));
	}
	return (error_none());
}

t_error			history_create_at(t_history **history,
					const char *history_file_path)
{
	t_error	error;

	*history = ft_memalloc(sizeof(**history));
	if (*history == NULL)
		return (errorf("out of memory"));
	error = initialize(*history, history_file_path);
	if (is_error(error))
	{
		ft_memdel((void **)history);
		return (error);
	}
	return (error_none());
}

t_error			history_create(t_history **history)
{
	ssize_t	ret;
	char	*home_env;
	char	path_name[PATH_MAX];

	home_env = getenv("HOME");
	if (home_env == NULL)
		return (errorf("HOME not set"));
	ret = snprintf(path_name, sizeof(path_name), "%s/.tosh_history", home_env);
	if (ret == -1)
		return (errorf("unable to expand ~/.tosh_history"));
	if (ret > (ssize_t)sizeof(path_name) - 1)
		return (errorf("~/.tosh_history is longer then PATH_MAX"));
	return (history_create_at(history, path_name));
}
