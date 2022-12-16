/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:33:50 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/16 18:32:46 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	char	*temp;
	size_t	i;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	temp = (char *)s + start;
	i = 0;
	while (*temp && i < len)
		res[i++] = *temp++;
	res[i] = 0;
	return (res);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*res;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (ret);
}
