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

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../../env/env.h"

uint8_t		builtin_cd(int argc, char **argv, t_env *const env);
uint8_t		builtin_echo(int argc, char **argv, t_env *const env);
uint8_t		builtin_exit(int argc, char **argv, t_env *const env);
uint8_t		builtin_setenv(int argc, char **argv, t_env *const env);

#endif
