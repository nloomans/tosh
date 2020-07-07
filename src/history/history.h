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

t_error						history_create(t_history **history);
t_error						history_create_at(t_history **history,
								const char *history_file_path);
void						history_destroy(t_history **history);

int							history_debug(void);

/*
** history_up and history_down allow you to scroll through the history.
** Returns the buffer of the new history item, empty string if we are at the
** bottom, and NULL of the action was a no-op.
**
** Result must be freed.
*/
char						*history_up(t_history *history);
char						*history_down(t_history *history);

/*
** history_push adds a new item to the bottom of the history. The cursor
** position will be reset.
*/
t_error						history_push(t_history *history, const char *new);

#endif
