# include "../includes/push_swap.h"

/* lst_find_tail:
*   Returns a pointer to the last node in the list.
*/
t_list	*lst_find_tail(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* lst_find_head:
*   Returns a pointer to the first node in the list.
*/
t_list	*lst_find_head(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}