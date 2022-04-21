#include "push_swap.h"

/* lst_del_one:
*   Frees a single node in the list.
*/
void	lst_del_one(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

/* lst_clear:
*   Frees all nodes in the list.
*/
void	lst_clear(t_list **lst)
{
	t_list	*tmp;
    t_list  *node;

	if (!lst)
		return ;
    node = lst_find_head(*lst);
	while (node)
	{
		tmp = node->next;
		lst_del_one(node);
		node = tmp;
	}
	*lst = NULL;
}