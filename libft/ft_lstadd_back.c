/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:27:03 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 15:06:13 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* lst: The address of a pointer to the first link of a list.
   new: The address of a pointer to the node to be added to the list.
	Descr: Adds the node ’new’ at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
