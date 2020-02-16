/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: ivan-tey <ivan-tey@student.codam.nl>          +:+                    */
/*       nloomans <nloomans@student.codam.nl>         +#+                     */
/*       aholster <aholster@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "error.h"

Test(is_error, detects_errors_as_errors) {
	cr_assert_eq(is_error(errorf("unable to allocate memory")), true);
}

Test(is_error, detects_non_errors_as_non_errors) {
	cr_assert_eq(is_error(ERROR_NONE), false);
}
