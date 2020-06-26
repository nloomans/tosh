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

#ifndef HISTORY_H
# define HISTORY_H

# include <libft.h>
# include "../error/error.h"

typedef struct s_history	t_history;

struct						s_history_node
{
	char					*buffer;
	t_list_conn				conn;
};

struct s_history_node		*unpack_history_node(const t_list_conn *conn);

struct						s_history
{
	int						fd;
	t_list_meta				history;
};

t_error						history_create(t_history **history,
								const char *history_file_path);
void						history_destroy(t_history **history);

int							history_debug(void);

#endif
