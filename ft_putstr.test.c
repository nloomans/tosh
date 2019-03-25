/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:49:52 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 17:23:44 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

TEST(test_basic, void putstrf(char const *s))
{
	PRINT();
	char src[] = "Hello, 世界 😀";
	char dst[sizeof(src)];
	memset(dst, '\0', sizeof(dst));

	FILE *file = freopen("/tmp/testing.txt", "w+", stdout);
	int fd = fileno(file);

	putstrf(src);

	lseek(fd, 0, SEEK_SET);
	read(fd, dst, sizeof(dst));
	assert(memcmp(src, dst, sizeof(src)) == 0);
	fclose(file);
}

int		main(void)
{
	RUN(test_basic, ft_putstr);
}
