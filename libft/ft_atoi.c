/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 16:48:31 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 14:15:35 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static	int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		result += (str[i] - '0');
		if (is_digit(str[i + 1]))
			result = result * 10;
		i++;
	}
	return (result * sign);
}
