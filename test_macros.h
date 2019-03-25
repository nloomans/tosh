/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_macros.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 13:26:27 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:27:33 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MACROS_H
# define TEST_MACROS_H

# include <assert.h>
# include <stdio.h>

# define TEST(name, testf) void name(char *source, testf)
# define PRINT() printf("testing (%s): %s\n", source, __func__)
# define RUN(name, func_libft) do { \
	name("libft", func_libft); \
} while (0)
# define RUN2(name, func_libft, func_libc) do {	\
	name("libc ", func_libc);					\
	name("libft", func_libft);					\
} while (0)

#endif
