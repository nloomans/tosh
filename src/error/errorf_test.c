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

Test(errorf, should_return_error) {
	t_error	error;

	error = errorf("unable to allocate memory");
	cr_assert_str_eq(error.msg, "unable to allocate memory");
}

Test(errorf, should_wrap_errors) {
	t_error	error;

	error = errorf("unable to allocate memory");
	error = errorf("failed to create object: %s", error.msg);
	cr_assert_str_eq(error.msg,
		"failed to create object: unable to allocate memory");
}

Test(errorf, should_handle_invalid_format_strings) {
	t_error	error;

	error = errorf("testing %q");
	cr_assert_str_eq(error.msg,
		"an error occurred during the generation of this error");
}
