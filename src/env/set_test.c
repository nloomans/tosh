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
#include "env.h"

Test(env_set, set_env) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	ret = env_set(&env, "YEEY", "yeey");
	cr_assert_eq(ret, 0);
	value = env_get(env, "YEEY");
	cr_assert_str_eq(value, "yeey");
}

Test(env_set, change_first_env_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	ret = env_set(&env, "FOO", "yasss");
	cr_assert_eq(ret, 0);
	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "yasss");
}

Test(env_set, change_last_env_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	ret = env_set(&env, "NAHHH", "yasss");
	cr_assert_eq(ret, 0);
	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "yasss");
}

Test(env_set, change_middle_env_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	ret = env_set(&env, "UGH", "yasss");
	cr_assert_eq(ret, 0);
	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "yasss");
}

Test(env_set, set_env_null) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	ret = env_set(&env, NULL, "yeey");
	cr_assert_eq(ret, -1);
}
