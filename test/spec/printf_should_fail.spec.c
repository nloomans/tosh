/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_should_fail.spec.c                               :+:    :+:       */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 20:47:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 19:40:06 by nmartins            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_should_fail, unterminated_percent)
{
	cr_skip_test("unterminated_percent");
	char *dest;

	cr_assert_eq(-1, ft_asprintf(&dest, "%"));
}

Test(printf_should_fail, undefined_specification)
{
	char *dest;

	cr_assert_eq(-1, ft_asprintf(&dest, "%zz"));
}
