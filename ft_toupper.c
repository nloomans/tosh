/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 19:23:45 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 10:43:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	if (u_c >= 'a' && u_c <= 'z')
		return (c + ('A' - 'a'));
	else
		return (c);
}
