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

#ifndef PRIVATE_H
# define PRIVATE_H

# include "history.h"

struct						s_history__line
{
	char					*buffer;
	t_list_conn				conn;
};

struct s_history__line		*unpack_line(const t_list_conn *conn);

struct						s_history
{
	int						fd;
	t_list_meta				lines;
	t_list_conn				*cursor;
};

t_error						history__read_all(char **out, int fd);

#endif
