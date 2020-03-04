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

Test(from_env_to_envp, to_envp) {
	char		*arr[] = {"FOO=1", "BAR=2", "UGH=3", NULL};
	t_env		env_lst;
	int			ret;
	char		**env_arr;
	
	ft_bzero(&env_lst, sizeof(t_env));
	ret = env_from_envp(&env_lst, arr);
	cr_assert_eq(ret, 0);

	env_arr = env_to_envp(&env_lst);
	cr_assert_str_eq(env_arr[0], "FOO=1");
	cr_assert_str_eq(env_arr[1], "BAR=2");
	cr_assert_str_eq(env_arr[2], "UGH=3");
	cr_assert_eq(env_arr[3], NULL);
}
