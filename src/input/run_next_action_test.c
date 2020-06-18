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

ssize_t fake_read_keypress(int fd, void *buf, size_t count) {
	(void)count;
	cr_expect_eq(fd, STDIN_FILENO);
	((char *)buf)[0] = ',';
	return (1);
}

Test(input__run_next_action, keypress) {
	struct s_input__state state = {
		.buffer = strdup("Hello World!"),
		.cursor_position = 5,
	};

	bool did_invalidate = false;
	t_error error = input__run_next_action(
		&state, NULL, &did_invalidate, fake_read_keypress);

	cr_expect_not(is_error(error));
	cr_expect_str_eq(state.buffer, "Hello, World!");
	cr_expect_eq(state.cursor_position, 6);
	cr_expect(did_invalidate);

	free(state.buffer);
}

char *keypresses_build_message[] = {
	"H", "e", "l", "l", "o", " ", "o", "r", "l", "d", "!",
	"\x1b[D", "\x1b[D", "\x1b[D", "\x1b[D", "\x1b[D", "\x1b[D", ",",
	"\x1b[C", "W",
};

ssize_t fake_read_build_message(int fd, void *buf, size_t count) {
	static int i = 0;
	cr_expect_eq(fd, STDIN_FILENO);
	ft_strlcpy(buf, keypresses_build_message[i], count);
	size_t ret = strlen(keypresses_build_message[i]);
	i++;
	return (ret);
}

Test(input__run_next_action, build_message) {
	struct s_input__state state = {
		.buffer = strdup(""),
		.cursor_position = 0,
	};

	for (size_t i = 0;
		i < sizeof(keypresses_build_message) / sizeof(*keypresses_build_message);
		i++)
	{
		bool did_invalidate = false;
		t_error error = input__run_next_action(
			&state, NULL, &did_invalidate, fake_read_build_message);
		cr_expect(did_invalidate);
		cr_expect_not(is_error(error));
	}

	cr_expect_str_eq(state.buffer, "Hello, World!");
	cr_expect_eq(state.cursor_position, 8);

	free(state.buffer);
}

ssize_t fake_read_backspace(int fd, void *buf, size_t count) {
	(void)count;
	cr_expect_eq(fd, STDIN_FILENO);
	((char *)buf)[0] = '\x7f';
	return (1);
}

Test(input__run_next_action, backspace_empty) {
	struct s_input__state state = {
		.buffer = strdup(""),
		.cursor_position = 0,
	};

	bool did_invalidate = false;
	t_error error = input__run_next_action(
		&state, NULL, &did_invalidate, fake_read_backspace);

	cr_expect_not(is_error(error));
	cr_expect_str_eq(state.buffer, "");
	cr_expect_eq(state.cursor_position, 0);
	cr_expect(did_invalidate);

	free(state.buffer);
}

Test(input__run_next_action, backspace) {
	struct s_input__state state = {
		.buffer = strdup("Hellow, World!"),
		.cursor_position = 6,
	};


	bool did_invalidate = false;
	t_error error = input__run_next_action(
		&state, NULL, &did_invalidate, fake_read_backspace);

	cr_expect_not(is_error(error));
	cr_expect_str_eq(state.buffer, "Hello, World!");
	cr_expect_eq(state.cursor_position, 5);
	cr_expect(did_invalidate);

	free(state.buffer);
}
