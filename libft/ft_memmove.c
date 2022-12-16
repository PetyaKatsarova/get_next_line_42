/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:42:47 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 13:52:40 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy byte string
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!len || dst == src)
		return (dst);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
