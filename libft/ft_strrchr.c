/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 19:22:13 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/10/21 15:17:01 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = ft_strlen(temp);
	while (i > -1)
	{
		if (temp[i] != (char)c)
			i--;
		else
			return (&temp[i]);
	}
	return (NULL);
}
