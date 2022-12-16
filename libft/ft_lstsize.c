/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:57:22 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/01 17:34:19 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* lst: The beginning of the list.
	Return v: The length of the list
	Descr: Counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != 0)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
