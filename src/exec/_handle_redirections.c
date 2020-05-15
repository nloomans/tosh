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

static t_error	redirect(const struct s_io_redirect *const redir)
{
	(void)redir; //ignoring redir for now
	return (error_none());
}

static t_error	recurse_prefix(const struct s_cmd_prefix *const prefix)//add tracker for success redirs
{
	t_error		err;

	if (prefix == NULL)
		return (error_none());
	if (prefix->prefix)
	{
		err = recurse_prefix(prefix);
		if (is_error(err))
		{
			return (err);
		}
	}
	err = redirect(prefix->redirect); //might need to be iff protected
	return (err);
}

t_error			exec__handle_redirections(
					const struct s_simple_command *const command)
{
	t_error				err;
	struct s_cmd_suffix	*suffix;

	err = recurse_prefix(command->prefix);
	if (is_error(err))
	{
		return (err);
	}
	suffix = command->suffix;
	while (suffix)
	{
		if (suffix->redirect)
		{
			err = redirect(suffix->redirect);
			if (is_error(err))
			{
				return (err);
			}
		}
		suffix = suffix->suffix;
	}
	return (err);
}