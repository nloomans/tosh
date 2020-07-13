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

#include "quote_and_expansion.h"

static t_error		rev_iter_prefix(struct s_cmd_prefix *prefix,
						t_env *const env)
{
	t_error		err;

	if (prefix == NULL)
	{
		return (error_none());
	}
	err = rev_iter_prefix(prefix->prefix, env);
	if (is_error(err))
	{
		return (err);
	}
	return (iter_redirection(prefix->redirect, env));
}

t_error		quote_and_expansion(struct s_pipe_sequence *ast_section,
				t_env *const env)
{
	t_error				err;
	struct s_cmd_suffix	*suffix;

	while (ast_section)
	{
		err = replacer_fsm(&ast_section->simple_command->name, env);
		if (is_error(err))
		{
			return (err);
		}
		suffix =  ast_section->simple_command->suffix;
		while (suffix)
		{
			if (suffix->word)
			{
				err = replacer_fsm(&suffix->word, env);
			}
			else
			{
				err =  iter_redirection(suffix->redirect, env);
			}
			if (is_error(err))
			{
				return (err);
			}
			suffix =  suffix->suffix;
		}
		ast_section = ast_section->pipe_sequence;
	}
}
