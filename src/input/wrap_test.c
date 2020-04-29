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

#include <criterion/criterion.h>
#include <libft.h>
#include "private.h"

Test(input__wrap, single_line) {
	char **dest;

	input__wrap(&dest, 80, 20, "ls -al");
	cr_expect_str_eq(dest[0], "ls -al");
	cr_expect_eq(dest[1], NULL);
	ft_arraydel((void ***)&dest, ft_memdel);
}

Test(input__wrap, multi_line) {
	char **dest;

	input__wrap(&dest, 80, 20, "echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.'");
	cr_expect_str_eq(dest[0], "echo 'this is a very long line which does not fit within the");
	cr_expect_str_eq(dest[1], " 80 characters of a standard terminal.'");
	cr_expect_eq(dest[2], NULL);
	ft_arraydel((void ***)&dest, ft_memdel);
}

Test(input__wrap_cursor, single_line) {
	struct s_term_pos pos = input__wrap_cursor(80, 20, 40);
	cr_expect_eq(pos.row, 0);
	cr_expect_eq(pos.column, 60);
}

Test(input__wrap_cursor, multi_line) {
	struct s_term_pos pos = input__wrap_cursor(80, 20, 70);
	cr_expect_eq(pos.row, 1);
	cr_expect_eq(pos.column, 10);
}

Test(input__wrap_cursor, edge) {
	struct s_term_pos pos = input__wrap_cursor(80, 20, 60);
	cr_expect_eq(pos.row, 1);
	cr_expect_eq(pos.column, 0);
}
