/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:45:38 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/04 11:27:21 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* lst: The node to free. del: The address of the function used
	 to delete the content.
	Descr: Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed. use free()
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
