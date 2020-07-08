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

# include "term.h"

void		term__send(const char *entry);
t_error		term__getcursor(struct s_term_pos *out);

t_error		term__handle_resize(t_term *self);
void		term__cursor_goto(t_term *self, struct s_term_pos new_pos);
void		term__print(t_term *self,
				struct s_term_formatted_string formatted_string);
void		term__clear_to_end(void);

#endif
