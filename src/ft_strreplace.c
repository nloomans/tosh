/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 18:21:10 by nloomans      #+#    #+#                 */
/*   Updated: 2019/10/17 18:23:46 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char **to_replace, char *new)
{
	ft_strdel(to_replace);
	*to_replace = new;
}
