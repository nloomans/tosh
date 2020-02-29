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

#ifndef ENV_H
# define ENV_H

# include <libft.h>
# include <stdlib.h>

struct					s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
};

typedef struct			s_env
{
	struct s_env_list	*list;
}						t_env;

/*
** env_to_envp
*/

int						env_from_envp(t_env *env, char **envp);
char					*env_get(t_env env, char *key);
void					env_unset(t_env *env, char *key);
int						env_set(t_env *env, char *key, char *value);

#endif
