/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_octal.spec.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:44:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 14:50:28 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"
#include <limits.h>

Test(printf_octal, basic)
{
	char *dest;

	ft_asprintf(&dest, "%o", 42u);
	cr_expect_str_eq(dest, "52");
	ft_asprintf(&dest, "%o", 1337u);
	cr_expect_str_eq(dest, "2471");
	ft_asprintf(&dest, "%o", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%#o", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%o", 0u);
	cr_expect_str_eq(dest, "0");
}

Test(printf_octal, width)
{
	char *dest;

	ft_asprintf(&dest, "%5o", 42u);
	cr_expect_str_eq(dest, "   52");
	ft_asprintf(&dest, "%*o", 5, 42u);
	cr_expect_str_eq(dest, "   52");
	ft_asprintf(&dest, "%05o", 42u);
	cr_expect_str_eq(dest, "00052");
	ft_asprintf(&dest, "%#05o", 42u);
	cr_expect_str_eq(dest, "00052");
	ft_asprintf(&dest, "%#5o", 42u);
	cr_expect_str_eq(dest, "  052");
	ft_asprintf(&dest, "%5o", 0u);
	cr_expect_str_eq(dest, "    0");
}

Test(printf_octal, zeropad)
{
	char *dest;

	ft_asprintf(&dest, "%05o", 42u);
	cr_expect_str_eq(dest, "00052");
	ft_asprintf(&dest, "%#05o", 42u);
	cr_expect_str_eq(dest, "00052");
	ft_asprintf(&dest, "%0o", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%05o", 0u);
	cr_expect_str_eq(dest, "00000");
}

Test(printf_octal, precision)
{
	char *dest;

	ft_asprintf(&dest, "%.5o", 42u);
	cr_expect_str_eq(dest, "00052");
	ft_asprintf(&dest, "%#.5o", 42u);
	cr_expect_str_eq(dest, "00052");
	ft_asprintf(&dest, "%.o", 0u);
	cr_expect_str_eq(dest, "");
}
