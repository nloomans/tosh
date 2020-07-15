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

#ifndef QUOTE_AND_EXPANSION_H
# define QUOTE_AND_EXPANSION_H

# include "../../env/env.h"
# include "../../error/error.h"
# include "../../parser/parser.h"

enum    e_machine_state{
	UNDEF,
	FIRST_CHAR,
	UNQUOTED,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	SLASH,
	EOS,
	QUOTE_INCOMPLETE,
};

struct  s_quote_fsm_rule{
	enum e_machine_state	new_state;
	bool					ignore_char;
	bool					env_expand;
};

struct  s_quote_fsm_complete_state{
	struct s_quote_fsm_rule	rules[256];
	struct s_quote_fsm_rule	catch_case;
};

typedef struct s_quote_fsm_complete_state	t_machine_def;

t_error     replacer_fsm(char **const tape,
                const t_machine_def *machine,
                t_env *const env);

#endif
