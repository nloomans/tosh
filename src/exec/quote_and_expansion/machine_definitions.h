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

#ifndef MACHINE_DEFINITIONS_H
# define MACHINE_DEFINITIONS_H

# include "quote_and_expansion.h"

const t_machine_def	g_basic_table[] = {
	[FIRST_CHAR] = {.rules = {
					['\"'] = {DOUBLE_QUOTE, true, false},
					['\''] = {SINGLE_QUOTE, true, false},
					['\0'] = {EOS,			true, false},
					['$'] = {UNQUOTED, 		true, true},
					},
					.catch_case = {UNQUOTED,	false, false},
	},
	[UNQUOTED] = {.rules = {
					['\"'] = {DOUBLE_QUOTE, true, false},
					['\''] = {SINGLE_QUOTE, true, false},
					['\0'] = {EOS,			true, false},
					['$'] = {UNQUOTED, 		true, true},
					},
					.catch_case = {UNQUOTED,	false, false},
	},
	[SINGLE_QUOTE] = {.rules = {
					['\''] = {UNQUOTED, 		true, false},
					['\0'] = {QUOTE_INCOMPLETE,	true, false},
					},
					.catch_case = {SINGLE_QUOTE,false, false},
	},
	[DOUBLE_QUOTE] = {.rules = {
					['\"'] = {UNQUOTED, 		true, false},
					['\0'] = {QUOTE_INCOMPLETE,	true, false},
					['$'] = {DOUBLE_QUOTE, 		true, true},
					},
					.catch_case = {DOUBLE_QUOTE,false, false},
	},
};

#endif
