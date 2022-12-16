/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 11:15:53 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 11:18:13 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
Descr: Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
