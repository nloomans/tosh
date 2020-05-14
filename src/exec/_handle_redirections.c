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

static t_error	recurse_prefix(const struct s_cmd_prefix *const prefix)//add tracker for success redirs
{
	t_error		err;

	assert(prefix->redirect); // discuss necesity/delet
	err = error_none();
	if (prefix->prefix)
	{
		err = recurse_prefix(prefix);
	}
	if (is_error(err))
	{
		return (err);
	}
	
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
			
		}
		suffix = suffix->suffix;
	}
	return (err);
}