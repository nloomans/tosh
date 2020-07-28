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

#include <ft_printf.h>

#include "../private.h"
#include "machine_definitions.h"
#include "../../input/input.h"

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

t_error		acquire_heredoc(struct s_io_here *const heredoc,
				bool is_quoted,
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
		if (expand_heredoc(&heredoc->contents, read_return.text) == -1)
		{
			err = errorf("could not allocate memory");
		}
		ft_strdel(&read_return.text);
	}
	ft_strdel(&read_return.text);
	if (!is_error(err) && !is_quoted)
		return (replacer_fsm(&heredoc->contents, &g_here_content_table, env));
	return (err);
}
