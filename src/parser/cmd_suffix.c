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

struct s_cmd_suffix	*parse_cmd_suffix(t_parser *const p)
{
	struct s_cmd_suffix *cmd_suffix;

	cmd_suffix = ft_memalloc(sizeof(*cmd_suffix));
	cmd_suffix->redirect = parse_io_redirect(p);
	if (!cmd_suffix->redirect && parser__is_token(p, WORD, NULL))
	{
		cmd_suffix->word = ft_strdup(parser__next_token(p)->string);
	}
	if (!cmd_suffix->redirect && !cmd_suffix->word)
	{
		free_cmd_suffix(cmd_suffix);
		return (NULL);
	}
	cmd_suffix->suffix = parse_cmd_suffix(p);
	return (cmd_suffix);
}

void				free_cmd_suffix(struct s_cmd_suffix *const cmd_suffix)
{
	if (cmd_suffix)
	{
		free_cmd_suffix(cmd_suffix->suffix);
		free_io_redirect(cmd_suffix->redirect);
		free(cmd_suffix->word);
		free(cmd_suffix);
	}
}
