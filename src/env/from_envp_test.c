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

Test(env_from_envp, import_envp) {
	char		*arr[] = {"FOO=1", "BAR=2", "UGH=3", NULL};
	t_env		env;
	int			ret;
	char		*value;
	
	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	value = env_get(&env, "FOO");
	cr_assert_str_eq(value, "1");

	value = env_get(&env, "BAR");
	cr_assert_str_eq(value, "2");

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