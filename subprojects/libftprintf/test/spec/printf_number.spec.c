/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_number.spec.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:44:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/05 13:20:24 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"
#include <limits.h>

Test(printf_number, basic)
{
	char *dest;

	ft_asprintf(&dest, "%d", 42);
	cr_expect_str_eq(dest, "42");
	ft_asprintf(&dest, "%d", 1337);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%d", 0);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%d cheating", -42);
	cr_expect_str_eq(dest, "-42 cheating");
	ft_asprintf(&dest, "%+d reverse cheating", 42);
	cr_expect_str_eq(dest, "+42 reverse cheating");
	ft_asprintf(&dest, "%+d special 0", 0);
	cr_expect_str_eq(dest, "+0 special 0");
	ft_asprintf(&dest, "bignum: %d", 2147483647);
	cr_expect_str_eq(dest, "bignum: 2147483647");
	ft_asprintf(&dest, "smallnum: %d", -2147483648);
	cr_expect_str_eq(dest, "smallnum: -2147483648");
	ft_asprintf(&dest, "%+03d", 1);
	cr_expect_str_eq(dest, "+01");
	ft_asprintf(&dest, "%+03d", 0);
	cr_expect_str_eq(dest, "+00");
}

Test(printf_number, padding)
{
	char *dest;

	ft_asprintf(&dest, "%5d", 42);
	cr_expect_str_eq(dest, "   42");
	ft_asprintf(&dest, "% d", 0);
	cr_expect_str_eq(dest, " 0");
	ft_asprintf(&dest, "%05d", 42);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%.5d", 42);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%10.5d", 42);
	cr_expect_str_eq(dest, "     00042");
	ft_asprintf(&dest, "%-10.5d", 42);
	cr_expect_str_eq(dest, "00042     ");
	ft_asprintf(&dest, "%-10.5d", 31337);
	cr_expect_str_eq(dest, "31337     ");
	ft_asprintf(&dest, "%-2.5d", 31337);
	cr_expect_str_eq(dest, "31337");
	ft_asprintf(&dest, "%2.5d", 31337);
	cr_expect_str_eq(dest, "31337");
}

Test(printf_number, padding_wildcard)
{
	char *dest;

	ft_asprintf(&dest, "%*d", 5, 42);
	cr_expect_str_eq(dest, "   42");
	ft_asprintf(&dest, "%0*d", 5, 42);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%.*d", 5, 42);
	cr_expect_str_eq(dest, "00042");
	ft_asprintf(&dest, "%*.*d", 10, 5, 42);
	cr_expect_str_eq(dest, "     00042");
	ft_asprintf(&dest, "%-*.*d", -10, 5, 42);
	cr_expect_str_eq(dest, "00042     ");
	ft_asprintf(&dest, "%-*.*d", 10, 5, 31337);
	cr_expect_str_eq(dest, "31337     ");
	ft_asprintf(&dest, "%-*.*d", 2, 5, 31337);
	cr_expect_str_eq(dest, "31337");
	ft_asprintf(&dest, "%*.*d", 2, 5, 31337);
	cr_expect_str_eq(dest, "31337");
}

Test(printf_number, sizes)
{
	char *dest;

	ft_asprintf(&dest, "%hhd", 1337);
	cr_expect_str_eq(dest, "57");
	ft_asprintf(&dest, "%hd", 1337);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%d", 1337);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%ld", 1337);
	cr_expect_str_eq(dest, "1337");
	ft_asprintf(&dest, "%5lld", 1337);
	cr_expect_str_eq(dest, " 1337");
	ft_asprintf(&dest, "%hhd", 2);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%hd", 2);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%d", 2);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%ld", 2);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%.5lld", 2);
	cr_expect_str_eq(dest, "00002");
	ft_asprintf(&dest, "%hhd", 0);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%hd", 0);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%d", 0);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%ld", 0);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%lld", 0);
	cr_expect_str_eq(dest, "0");
	ft_asprintf(&dest, "%hhd", 9223372036854775807L);
	cr_expect_str_eq(dest, "-1");
	ft_asprintf(&dest, "%hd", 9223372036854775807L);
	cr_expect_str_eq(dest, "-1");
	ft_asprintf(&dest, "%d", 9223372036854775807L);
	cr_expect_str_eq(dest, "-1");
	ft_asprintf(&dest, "%ld", 9223372036854775807L);
	cr_expect_str_eq(dest, "9223372036854775807");
	ft_asprintf(&dest, "%lld", 9223372036854775807L);
	cr_expect_str_eq(dest, "9223372036854775807");
}


Test(printf_number, advanced_padding)
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
	ft_asprintf(&dest, "%.d", 0);
	cr_expect_str_eq(dest, "");
	ft_asprintf(&dest, "%5.d", 0);
	cr_expect_str_eq(dest, "     ");
}
