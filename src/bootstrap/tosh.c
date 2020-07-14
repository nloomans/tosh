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
** todo: replace (void)env; with the executor module
**
** assert is placeholder for actual code
*/

static void		run_command(const char *const input, t_env *const env)
{
	t_list_meta					tokens;
	struct s_complete_command	*complete_command;
	bool						extra_input_requested;
	t_error						err;

	if (lexer_tokenize(&tokens, input) == -1)
		ft_dprintf(STDERR_FILENO, "tosh: lexer could not allocate memory\n");
	if (tokens.len != 0)
	{
		err = parser_parse(&complete_command, &extra_input_requested, &tokens);
		lexer_clear(&tokens);
		if (is_error(err))
		{
			ft_dprintf(STDERR_FILENO, "tosh: %s\n", err.msg);
			return ;
		}
		if (extra_input_requested)
		{
			ft_dprintf(STDERR_FILENO, "extra input requested\n");
			assert(0);
		}
		exec_run(complete_command, env);
		parser_del(&complete_command);
	}
}

static void		initialize_tosh(t_env **const env,
					t_history **const history,
					char **const envp)
{
	t_error	error;

	error = history_create(history);
	if (is_error(error))
	{
		ft_dprintf(STDERR_FILENO,
			"tosh: failed to enable history support: %s\n", error.msg);
	}
	*env = env_from_envp(envp);
	if (*env == NULL)
	{
		ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to create enviroment\n");
		exit(1);
	}
}

/*
** TODO: Consider using ft_getline if TERM is unknown.
*/

void			tosh(char **envp)
{
	t_env						*env;
	t_error						error;
	struct s_input_read_result	input;
	char						prompt[32];
	t_history					*history;

	ft_snprintf(prompt, sizeof(prompt), "%{green}TOSH $ %{reset}");
	initialize_tosh(&env, &history, envp);
	while (true)
	{
		error = input_read(&input, history,
			(struct s_term_formatted_string){prompt, 7});
		if (is_error(error))
		{
			ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to read input: %s\n",
				error.msg);
			exit(1);
		}
		if (input.exit_reason == INPUT_EXIT_REASON_DONE)
			exit(env_get_exit_status(env));
		if (input.exit_reason == INPUT_EXIT_REASON_SUBMIT)
			run_command(input.text, env);
		ft_strdel(&input.text);
	}
}
