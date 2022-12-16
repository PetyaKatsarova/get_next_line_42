/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 17:57:20 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/10/21 11:16:29 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != (char)c)
	{
		if (!*chr)
			return (0);
		chr++;
	}
	return (chr);
}
