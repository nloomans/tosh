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

#ifndef INPUT_H
# define INPUT_H

# include "../error/error.h"
# include "../term/term.h"

/*
** input_read reads a single line of input to dest. prompt contains the text to
** display before the input.
**
** Text wrapping is handled automatically.
*/
t_error		input_read(char **dest, struct s_term_formatted_string prompt);

/*
** input_debug prints useful debug information about the current keys pressed.
** It can be accessed using 'tosh -d input'
*/
int			input_debug(void);

#endif
