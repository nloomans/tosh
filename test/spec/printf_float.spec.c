/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_float.spec.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:20:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/14 13:09:31 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_float, normal)
{
	char *dest;

	ft_asprintf(&dest, "%f", 2.5);
	cr_expect_str_eq(dest, "2.500000");
	ft_asprintf(&dest, "%f", 1.0);
	cr_expect_str_eq(dest, "1.000000");
	ft_asprintf(&dest, "%f", -2.0);
	cr_expect_str_eq(dest, "-2.000000");
	ft_asprintf(&dest, "%f", 12345.0);
	cr_expect_str_eq(dest, "12345.000000");
}

Test(printf_float, precision)
{
	char *dest;

	ft_asprintf(&dest, "%.0f", 2.5);
	cr_expect_str_eq(dest, "2");
	ft_asprintf(&dest, "%.1f", 1.0);
	cr_expect_str_eq(dest, "1.0");
	ft_asprintf(&dest, "%.0f", -2.0);
	cr_expect_str_eq(dest, "-2");
	ft_asprintf(&dest, "%.1f", -2.0);
	cr_expect_str_eq(dest, "-2.0");
	ft_asprintf(&dest, "%.2f", -2.0);
	cr_expect_str_eq(dest, "-2.00");
	ft_asprintf(&dest, "%f", 12345.0);
	cr_expect_str_eq(dest, "12345.000000");
	ft_asprintf(&dest, "%.0f", 12345.0);
	cr_expect_str_eq(dest, "12345");
}

Test(printf_float, size)
{
	char *dest;

	ft_asprintf(&dest, "%Lf", 2.5L);
	cr_expect_str_eq(dest, "2.500000");
	ft_asprintf(&dest, "%llf", 1.0L);
	cr_expect_str_eq(dest, "1.000000");
	ft_asprintf(&dest, "%Lf", -2.0L);
	cr_expect_str_eq(dest, "-2.000000");
	ft_asprintf(&dest, "%Lf", 12345.0L);
	cr_expect_str_eq(dest, "12345.000000");
}
