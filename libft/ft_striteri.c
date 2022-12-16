/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 20:08:47 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 20:27:46 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s: The string on which to iterate.
f: The function to apply to each character.
Descr: Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!*s || !s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
