/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:36:06 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 15:14:38 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* lst: The beginning of the list.
	Return v: Last node of the list , i will use: int	ft_lstsize(t_list *lst)
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*copy;

	copy = lst;
	while (copy)
	{
		if (!copy->next)
			return (copy);
		copy = copy->next;
	}
	return (copy);
}
