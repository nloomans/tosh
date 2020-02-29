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

#include "env.h"

size_t					list_length(struct s_env_list *list)
{
	struct s_env_list	*temp;
	size_t				len;

	temp = list;
	len = 0;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

char					**env_to_envp(t_env env)
{
	size_t				lst_len;
	char				**env_arr;

	lst_len = list_lenght(env.list);
	env_arr = (char **)ft_memalloc(sizeof(char *) * (lst_len + 1));
	if (env_arr == NULL)
		return (NULL);
	return (env_arr);
}
