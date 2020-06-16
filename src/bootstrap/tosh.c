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

#include "../env/env.h"
#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include "../exec/exec.h"
#include "../error/error.h"
#include "../term/term.h"
#include "../input/input.h"

/*
** TODO: Consider using ft_getline if TERM is unknown.
*/

static void		run(const char *input, t_env *const env)
{
	t_list_meta					tokens;
	struct s_complete_command	*complete_command;
	bool						extra_input_requested;
	t_error						err;

	if (lexer_tokenize(&tokens, input) == -1)
	{
		ft_dprintf(STDERR_FILENO, "tosh: lexer could not allocate memory\n");
	}
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
			return ; //not sure how to hack this in
		}
		exec_run(complete_command, env);
		parser_del(&complete_command);
	}
}

void			tosh(char **envp)
{
	t_env				*env;
	char				*input;
	t_error				error;
	char				prompt[32];

	env = env_from_envp(envp); //error check
	if (term_init(getenv("TERM")) == -1)
	{
		ft_dprintf(STDERR_FILENO, "tosh: fatal: unknown terminal\n");
		// exit(1);
	}
	ft_snprintf(prompt, sizeof(prompt), "%{green}TOSH $ %{reset}");
	while (true)
	{
		error = input_read(&input,
			(struct s_input_formatted_string){prompt, 7});
		if (is_error(error))
		{
			ft_dprintf(STDERR_FILENO, "tosh: fatal: unable to read input: %s\n",
				error.msg);
			exit(1);
		}
		ft_printf("input_read: %s\n", input);

		run (input, env); //error check
		ft_strdel(&input);
	}
}
