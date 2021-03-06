/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh-21Shell                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdbool.h>
# include <stdint.h>

typedef struct s_env	t_env;

bool					env_is_key_char(const char character);

t_env					*env_from_envp(char **const envp);
char					**env_to_envp(const t_env *const env);

char					*env_get(t_env const *const env, char const *const key);
char					*env_get_unsafe(t_env const *const env,
							char const *const key);
void					env_unset(t_env *env, char const *const key);
int						env_set(t_env *const env,
								char const *const key,
								char const *const value);

uint8_t					env_get_exit_status(const t_env *const env);
void					env_set_exit_status(t_env *const env,
											const uint8_t status);

void					env_delete(t_env **const env);

#endif
