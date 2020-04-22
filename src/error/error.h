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

#ifndef ERROR_H
# define ERROR_H

# include <stdbool.h>

/*
** t_error is the return value that any function which can return an error
** should use.
*/
typedef struct	s_error
{
	char msg[1024];
}				t_error;

/*
** error_none should be returned to indicate that no error occurred.
*/
t_error			error_none(void);

/*
** errorf creates a new error. For example errorf("unable to allocate memory")
** or errorf("unexpected input from terminal"). If an error in a function you
** called occurred and you wish to pass it on to the function which called you,
** consider adding adding context to the error. e.g.
** errorf("unable to get cursor position: %s", error.msg)
**
** An error error should not start with an uppercase letter and should not
** include a newline.
*/
t_error			errorf(char *fmt, ...);

/*
** is_error checks is error contains an error.
**  - is_error(errorf(" ... some text ... ")) == true.
**  - is_error(ERROR_NONE) == false.
*/
bool			is_error(t_error error);

#endif
