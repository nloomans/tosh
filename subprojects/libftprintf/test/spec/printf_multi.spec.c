/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_multi.spec.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:20:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/05 17:07:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

Test(printf_multi, strings)
{
	char *dest;

	ft_asprintf(&dest, "%s%s", NULL, NULL);
	cr_expect_str_eq(dest, "(null)(null)");
	ft_asprintf(&dest, "%s%s", "Hello, ", "World");
	cr_expect_str_eq(dest, "Hello, World");
	ft_asprintf(&dest, "%s%s%s%s? Hmmm", "What does it mean to be ", NULL, " is it a state of mind? Or is it... ", NULL);
	cr_expect_str_eq(dest, "What does it mean to be (null) is it a state of mind? Or is it... (null)? Hmmm");
	ft_asprintf(&dest, "%s**%s**%s**%s? Hmmm", "What does it mean to be ", NULL, " is it a state of mind? Or is it... ", NULL);
	cr_expect_str_eq(dest, "What does it mean to be **(null)** is it a state of mind? Or is it... **(null)? Hmmm");
}

Test(printf_multi, strings_large)
{
	char *str;
	char *dest;

	str = malloc(100000);
	memset(str, '*', 100000);
	str[5] = 'a';
	str[478] = 'z';
	str[18977] = '*';
	str[99999] = '\0';
	ft_asprintf(&dest, "%s", str);
	cr_expect_str_eq(dest, str);
	ft_asprintf(&dest, "%c%.10s", 65, str);
	cr_expect_str_eq(dest, "A*****a****");
}

Test(printf_multi, atf_strings)
{
	char *dest;

	ft_asprintf(&dest, "%c%c... %s", '4', '2', "is cool");
	cr_expect_str_eq(dest, "42... is cool");
	ft_asprintf(&dest, "%c%c...%10s", '4', '2', "is cool");
	cr_expect_str_eq(dest, "42...   is cool");
}

Test(printf_multi, atf_numbers)
{
	char *dest;
	ft_asprintf(&dest, "%#o + %#x = %d", 5, 10, 5 + 10);
	cr_expect_str_eq(dest, "05 + 0xa = 15");
}

Test(printf_multi, atf_all)
{
	char *dest;

	ft_asprintf(&dest, "%#o + %#x = %d, that's %s", 5, 10, 5 + 10, "great");
	cr_expect_str_eq(dest, "05 + 0xa = 15, that's great");
}

Test(printf_multi, atf_percent)
{
	char *dest;

	ft_asprintf(&dest, "20%% cooler than %s", "you");
	cr_expect_str_eq(dest, "20% cooler than you");
	ft_asprintf(&dest, "%%%%20%% cooler than %s%%%%", "you");
	cr_expect_str_eq(dest, "%%20% cooler than you%%");
}

Test(printf_multi, atf_complex)
{
	char *dest;

	ft_asprintf(&dest, "%d%s%p%c%o", 42, "Hi", NULL, 65, 42);
	cr_expect_str_eq(dest, "42Hi0x0A52");
}
