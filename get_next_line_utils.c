/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:33:50 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/01/20 10:53:47 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	tmp = (char *)s + start;
	i = 0;
	while (*tmp && i < len)
		ret[i++] = *tmp++;
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (!dst || !src)
		return (0);
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// char	*ft_strdup(const char *str)
// {
// 	char	*ptr;

// 	ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, str, ft_strlen(str) + 1);
// 	return (ptr);
// }
