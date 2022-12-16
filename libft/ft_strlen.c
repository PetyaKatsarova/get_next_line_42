/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:46:06 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/10/21 16:47:21 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
