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

Test(env_from_envp, import_envp) {
	char		*arr[] = {"FOO=1", "BAR=2", "UGH=3", NULL};
	t_env		env;
	int			ret;
	
	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);
	cr_assert_str_eq(env.list->key, "FOO");
	cr_assert_str_eq(env.list->value, "1");
	cr_assert_str_eq(env.list->next->key, "BAR");
	cr_assert_str_eq(env.list->next->value, "2");
	cr_assert_str_eq(env.list->next->next->key, "UGH");
	cr_assert_str_eq(env.list->next->next->value, "3");
	cr_assert_eq(env.list->next->next->next, NULL);
}

Test(env_from_envp, import_envp_containing_equal) {
	char		*arr[] = {"FOO=ugh=1", NULL};
	t_env		env;
	int			ret;
	
	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);
	cr_assert_str_eq(env.list->key, "FOO");
	cr_assert_str_eq(env.list->value, "ugh=1");
	cr_assert_eq(env.list->next, NULL);
}

Test(env_from_envp, import_envp_null) {
	char		*arr[] = {NULL};
	t_env		env;
	int			ret;

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(env.list, NULL);
	cr_assert_eq(ret, 0);
}
