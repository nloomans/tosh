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
#include "private.h"

Test(env_set, set_env) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;
	int			ret;

	env = env_from_envp(arr);

	ret = env_set(env, "YEEY", "yeey");
	cr_assert_eq(ret, 0);

	value = env_get(env, "YEEY");
	cr_assert_str_eq(value, "yeey");
	ft_strdel(&value);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	ft_strdel(&value);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	ft_strdel(&value);

	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	ft_strdel(&value);

	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
	ft_strdel(&value);

	env_delete(&env);
}

Test(env_set, change_first_env_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;
	int			ret;

	env = env_from_envp(arr);

	ret = env_set(env, "FOO", "yasss");
	cr_assert_eq(ret, 0);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "yasss");
	ft_strdel(&value);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	ft_strdel(&value);

	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	ft_strdel(&value);

	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
	ft_strdel(&value);

	env_delete(&env);
}

Test(env_set, change_last_env_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;
	int			ret;

	env = env_from_envp(arr);

	ret = env_set(env, "NAHHH", "yasss");
	cr_assert_eq(ret, 0);

	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "yasss");
	ft_strdel(&value);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	ft_strdel(&value);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	ft_strdel(&value);

	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "ugh");
	ft_strdel(&value);

	env_delete(&env);
}

Test(env_set, change_middle_env_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		*env;
	char		*value;
	int			ret;

	env = env_from_envp(arr);

	ret = env_set(env, "UGH", "yasss");
	cr_assert_eq(ret, 0);

	value = env_get(env, "UGH");
	cr_assert_str_eq(value, "yasss");
	ft_strdel(&value);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	ft_strdel(&value);

	value = env_get(env, "BAR");
	cr_assert_str_eq(value, "bar");
	ft_strdel(&value);

	value = env_get(env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
	ft_strdel(&value);

	env_delete(&env);
}

Test(env_set, from_empty) {
	t_env		*env;
	char		*value;
	int			ret;

	env = env_from_envp((char *[]){NULL});

	ret = env_set(env, "FOO", "foo");
	cr_assert_eq(ret, 0);

	value = env_get(env, "FOO");
	cr_assert_str_eq(value, "foo");
	ft_strdel(&value);

	env_delete(&env);
}
