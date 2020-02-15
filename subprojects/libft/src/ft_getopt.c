/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getopt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 18:03:23 by nloomans      #+#    #+#                 */
/*   Updated: 2020/02/12 18:03:24 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "libft.h"

/*
** ft_getopt parses the options for you. Example usage:
**
** int     main(int argc, char **argv)
** {
**     struct s_ft_getopt  opt;
**     bool                opt_a;
**     char                *opt_b_arg;
**     bool                opt_c;
**
**     opt = FT_GETOPT_DEFAULT;
**     opt_a = false;
**     opt_b_arg = NULL;
**     opt_c = false;
**     while (ft_getopt(&opt, argc, argv, "ab:c"))
**     {
**         if (opt.opt == 'a')
**             opt_a = true;
**         else if (opt.opt == 'b')
**             opt_b_arg = opt.arg;
**         else if (opt.opt == 'c')
**             opt_c = true;
**     }
**     if (opt.illegal)
**         return (1);
**     // use options
**     return (0);
** }
*/

static void	print_error(char *argv0, char *msg, char opt)
{
	write(STDERR_FILENO, argv0, ft_strlen(argv0));
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, &opt, 1);
	write(STDERR_FILENO, "\n", sizeof("\n"));
}

static int	process_arg(struct s_ft_getopt *opt, char **argv)
{
	if (argv[opt->index][opt->group_index + 1])
		opt->arg = argv[opt->index] + opt->group_index + 1;
	else if (argv[opt->index + 1])
	{
		opt->arg = argv[opt->index + 1];
		opt->index++;
	}
	else
		return (-1);
	opt->group_index = 1;
	opt->index++;
	return (0);
}

static int	process(struct s_ft_getopt *opt,
				char **argv, char matched_opt, bool has_arg)
{
	opt->opt = matched_opt;
	if (has_arg)
	{
		if (process_arg(opt, argv) == -1)
		{
			opt->illegal = true;
			print_error(argv[0], ": option requires an argument -- ",
				argv[opt->index][opt->group_index]);
			return (-1);
		}
	}
	else
	{
		if (argv[opt->index][opt->group_index + 1])
			opt->group_index++;
		else
		{
			opt->group_index = 1;
			opt->index++;
		}
	}
	return (0);
}

bool		ft_getopt(struct s_ft_getopt *opt, int argc, char **argv,
				const char *optstring)
{
	size_t	i;

	if (opt->index >= argc || argv[opt->index][0] != '-')
		return (false);
	if (argv[opt->index][1] == '-')
	{
		opt->index++;
		return (false);
	}
	i = 0;
	while (i < ft_strlen(optstring))
	{
		if (ft_isalnum(optstring[i]) &&
			optstring[i] == argv[opt->index][opt->group_index])
		{
			if (process(opt, argv, optstring[i], optstring[i + 1] == ':') == -1)
				return (false);
			return (true);
		}
		i++;
	}
	opt->illegal = true;
	print_error(argv[0], ": illegal option -- ",
		argv[opt->index][opt->group_index]);
	return (false);
}
