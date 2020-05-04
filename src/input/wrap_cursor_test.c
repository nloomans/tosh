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
