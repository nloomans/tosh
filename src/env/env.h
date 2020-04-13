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

typedef struct s_env	t_env;

int						env_from_envp(t_env *const env, char **const envp);
char					**env_to_envp(t_env *const env);

char					*env_get(t_env const *const env, char const *const key);
void					env_unset(t_env *env, char const *const key);
int						env_set(t_env *const env,
								char const *const key,
								char const *const value);

void					env_clear(t_env *env);

#endif
