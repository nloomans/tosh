/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "private.h"

Test(env_from_envp, import_envp) {
	char		*arr[] = {"FOO=123", "BAR=2345", "UGH=3", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	value = env_get(&env, "FOO");
	cr_assert_str_eq(value, "123");

	value = env_get(&env, "BAR");
	cr_assert_str_eq(value, "2345");

	value = env_get(&env, "UGH");
	cr_assert_str_eq(value, "3");
}

Test(env_from_envp, import_envp_containing_equal) {
	char		*arr[] = {"FOO=ugh=1", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	value = env_get(&env, "FOO");
	cr_assert_str_eq(value, "ugh=1");
}

Test(env_from_envp, import_envp_no_equal, .init = cr_redirect_stderr) {
	char		*arr[] = {"FOO=123", "BAR2345", "UGH=3", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	value = env_get(&env, "FOO");
	cr_assert_str_eq(value, "123");

	value = env_get(&env, "UGH");
	cr_assert_str_eq(value, "3");

	value = env_get(&env, "BAR2345");
	cr_assert_eq(value, NULL);

	value = env_get(&env, "BAR");
	cr_assert_eq(value, NULL);

	cr_assert_stderr_eq_str("Warning: env: 'BAR2345', no '=' present\n");
}

Test(env_from_envp, import_envp_null) {
	char		*arr[] = {NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	value = env_get(&env, "FAKE");
	cr_assert_eq(value, NULL);
}
