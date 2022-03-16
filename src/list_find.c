# include "../includes/push_swap.h"

t_list	*lst_find_tail(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*lst_find_head(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}