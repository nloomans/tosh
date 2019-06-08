/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_octal.spec.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:44:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/09 00:23:48 by nmartins      ########   odam.nl         */
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