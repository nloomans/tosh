/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:49:53 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/26 17:51:28 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void f(char *))
{
	if (*s == '\0')
		return ;
	f(s);
	ft_striter(s + 1, f);
}
