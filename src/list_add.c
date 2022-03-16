#include "../includes/push_swap.h"
t_list  *lst_new(int nb)
{
    t_list *node;

    node = malloc(sizeof *node);
    if (!node)
        return (NULL);
    node->nb = nb;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

void    lst_add_head(t_list **list, t_list *node)
{
    t_list  *firstnode;
    if (!node)
        return ;
    if (!*list)
    {
        *list = node;
        return ;
    }
    firstnode = lst_find_head(*list);
    firstnode->prev = node;
    node->next = firstnode;
    node->prev = NULL;
    *list = node;
}

void    lst_add_tail(t_list **list, t_list *node)
{
    t_list  *lastnode;

    if (!node)
        return ;
    if (!*list)
    {
        *list = node;
        return ;
    }
    lastnode = lst_find_tail(*list);
    lastnode->next = node;
    node->prev = lastnode;
}