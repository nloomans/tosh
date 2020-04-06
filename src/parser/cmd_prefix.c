/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "private.h"

struct s_cmd_prefix	*parse_cmd_prefix(t_parser *const p)
{
	struct s_cmd_prefix *cmd_prefix;

	cmd_prefix = ft_memalloc(sizeof(*cmd_prefix));
	cmd_prefix->redirect = parse_io_redirect(p);
	if (!cmd_prefix->redirect)
	{
		free_cmd_prefix(cmd_prefix);
		return (NULL);
	}
	cmd_prefix->prefix = parse_cmd_prefix(p);
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
