/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh - 21 Shell                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "private.h"

Test(env_get, get_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);
	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
}

Test(env_get, get_value_null_env) {
	t_env		*env;
	char		*value;

	env = env_from_envp((char *[]){NULL});
	value = env_get(env, "FAKE");
	cr_assert_eq(value, NULL);
}

Test(env_get, get_value_fake) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);
	value = env_get(env, "FAKE");
	cr_assert_eq(value, NULL);
}
