/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:33:50 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/20 13:59:16 by pkatsaro      ########   odam.nl         */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*mystr;

	i = 0;
	j = 0;
	mystr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!mystr)
		return (NULL);
	while (s1[i] != '\0')
	{
		mystr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mystr[i + j] = s2[j];
		j++;
	}
	mystr[i + j] = '\0';
	return (mystr);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*ptr;

// 	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
// 	return (ptr);
// }

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





