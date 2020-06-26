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
	t_list_conn				*cursor;
};

t_error						history_create(t_history **history,
								const char *history_file_path);
void						history_destroy(t_history **history);

int							history_debug(void);

/*
** history_up and history_down allow you to scroll through the history.
** Returns the buffer of the new history item, empty string if we are at the
** bottom, and NULL of the action was a no-op.
**
** Result may not be  modified or freed.
*/
char						*history_up(struct s_history *history);
char						*history_down(struct s_history *history);

/*
** history_push adds a new item to the bottom of the history. The cursor
** position will be reset.
*/
t_error						history_push(struct s_history *history,
								const char *new);

#endif
