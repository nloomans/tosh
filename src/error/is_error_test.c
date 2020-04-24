/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh-21Shell                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "error.h"

Test(is_error, detects_errors_as_errors) {
	cr_assert_eq(is_error(errorf("unable to allocate memory")), true);
}

Test(is_error, detects_non_errors_as_non_errors) {
	cr_assert_eq(is_error(error_none()), false);
}
