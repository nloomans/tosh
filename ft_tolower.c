/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 19:26:24 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 10:42:59 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	if (u_c >= 'A' && u_c <= 'Z')
		return (c - ('A' - 'a'));
	else
		return (c);
}
