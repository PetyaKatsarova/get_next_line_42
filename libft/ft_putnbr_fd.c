/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 14:28:48 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/01 10:57:26 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = nb * (-1);
		}
		if (nb > 9)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10 + '0'), fd);
	}
}
