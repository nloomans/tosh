/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_should_fail.spec.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 20:47:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 16:13:48 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_should_fail, unterminated_percent)
{
	char *dest;

	cr_assert_eq(-1, ft_asprintf(&dest, "%"));
}

Test(printf_should_fail, undefined_specification)
{
	char *dest;

	cr_assert_eq(-1, ft_asprintf(&dest, "%zz"));
}
