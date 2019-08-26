/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprintf.spec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 12:41:52 by nloomans       #+#    #+#                */
/*   Updated: 2019/08/26 12:41:52 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(sprintf, adds_a_null_terminator) {
	char dest[9] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	cr_expect_eq(ft_sprintf(dest, "12345678"), 8);
	cr_expect_str_eq(dest, "12345678");
}

Test(sprintf, adds_a_null_terminator_empty_string) {
	char dest[9] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	cr_expect_eq(ft_sprintf(dest, ""), 0);
	cr_expect_str_eq(dest, "");
}

Test(snprintf, adds_a_null_terminator) {
	char dest[9] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	cr_expect_eq(ft_snprintf(dest, 9, "12345678"), 8);
	cr_expect_str_eq(dest, "12345678");
}

Test(snprintf, adds_a_null_terminator_empty_string) {
	char dest[9] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	cr_expect_eq(ft_snprintf(dest, 9, ""), 0);
	cr_expect_str_eq(dest, "");
}

Test(snprintf, adds_a_null_terminator_when_truncating) {
	char dest[9] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	cr_expect_eq(ft_snprintf(dest, 9, "1234567890"), 10);
	cr_expect_str_eq(dest, "12345678");
}

Test(snprintf, prints_nothing_when_n_is_0) {
	char dest[9] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};
	cr_expect_eq(ft_snprintf(dest, 0, "123456789"), 9);
	cr_expect_eq(dest[0], 'A');
}

Test(snprintf, prints_nothing_when_null_ptr) {
	cr_expect_eq(ft_snprintf(NULL, 0, "123456789"), 9);
}
