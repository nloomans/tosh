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

#ifndef PRIVATE_H
# define PRIVATE_H

# include "env.h"
# include <libft.h>

struct					s_env_pair
{
	char				*key;
	char				*value;
	t_list_conn			conn;
};

typedef struct			s_env
{
	t_list_meta			list;
}						t_env;

struct s_env_pair		*unpack_env(t_list_conn *const node);

#endif
