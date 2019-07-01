/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_string.spec.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:20:13 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 17:24:44 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_string, null)
{
	char *dest;

	ft_asprintf(&dest, "%s", NULL);
	cr_expect_str_eq(dest, "(null)");
}

Test(printf_string, pad_null)
{
	char *dest;

	ft_asprintf(&dest, "%10s", NULL);
	cr_expect_str_eq(dest, "    (null)");
}

Test(printf_string, pad_null_wildcard)
{
	char *dest;

	ft_asprintf(&dest, "%*s", 10, NULL);
	cr_expect_str_eq(dest, "    (null)");
}

Test(printf_string, normal_string)
{
	char *dest;

	ft_asprintf(&dest, "%s", "normal");
	cr_expect_str_eq(dest, "normal");
}

Test(printf_string, pad_normal_string_wildcard)
{
	char *dest;

	ft_asprintf(&dest, "%*s", 10, "normal");
	cr_expect_str_eq(dest, "    normal");
}

Test(printf_string, normal_string_cutoff)
{
	char *dest;

	ft_asprintf(&dest, "%.5s", "hello world");
	cr_expect_str_eq(dest, "hello");
	ft_asprintf(&dest, "%.5s", "world");
	cr_expect_str_eq(dest, "world");
	ft_asprintf(&dest, "%.2s", "world");
	cr_expect_str_eq(dest, "wo");
	ft_asprintf(&dest, "%.10s", "world");
	cr_expect_str_eq(dest, "world");
}

Test(printf_string, normal_string_cutoff_wildcard)
{
	char *dest;

	ft_asprintf(&dest, "%.*s", 5, "HELLO FELLOW HUMAN");
	cr_expect_str_eq(dest, "HELLO");
	ft_asprintf(&dest, "%.*s", 5, "");
	cr_expect_str_empty(dest);
}

Test(printf_string, leftpad_normal_string)
{
	char *dest;
	char *dest2;

	ft_asprintf(&dest, "%-5s", "HI");
	cr_expect_str_eq(dest, "HI   ");
	ft_asprintf(&dest2, "%-1s", "HI");
	cr_expect_str_eq(dest2, "HI");
}

Test(printf_string, leftpad_normal_string_wildcard)
{
	char *dest;

	ft_asprintf(&dest, "%-*s", 5, "HI");
	cr_expect_str_eq(dest, "HI   ");
	cr_expect_eq(ft_asprintf(&dest, "%-*s", 1, "HI"), 2);
	cr_expect_str_eq(dest, "HI");
}

Test(printf_string, complicated_string)
{
	char *dest;

	ft_asprintf(&dest, "%-*.*s:%s", 10, 5, "fight me", "now");
	cr_expect_str_eq(dest, "fight     :now");
}

Test(printf_char, basic)
{
	char *dest;

	ft_asprintf(&dest, "%c", 'a');
	cr_expect_str_eq(dest, "a");
	ft_asprintf(&dest, "%5c", 'a');
	cr_expect_str_eq(dest, "    a");
	ft_asprintf(&dest, "%-5c", 'a');
	cr_expect_str_eq(dest, "a    ");
	ft_asprintf(&dest, "%*c", 5, 'a');
	cr_expect_str_eq(dest, "    a");
	ft_asprintf(&dest, "%*c", -5, 'a');
	cr_expect_str_eq(dest, "a    ");
}
