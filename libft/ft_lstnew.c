/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 14:45:35 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/11/01 16:34:31 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* content: The content to create the node with. 
Return val: the new node, use malloc
Descr: Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*newls;

	newls = (t_list *) malloc(sizeof (*newls));
	if (!newls)
		return (NULL);
	newls->content = content;
	newls->next = NULL;
	return (newls);
}
