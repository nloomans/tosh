/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_hex.spec.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:20:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 14:46:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_hex, normal_hex)
{
	char *dest;

	ft_asprintf(&dest, "%x", 42);
	cr_expect_str_eq(dest, "2a");
	ft_asprintf(&dest, "%x", 0xDEADBEEF);
	cr_expect_str_eq(dest, "deadbeef");
	ft_asprintf(&dest, "%x", 0x3456789);
	cr_expect_str_eq(dest, "3456789");
	ft_asprintf(&dest, "%x", 0x12ABCDEF);
	cr_expect_str_eq(dest, "12abcdef");
}

Test(printf_hex, capital_hex)
{
	char *dest;

	ft_asprintf(&dest, "%X", 42);
	cr_expect_str_eq(dest, "2A");
	ft_asprintf(&dest, "%X", 0xDEADBEEF);
	cr_expect_str_eq(dest, "DEADBEEF");
	ft_asprintf(&dest, "%X", 0x3456789);
	cr_expect_str_eq(dest, "3456789");
	ft_asprintf(&dest, "%X", 0x12ABCDEF);
	cr_expect_str_eq(dest, "12ABCDEF");
}

Test(printf_hex, prefix)
{
	char *dest;

	ft_asprintf(&dest, "%#x", 42);
	cr_expect_str_eq(dest, "0x2a");
	ft_asprintf(&dest, "%#X", 42);
	cr_expect_str_eq(dest, "0X2A");
	ft_asprintf(&dest, "%#x", 0x1337);
	cr_expect_str_eq(dest, "0x1337");
	ft_asprintf(&dest, "%#x", 0xEEFFAA);
	cr_expect_str_eq(dest, "0xeeffaa");
	ft_asprintf(&dest, "%#X", 0xEEFFAA);
	cr_expect_str_eq(dest, "0XEEFFAA");
}

Test(printf_hex, padding)
{
	char *dest;

	ft_asprintf(&dest, "%5x", 42);
	cr_expect_str_eq(dest, "   2a");
	ft_asprintf(&dest, "%#5x", 42);
	cr_expect_str_eq(dest, " 0x2a");
	ft_asprintf(&dest, "%1x", 42);
	cr_expect_str_eq(dest, "2a");
	ft_asprintf(&dest, "%#3x", 42);
	cr_expect_str_eq(dest, "0x2a");
	ft_asprintf(&dest, "%-1x", 42);
	cr_expect_str_eq(dest, "2a");
	ft_asprintf(&dest, "%#-3x", 42);
	cr_expect_str_eq(dest, "0x2a");
}

Test(printf_hex, padding_left_complex)
{
	char *dest;

	ft_asprintf(&dest, "%-5X", 42);
	cr_expect_str_eq(dest, "2A   ");
	ft_asprintf(&dest, "%#-5x", 42);
	cr_expect_str_eq(dest, "0x2a ");
	ft_asprintf(&dest, "%-*x", 5, 42);
	cr_expect_str_eq(dest, "2a   ");
	ft_asprintf(&dest, "%#*x!*%%", -5, 42);
	cr_expect_str_eq(dest, "0x2a !*%");
	ft_asprintf(&dest, "%#*X>>", -5, 42);
	cr_expect_str_eq(dest, "0X2A >>");
}

Test(printf_hex, wildcard_complete)
{
	char *dest;

	ft_asprintf(&dest, "%-*.*X", 10, 5, 42);
	cr_expect_str_eq(dest, "0002A     ");
	ft_asprintf(&dest, "%#*.*X", -10, 5, 42);
	cr_expect_str_eq(dest, "0X0002A   ");
}

Test(printf_hex, zeropad)
{
	char *dest;

	ft_asprintf(&dest, "%0*X", 30, 0xFFFF);
	cr_expect_str_eq(dest, "00000000000000000000000000FFFF");
	ft_asprintf(&dest, "'%#-30X'", 0xFFFF);
	cr_expect_str_eq(dest, "'0XFFFF                        '");
	ft_asprintf(&dest, "%#05x", 0);
	cr_expect_str_eq(dest, "00000");
	ft_asprintf(&dest, "%#5x", 0);
	cr_expect_str_eq(dest, "    0");
}

Test(printf_hex, null_null)
{
	char *dest;

	ft_asprintf(&dest, "%5.X", 0);
	cr_expect_str_eq(dest, "     ");
	ft_asprintf(&dest, "%5.0x", 0);
	cr_expect_str_eq(dest, "     ");
	ft_asprintf(&dest, "%5.0x", 42);
	cr_expect_str_eq(dest, "   2a");
	ft_asprintf(&dest, "%.0x", 42);
	cr_expect_str_eq(dest, "2a");
	ft_asprintf(&dest, "%.x", 0);
	cr_expect_str_eq(dest, "");
}
