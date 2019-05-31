/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:26:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 17:12:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

#define TEST(fmt, ...) do { \
	printf("-- Test for >> %s", fmt);\
	int res = printf(fmt, __VA_ARGS__);\
	int res2 = ft_printf(fmt, __VA_ARGS__);\
	printf("printf returned <%d>, ft_printf returned <%d>\n", res, res2);\
} while (0)


#define TEST 1
#define DEBUG 1
#define MEMP 0
#define LEN 512
#define MCMPARE(fmt, ...) do { \
	const char buff[LEN] = {};\
	const char buff2[LEN] = {};\
	if(DEBUG){\
		printf("\rArgs: %d, %d, %d, %d, %d\n", __VA_ARGS__);\
	}\
	int res = snprintf((char*)buff, LEN, (char*)fmt, __VA_ARGS__);\
	if(DEBUG && MEMP){\
		ft_printf("PRINTF:\n%#m\n", (char*)buff, LEN);\
	}\
	int res2 = ft_snprintf((char*)buff2, LEN, (char*)fmt, __VA_ARGS__);\
	if(DEBUG && MEMP){\
		ft_printf("FT_PRINTF:\n%#m\n", (char*)buff2, LEN);\
		printf("printf returned <%d>, ft_printf returned <%d>\n", res, res2);\
	}\
	if (TEST){\
		assert(!memcmp(buff, buff2, LEN));\
		assert(res == res2);\
	}\
} while(0)

int	extensive(void)
{
	int run = 0;
	const int range[4] = { -100, 100
						 , -100, 100 };
	const char *acc_fmt = "%{blue}%02d%{reset}> %{cyan}Searched %{red}%d%{reset} to %{red}%d%{reset}, %{red}%d %{reset}to %{red}%d %{reset}(%{magenta}%d%{reset} total tests)\n";
	MCMPARE("%0*.*s\n", -200, 6, NULL);
	{
		const char *fmt_str = "%-#*.*s\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, "Hello, world");
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%#*.*s\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, "Amazing");
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%0*.*s\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, "!!!!!!!!!!!!!!!");
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%0*.*s\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, NULL);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%*.*d\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 42);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*d\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 42);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%+*.*d\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 42);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%+*.*d\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 42);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*d\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 42);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*lld\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, -4);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*hhd\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 9999994);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*hhx\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 9999994);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*hhX\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, 42);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*hhX\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				MCMPARE(fmt_str, x, y, -888);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}
	{
		const char *fmt_str = "%-*.*hho\n";

		for (int x = range[0]; x < range[1]; x++)
			for (int y = range[2]; y < range[3]; y++)
				for (int n = -100; n < 100; n += 10)
					MCMPARE(fmt_str, x, y, n);
		ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
		run++;
	}

}

int	main(void)
{
	// extensive();
	// int run = 0;
	// const int range[4] = { -100, 100
	// 					 , -100, 100 };
	// const char *acc_fmt = "%{blue}%02d%{reset}> %{cyan}Searched %{red}%d%{reset} to %{red}%d%{reset}, %{red}%d %{reset}to %{red}%d %{reset}(%{magenta}%d%{reset} total tests)\n";
	// {
	// 	const char *fmt_str = "%-*.*hho\n";

	// 	for (int x = range[0]; x < range[1]; x++)
	// 		for (int y = range[2]; y < range[3]; y++)
	// 			for (int n = -100; n < 100; n += 10)
	// 				MCMPARE(fmt_str, x, y, n);
	// 	ft_printf(acc_fmt, run, range[0], range[1], range[2], range[3], (range[1] - range[0]) * (range[3] - range[2]));
	// 	run++;
	// }
	ft_printf("%C\n", 'x');
	return (0);
}
