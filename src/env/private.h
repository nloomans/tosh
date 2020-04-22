/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TOSH                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include <libft.h>
# include "env.h"

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
