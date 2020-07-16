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

#include <fcntl.h>
#include <unistd.h>
#include <ft_printf.h>

#include "../private.h"
#include "../../input/input.h"
#include "../quote_and_expansion/machine_definitions.h"

static int	expand_heredoc(char **const heredoc_contents,
				const char *const new_addition)
{
	char	*holder;

	if (*heredoc_contents == NULL)
	{
		if (ft_asprintf(&holder, "%s\n", new_addition) == -1)
		{
			holder = NULL;
		}
	}
	else
	{
		if (ft_asprintf(&holder, "%s%s\n",
			*heredoc_contents, new_addition) == -1)
		{
			holder = NULL;
		}
	}
	if (holder == NULL)
	{
		return (-1);
	}
	ft_strreplace(heredoc_contents, holder);
	return (0);
}

t_error		acquire_heredoc(char **const doc_contents,
				const struct s_io_here *const heredoc,
				const t_env *const env)
{
	struct s_input_read_result	read_return;
	t_error						err;

	while (true)
	{
		err = input_read(&read_return, "> ", 2);
		if (is_error(err))
			return (err);
		if (read_return.exit_reason == INPUT_EXIT_REASON_CANCEL)
			return (errorf("heredoc cancelled by ctrl-c"));
		if (read_return.exit_reason == INPUT_EXIT_REASON_DONE ||
				ft_strequ(read_return.text, heredoc->here_end))
		{
			break ;
		}
		if (expand_heredoc(doc_contents, read_return.text) == -1)
		{
			err = errorf("could not allocate memory");
		}
		ft_strdel(&read_return.text);
	}
	ft_strdel(&read_return.text);
	if (!is_error(err) && !heredoc->was_quoted)
		return (replacer_fsm(doc_contents, &g_here_content_table, env));
	return (err);
}

t_error		redirect_heredoc(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_here *const heredoc,
				const t_env *const env)
{
	char		*doc_contents;
	int			pip[2];
	t_error		err;

	doc_contents = NULL;
	err = acquire_heredoc(&doc_contents, heredoc, env);
	if (is_error(err))
	{
		ft_strdel(&doc_contents);
		return (err);
	}
	if (pipe(pip) == -1)
	{
		return (errorf("failed to create pipe"));
	}
	write(pip[write_to], doc_contents, ft_strlen(doc_contents));
	close(pip[write_to]);
	err = exec__add_tracker(first_fd, pip[read_from], tracker_lst);
	if (is_error(err))
	{
		close(pip[read_from]);
	}
	ft_strdel(&doc_contents);
	return (err);
}
