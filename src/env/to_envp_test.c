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

Test(env_to_envp, to_envp) {
	char		*arr[] = {"FOO=1", "BAR=2", "UGH=3", "TEST=FOO=1", "HI=", NULL};
	t_env		*env;
	char		**env_arr;

	env = env_from_envp(arr);

	env_arr = env_to_envp(env);
	cr_assert_str_eq(env_arr[0], "FOO=1");
	cr_assert_str_eq(env_arr[1], "BAR=2");
	cr_assert_str_eq(env_arr[2], "UGH=3");
	cr_assert_str_eq(env_arr[3], "TEST=FOO=1");
	cr_assert_str_eq(env_arr[4], "HI=");
	cr_assert_eq(env_arr[5], NULL);
}

Test(env_to_envp, empty) {
	t_env		*env;
	char		**env_arr;

	env = env_from_envp((char *[]){NULL});
	env_arr = env_to_envp(env);
	cr_assert_eq(env_arr[0], NULL);
}