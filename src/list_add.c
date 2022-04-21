#include "push_swap.h"

/* lst_new:
*   Creates and allocates memory for the initial node in a double linked list.
*/
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

/* lst_add_head:
*   Adds a node to the head of the list:
*   [NULL]<-[new]<->[*]<->[*]<->[*]->[NULL]
*/
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

/* lst_add_tail:
*   Adds a node to the tail of the list:
*   [NULL]<-[*]<->[*]<->[*]<->[new]->[NULL]
*/
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