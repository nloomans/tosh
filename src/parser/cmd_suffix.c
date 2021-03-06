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

static struct s_cmd_suffix	*fill_cmd_suffix(
								struct s_cmd_suffix *const cmd_suffix,
								t_parser *const p)
{
	cmd_suffix->redirect = parse_io_redirect(p);
	if (!cmd_suffix->redirect && parser__is_token(p, WORD, NULL))
	{
		cmd_suffix->word = ft_strdup(parser__next_token(p)->string);
		if (cmd_suffix->word == NULL)
		{
			parser__errorf(p, "unable to allocate memory");
			return (NULL);
		}
	}
	if (is_error(p->error) || (!cmd_suffix->redirect && !cmd_suffix->word))
	{
		return (NULL);
	}
	return (cmd_suffix);
}

struct s_cmd_suffix			*parse_cmd_suffix(t_parser *const p)
{
	struct s_cmd_suffix *cmd_suffix;

	cmd_suffix = ft_memalloc(sizeof(*cmd_suffix));
	if (cmd_suffix == NULL)
	{
		parser__errorf(p, "unable to allocate memory");
		return (NULL);
	}
	if (fill_cmd_suffix(cmd_suffix, p) == NULL || is_error(p->error))
	{
		free_cmd_suffix(cmd_suffix);
		return (NULL);
	}
	cmd_suffix->suffix = parse_cmd_suffix(p);
	if (is_error(p->error))
	{
		free_cmd_suffix(cmd_suffix);
		return (NULL);
	}
	return (cmd_suffix);
}

void						free_cmd_suffix(
								struct s_cmd_suffix *const cmd_suffix)
{
	if (cmd_suffix)
	{
		free_cmd_suffix(cmd_suffix->suffix);
		free_io_redirect(cmd_suffix->redirect);
		free(cmd_suffix->word);
		free(cmd_suffix);
	}
}
