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

Test(term_wrap, single_line) {
	struct s_term_pos pos = term_wrap(80, (struct s_term_pos){3, 20}, 40);
	cr_expect_eq(pos.row, 3);
	cr_expect_eq(pos.column, 60);
}

Test(term_wrap, multi_line) {
	struct s_term_pos pos = term_wrap(80, (struct s_term_pos){5, 20}, 70);
	cr_expect_eq(pos.row, 6);
	cr_expect_eq(pos.column, 10);
}

Test(term_wrap, edge) {
	struct s_term_pos pos = term_wrap(80, (struct s_term_pos){5, 20}, 60);
	cr_expect_eq(pos.row, 5);
	cr_expect_eq(pos.column, 80);
}

Test(term_wrap, edge_plus_one) {
	struct s_term_pos pos = term_wrap(80, (struct s_term_pos){5, 20}, 61);
	cr_expect_eq(pos.row, 6);
	cr_expect_eq(pos.column, 1);
}

Test(term_wrap, multi_line_edge) {
	struct s_term_pos pos = term_wrap(80, (struct s_term_pos){5, 20}, 80 + 60);
	cr_expect_eq(pos.row, 6);
	cr_expect_eq(pos.column, 80);
}

Test(term_wrap, multi_line_edge_plus_one) {
	struct s_term_pos pos = term_wrap(80, (struct s_term_pos){5, 20}, 80 + 61);
	cr_expect_eq(pos.row, 7);
	cr_expect_eq(pos.column, 1);
}
