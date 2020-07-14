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
					['\"'] = {DOUBLE_QUOTE, true},
					['\''] = {SINGLE_QUOTE, true},
					['\0'] = {EOS,			true},
					},
					.catch_case = {UNQUOTED,	false},
					.can_env_expand = true},
	[UNQUOTED] = {.rules = {
					['\"'] = {DOUBLE_QUOTE, true},
					['\''] = {SINGLE_QUOTE, true},
					['\0'] = {EOS,			true},
					},
					.catch_case = {UNQUOTED,	false},
					.can_env_expand = true},
	[SINGLE_QUOTE] = {.rules = {
					['\''] = {UNQUOTED, 		true},
					['\0'] = {QUOTE_INCOMPLETE,	true},
					},
					.catch_case = {SINGLE_QUOTE,false},
					.can_env_expand = false},
	[DOUBLE_QUOTE] = {.rules = {
					['\"'] = {UNQUOTED, 		true},
					['\0'] = {QUOTE_INCOMPLETE,	true},
					},
					.catch_case = {DOUBLE_QUOTE,false},
					.can_env_expand = true},
};

#endif
