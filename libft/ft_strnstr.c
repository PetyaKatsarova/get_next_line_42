/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 15:33:56 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/10/29 19:32:13 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j] && i + j < len
			&& j < ft_strlen(needle))
			j++;
		if (ft_strlen(needle) == j)
			return ((char *) &haystack[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
