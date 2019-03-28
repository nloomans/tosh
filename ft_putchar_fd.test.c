/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:23:28 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/28 12:35:53 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>

TEST(test_basic, void putchar_fdf(char c, int fd))
{
	PRINT();
	char src = 'a';
	char dst[1];

	int fd = open("/tmp/testing.txt", O_RDWR | O_TRUNC);

	putchar_fdf(src, fd);

	lseek(fd, 0, SEEK_SET);
	read(fd, dst, 1);
	assert(src == dst[0]);

	close(fd);
}

int		main(void)
{
	RUN(test_basic, ft_putchar_fd);
}
