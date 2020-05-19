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
#include <unistd.h>
#include <libft.h>
#include "private.h"

/*
** We are using the Nested Functions GNU C extention for this test file.
** See: https://gcc.gnu.org/onlinedocs/gcc/Nested-Functions.html
*/
#pragma GCC diagnostic ignored "-Wpedantic"

Test(input__run_next_action, keypress) {
	struct s_input__state state = {
		.buffer = strdup("Hello World!"),
		.cursor_position = 5,
	};

	ssize_t fake_read(int fd, void *buf, size_t count) {
		(void)count;
		cr_expect_eq(fd, STDIN_FILENO);
		((char *)buf)[0] = ',';
		return (1);
	}

	bool did_invalidate = false;
	t_error error = input__run_next_action(&state, &did_invalidate, fake_read);

	cr_expect_not(is_error(error));
	cr_expect_str_eq(state.buffer, "Hello, World!");
	cr_expect_eq(state.cursor_position, 6);
	cr_expect(did_invalidate);

	free(state.buffer);
}

Test(input__run_next_action, build_message) {
	struct s_input__state state = {
		.buffer = strdup(""),
		.cursor_position = 0,
	};

	char *keypresses[] = {
		"H", "e", "l", "l", "o", " ", "o", "r", "l", "d", "!",
		"\x1b[D", "\x1b[D", "\x1b[D", "\x1b[D", "\x1b[D", "\x1b[D", ",",
		"\x1b[C", "W", 
	};

	for (size_t i = 0; i < sizeof(keypresses) / sizeof(*keypresses); i++)
	{
		ssize_t fake_read(int fd, void *buf, size_t count) {
			cr_expect_eq(fd, STDIN_FILENO);
			ft_strlcpy(buf, keypresses[i], count);
			return (strlen(keypresses[i]));
		}

		bool did_invalidate = false;
		t_error error = input__run_next_action(
			&state, &did_invalidate, fake_read);
		cr_expect(did_invalidate);
		cr_expect_not(is_error(error));
	}

	cr_expect_str_eq(state.buffer, "Hello, World!");
	cr_expect_eq(state.cursor_position, 8);

	free(state.buffer);
}
