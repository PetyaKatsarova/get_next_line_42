/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:30:03 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/02 11:01:56 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = ft_nlen(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		if (str[0] == '-')
			str[length--] = '0' - (n % 10);
		else
		{
			str[length] = '0' + (n % 10);
			length--;
		}
		n = n / 10;
	}
	return (str);
}
