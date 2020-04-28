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

/*
** input_read reads a single line of input to dest. prompt contains the text to
** display before the input, prompt_width is the amount of space prompt contains
** when printed to a terminal.
**
** Text wrapping is handled automatically.
*/
t_error		input_read(char **dest, const char *prompt, size_t prompt_width);

#endif
