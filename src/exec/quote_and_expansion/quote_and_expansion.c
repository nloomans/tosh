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

#include "machine_definitions.h"

static t_error		expand_redirection(struct s_io_redirect *const redirect,
						t_env *const env)
{
	if (redirect->file)
	{
		return (replacer_fsm(&redirect->file->filename,
			&g_basic_table, env));
	}
	else
	{
		if (ft_strchr(redirect->here->here_end, '\"') != NULL ||
			ft_strchr(redirect->here->here_end, '\'') != NULL)
		{
			redirect->here->was_quoted = true;
		}
		return (replacer_fsm(&redirect->here->here_end,
			&g_here_end_table, env));
	}
}

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
	return (expand_redirection(prefix->redirect, env));
}

static t_error		iter_suffix(struct s_cmd_suffix *suffix, t_env *const env)
{
	t_error	err;

	while (suffix)
	{
		if (suffix->word)
		{
			err = replacer_fsm(&suffix->word, &g_basic_table, env);
		}
		else
		{
			err = expand_redirection(suffix->redirect, env);
		}
		if (is_error(err))
		{
			return (err);
		}
		suffix = suffix->suffix;
	}
	return (error_none());
}

t_error				quote_and_expansion(struct s_pipe_sequence *ast_section,
						t_env *const env)
{
	t_error				err;

	while (ast_section)
	{
		if (ast_section->simple_command->name)
		{
			err = replacer_fsm(&ast_section->simple_command->name,
				&g_basic_table, env);
			if (is_error(err))
				return (err);
		}
		err = rev_iter_prefix(ast_section->simple_command->prefix, env);
		if (is_error(err))
			return (err);
		err = iter_suffix(ast_section->simple_command->suffix, env);
		if (is_error(err))
			return (err);
		ast_section = ast_section->pipe_sequence;
	}
	return (error_none());
}
