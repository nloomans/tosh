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

Test(env_unset, unset_env) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	env_unset(&env, "BAR");
	
	value = env_get(&env, "BAR");
	cr_assert_eq(value, NULL);
}

Test(env_unset, unset_env_first) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	env_unset(&env, "FOO");
	
	value = env_get(&env, "FOO");
	cr_assert_eq(value, NULL);
}

Test(env_unset, unset_env_last) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	env_unset(&env, "NAHHH");
	
	value = env_get(&env, "NAHHH");
	cr_assert_eq(value, NULL);
}

Test(env_unset, unset_env_middle) {
	char		*arr[] = {"FOO=foo", "BAR=bar", "UGH=ugh", "NAHHH=nahhh", NULL};
	t_env		env;
	int			ret;
	char		*value;

	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	env_unset(&env, "UGH");
	
	value = env_get(&env, "UGH");
	cr_assert_eq(value, NULL);
}
