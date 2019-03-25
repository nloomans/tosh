/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.test.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:27:49 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 16:30:49 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* @disable-valgrind */

TEST(test_basic, void putstr_fdf(char const *s, int fd))
{
	PRINT();
	char src[] = "Hello, 世界 😀";
	char dst[sizeof(src)];
	memset(dst, '\0', sizeof(dst));

	FILE *file = tmpfile();
	int fd = fileno(file);

	putstr_fdf(src, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, dst, sizeof(dst));
	assert(memcmp(src, dst, sizeof(src)) == 0);
	fclose(file);
}

int		main(void)
{
	RUN(test_basic, ft_putstr_fd);
}
