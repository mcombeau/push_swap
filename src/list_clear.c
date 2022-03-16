#include "../includes/push_swap.h"

void	lst_del_one(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	lst_clear(t_list **lst)
{
	printf("Freeing list...\n");
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
	printf("List freed.\n");
}