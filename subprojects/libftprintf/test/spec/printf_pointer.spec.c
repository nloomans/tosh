/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_pointer.spec.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:20:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 16:17:09 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_pointer, normal)
{
	char *dest;

	ft_asprintf(&dest, "%p", (void *)42);
	cr_expect_str_eq(dest, "0x2a");
	ft_asprintf(&dest, "%p", (void *)0xDEADBEEF);
	cr_expect_str_eq(dest, "0xdeadbeef");
	ft_asprintf(&dest, "%p", (void *)0x3456789);
	cr_expect_str_eq(dest, "0x3456789");
	ft_asprintf(&dest, "%p", (void *)0x12ABCDEF);
	cr_expect_str_eq(dest, "0x12abcdef");
}

Test(printf_pointer, capital)
{
	char *dest;

	ft_asprintf(&dest, "%P", (void *)42);
	cr_expect_str_eq(dest, "0X2A");
	ft_asprintf(&dest, "%P", (void *)0xDEADBEEF);
	cr_expect_str_eq(dest, "0XDEADBEEF");
	ft_asprintf(&dest, "%P", (void *)0x3456789);
	cr_expect_str_eq(dest, "0X3456789");
	ft_asprintf(&dest, "%P", (void *)0x12ABCDEF);
	cr_expect_str_eq(dest, "0X12ABCDEF");
}

Test(printf_pointer, padding)
{
	char *dest;

	ft_asprintf(&dest, "%5p", 42);
	cr_expect_str_eq(dest, " 0x2a");
	ft_asprintf(&dest, "%1p", 42);
	cr_expect_str_eq(dest, "0x2a");
	ft_asprintf(&dest, "%3p", 42);
	cr_expect_str_eq(dest, "0x2a");
	ft_asprintf(&dest, "%-1p", 42);
	cr_expect_str_eq(dest, "0x2a");
	ft_asprintf(&dest, "%-5p", 42);
	cr_expect_str_eq(dest, "0x2a ");
}

Test(printf_pointer, padding_left_complex)
{
	char *dest;

	ft_asprintf(&dest, "%-*p", 5, 42);
	cr_expect_str_eq(dest, "0x2a ");
	ft_asprintf(&dest, "%*p!*%%", -5, 42);
	cr_expect_str_eq(dest, "0x2a !*%");
	ft_asprintf(&dest, "%*P>>", -5, 42);
	cr_expect_str_eq(dest, "0X2A >>");
}
