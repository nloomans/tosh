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

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "private.h"

Test(env_from_envp, import_envp) {
	char		*arr[] = {"FOO=123", "BAR=2345", "UGH=3", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "123");
	ft_strdel(&value);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "2345");
	ft_strdel(&value);

	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "3");
	ft_strdel(&value);

	env_delete(&env);
}

Test(env_from_envp, import_envp_containing_equal) {
	char		*arr[] = {"FOO=ugh=1", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "ugh=1");
	ft_strdel(&value);

	env_delete(&env);
}

Test(env_from_envp, import_envp_no_equal, .init = cr_redirect_stderr) {
	char		*arr[] = {"FOO=123", "BAR2345", "UGH=3", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "123");
	ft_strdel(&value);

	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "3");
	ft_strdel(&value);

	value = env_get(env, "BAR2345");
	cr_assert_eq(value, NULL);

	value = env_get(env, "BAR");
	cr_assert_eq(value, NULL);

	env_delete(&env);

	cr_assert_stderr_eq_str("tosh: missing '=' in env 'BAR2345', ignoring\n");
}

Test(env_from_envp, import_envp_null) {
	char		*arr[] = {NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	value = env_get(env, "FAKE");
	cr_assert_eq(value, NULL);

	env_delete(&env);
}
