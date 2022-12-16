/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:53:26 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/10/22 16:10:40 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// write n seroed bytes(aka '\0') to the str s, if n==0: do nth

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
		((unsigned char *)s)[i++] = '\0';
}
