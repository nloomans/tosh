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
#include <ft_printf.h>
#include <unistd.h>

#include <assert.h>

#include "../env/env.h"
#include "../exec/exec.h"
#include "../history/history.h"
#include "../input/input.h"
#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include "../error/error.h"

/*
** assert is placeholder for actual code
*/

static void		run_command(char **input, t_env *const env)
{
	t_list_meta					tokens;
	struct s_complete_command	*complete_command;
	t_error						err;

	err = lexer_handler(&tokens, input);
	if (is_error(err))
		ft_dprintf(STDERR_FILENO, "tosh: %s\n", err.msg);
	else if (tokens.len != 0)
	{
		err = parser_parse(&complete_command, &tokens);
		lexer_clear(&tokens);
		if (is_error(err))
		{
			ft_dprintf(STDERR_FILENO, "tosh: %s\n", err.msg);
			return ;
		}
		exec_run(complete_command, env);
		parser_del(&complete_command);
	}
}

static void		sigint_replacement(int sig)
{
	g_terminate_sig = 1;
	(void)sig;
}

static void		initialize_tosh(t_env **const aenv, char **envp)
{
	if (signal(SIGINT, &sigint_replacement) == SIG_ERR)
	{
		ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to set signal handler");
		exit(1);
	}
	*aenv = env_from_envp(envp);
	if (*aenv == NULL)
	{
		ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to create enviroment\n");
		exit(1);
	}
}

void			tosh(char **envp)
{
	t_env						*env;
	t_error						error;
	struct s_input_read_result	input;

	initialize_tosh(&env, envp);
	while (true)
	{
		error = input_read(&input, "\x1b[0;32mTOSH $ \x1b[0;0m", 7);
		if (is_error(error))
		{
			ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to read input: %s\n",
				error.msg);
			exit(1);
		}
		if (input.exit_reason == INPUT_EXIT_REASON_DONE)
			exit(env_get_exit_status(env));
		if (input.exit_reason == INPUT_EXIT_REASON_SUBMIT)
			run_command(&input.text, env);
		ft_strdel(&input.text);
	}
}
