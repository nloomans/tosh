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

#include <stdlib.h>
#include "private.h"

struct s_cmd_prefix	*parse_cmd_prefix(t_parser *const p)
{
	struct s_cmd_prefix *cmd_prefix;

	cmd_prefix = ft_memalloc(sizeof(*cmd_prefix));
	if (cmd_prefix == NULL)
	{
		parser__errorf(p, "unable to allocate memory");
		return (NULL);
	}
	cmd_prefix->redirect = parse_io_redirect(p);
	if (is_error(p->error) || !cmd_prefix->redirect)
	{
		free_cmd_prefix(cmd_prefix);
		return (NULL);
	}
	cmd_prefix->prefix = parse_cmd_prefix(p);
	if (is_error(p->error))
	{
		free_cmd_prefix(cmd_prefix);
		return (NULL);
	}
	return (cmd_prefix);
}

void				free_cmd_prefix(struct s_cmd_prefix *const cmd_prefix)
{
	if (cmd_prefix)
	{
		free_cmd_prefix(cmd_prefix->prefix);
		free_io_redirect(cmd_prefix->redirect);
		free(cmd_prefix);
	}
}
