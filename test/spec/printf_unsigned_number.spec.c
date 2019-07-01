/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_unsigned_number.spec.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:44:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 17:15:39 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"
#include <limits.h>

Test(printf_unsigned_number, basic)
{
	char *dest;

	ft_asprintf(&dest, "%u", 42u);
	cr_expect_str_eq(dest, "42");
	ft_asprintf(&dest, "%u", 1337u);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%u", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "bignum: %u", UINT_MAX);
	cr_expect_str_eq(dest, "bignum: 4294967295");
}

Test(printf_unsigned_number, padding)
{
	char *dest;

	ft_asprintf(&dest, "%5u", 42u);
	cr_expect_str_eq(dest, "   42");
	ft_asprintf(&dest, "%05u", 42u);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%.5u", 42u);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%10.5u", 42u);
	cr_expect_str_eq(dest, "     00042");
	ft_asprintf(&dest, "%-10.5u", 42u);
	cr_expect_str_eq(dest, "00042     ");
	ft_asprintf(&dest, "%-10.5u", 31337u);
	cr_expect_str_eq(dest, "31337     ");
	ft_asprintf(&dest, "%-2.5u", 31337u);
	cr_expect_str_eq(dest, "31337");
	ft_asprintf(&dest, "%2.5u", 31337u);
	cr_expect_str_eq(dest, "31337");
}

Test(printf_unsigned_number, padding_wildcard)
{
	char *dest;

	ft_asprintf(&dest, "%*u", 5, 42u);
	cr_expect_str_eq(dest, "   42");
	ft_asprintf(&dest, "%0*u", 5, 42u);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%.*u", 5, 42u);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%*.*u", 10, 5, 42u);
	cr_expect_str_eq(dest, "     00042");
	ft_asprintf(&dest, "%-*.*u", -10, 5, 42u);
	cr_expect_str_eq(dest, "00042     ");
	ft_asprintf(&dest, "%-*.*u", 10, 5, 31337u);
	cr_expect_str_eq(dest, "31337     ");
	ft_asprintf(&dest, "%-*.*u", 2, 5, 31337u);
	cr_expect_str_eq(dest, "31337");
	ft_asprintf(&dest, "%*.*u", 2, 5, 31337u);
	cr_expect_str_eq(dest, "31337");
}

Test(printf_unsigned_number, sizes)
{
	char *dest;

	ft_asprintf(&dest, "%hhu", 1337u);
	cr_expect_str_eq(dest, "57");
	ft_asprintf(&dest, "%hu", 1337u);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%u", 1337u);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%lu", 1337u);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%5llu", 1337u);
	cr_expect_str_eq(dest, " 1337");
	ft_asprintf(&dest, "%hhu", 2u);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%hu", 2u);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%u", 2u);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%lu", 2u);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%.5llu", 2u);
	cr_expect_str_eq(dest, "00002");
	ft_asprintf(&dest, "%hhu", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%hu", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%u", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%lu", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%llu", 0u);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%hhu", 9223372036854775807UL);
	cr_expect_str_eq(dest, "255");
	ft_asprintf(&dest, "%hu", 9223372036854775807UL);
	cr_expect_str_eq(dest, "65535");
	ft_asprintf(&dest, "%u", 9223372036854775807UL);
	cr_expect_str_eq(dest, "4294967295");
	ft_asprintf(&dest, "%lu", 9223372036854775807UL);
	cr_expect_str_eq(dest, "9223372036854775807");
	ft_asprintf(&dest, "%llu", 9223372036854775807UL);
	cr_expect_str_eq(dest, "9223372036854775807");
}


Test(printf_unsigned_number, advanced_padding)
{
	char *dest;

	ft_asprintf(&dest, "%05hhd", 1337);
	cr_expect_str_eq(dest, "00057");
	ft_asprintf(&dest, "%.5hhd", 1337);
	cr_expect_str_eq(dest, "00057");
	ft_asprintf(&dest, "%10.5hhd", 1337);
	cr_expect_str_eq(dest, "     00057");
	ft_asprintf(&dest, "%010.5hhd", 1337);
	cr_expect_str_eq(dest, "     00057");
	ft_asprintf(&dest, "%.u", 0u);
	cr_expect_str_eq(dest, "");
}
