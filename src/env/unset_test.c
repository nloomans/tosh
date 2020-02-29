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

	env.list = NULL;
	ret = env_from_envp(&env, arr);
	cr_assert_eq(ret, 0);

	env_unset(&env, "BAR");
	
	value = env_get(env, "BAR");
	cr_assert_eq(value, NULL);
}
