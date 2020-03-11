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
#include "private.h"

Test(env_unset, unset_env) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	env_unset(env, "BAR");

	value = env_get(env, "BAR");
	cr_assert_eq(value, NULL);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
}

Test(env_unset, unset_env_first) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	env_unset(env, "FOO");

	value = env_get(env, "FOO");
	cr_assert_eq(value, NULL);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
}

Test(env_unset, unset_env_last) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	env_unset(env, "NAHHH");

	value = env_get(env, "NAHHH");
	cr_assert_eq(value, NULL);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
}

Test(env_unset, unset_env_middle) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	env_unset(env, "UGH");

	value = env_get(env, "UGH");
	cr_assert_eq(value, NULL);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
}

Test(env_unset, unset_nonexistent) {
	char		*arr[] = {"FOO=foo", NULL};
	t_env		*env;
	char		*value;

	env = env_from_envp(arr);

	env_unset(env, "BAR");

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	value = env_get(env, "BAR");
	cr_assert_eq(value, NULL);
}

Test(env_unset, unset_empty) {
	t_env		*env;
	char		*value;

	env = env_from_envp((char *[]){NULL});

	env_unset(env, "BAR");

	value = env_get(env, "BAR");
	cr_assert_eq(value, NULL);
}

Test(env_unset, unset_all) {
	char		*arr[] = {"FOO=foo", "BAR=bar", NULL};
	t_env		*env;

	env = env_from_envp(arr);

	env_unset(env, "FOO");
	env_unset(env, "BAR");

	cr_assert_eq(env->list.len, 0);
}