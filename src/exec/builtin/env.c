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

#include <libft.h>
#include <ft_printf.h>

#include "../../env/env.h"

uint8_t		builtin_env(int argc, char **argv, t_env *const env)
{
	char	**envp;
	size_t	index;

	(void)argv;
	if (argc > 1)
	{
		return (ft_eprintf(1, "env: too many arguments\n"));
	}
	envp = env_to_envp(env);
	if (envp == NULL)
	{
		return (ft_eprintf(1, "env: failed to allocate memory\n"));
	}
	index = 0;
	while (envp[index] != NULL)
	{
		ft_printf("%s\n", envp[index]);
		index++;
	}
	ft_arraydel((void ***)&envp, &ft_memdel);
	return (0);
}
