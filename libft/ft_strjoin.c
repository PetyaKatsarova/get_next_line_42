/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 19:31:51 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/01 16:35:37 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
