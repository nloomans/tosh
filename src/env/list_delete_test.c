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

Test(env_list_delete, delete_env) {
	char		*arr[] = {"FOO=123", "BAR=2345", "UGH=3", NULL};
	t_env		env;
	int			ret;
	
	ft_bzero(&env, sizeof(t_env));
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	env_list_delete(&env);
	cr_assert_eq(env.list.first, NULL);
	cr_assert_eq(env.list.last, NULL);
	cr_assert_eq(env.list.len, 0);
}
