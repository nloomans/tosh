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

Test(env_get, get_value) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;
	
	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);
	value = env_get(&env, "UGH");
	cr_assert_str_eq(value, "ugh");
	value = env_get(&env, "BAR");
	cr_assert_str_eq(value, "bar");
	value = env_get(&env, "FOO");
	cr_assert_str_eq(value, "foo");
	value = env_get(&env, "NAHHH");
	cr_assert_str_eq(value, "nahhh");
}

Test(env_get, get_value_null_env) {
	t_env		env;
	char		*value;
	
	ft_bzero(&env, sizeof(t_env));
	value = env_get(&env, "FAKE");
	cr_assert_eq(value, NULL);
}

Test(env_get, get_value_fake) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;
	
	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);
	value = env_get(&env, "FAKE");
	cr_assert_eq(value, NULL);
}
