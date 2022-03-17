#include "../includes/push_swap.h"

/* swap:
*   Swaps the first two elements in the stack:
*   Ex.:
*   0 1 2 3 4 5 6 7 8 9 becomes:
*   1 0 2 3 4 5 6 7 8 9
*   Returns: a pointer to the new first element in the list.
*/
t_list  *swap(t_list *stack)
{
    int tmp;

    if (!stack)
        return (NULL);
    if (stack->prev != NULL)
        stack = lst_find_head(stack);
    if (stack->next == NULL)
        return (stack);
    tmp = stack->nb;
    stack->nb = stack->next->nb;
    stack->next->nb = tmp;
    return (stack);
}

/* rotate:
*   Shifts all the elements in the stack up by 1: the first element becomes the last.
*   Ex.:
*   0 1 2 3 4 5 6 7 8 9 becomes:
*   1 2 3 4 5 6 7 8 9 0
*   Returns: a pointer to the new first element in the list.
*/
t_list  *rotate(t_list *stack)
{
    t_list *last;
    t_list *tmp;

    if (!stack)
        return(NULL);
    if (stack->prev != NULL)
        stack = lst_find_head(stack);
    if (stack->next == NULL)
        return(stack);
    last = lst_find_tail(stack);
    tmp = stack->next;
    stack->prev = last;
    stack->next = NULL;
    last->next = stack;
    tmp->prev = NULL;
    return(tmp);
}

/* rev_rotate:
*   Shifts all the elements in the stack down by 1: the last element becomes the first.
*   Ex.:
*   0 1 2 3 4 5 6 7 8 9 becomes:
*   9 0 1 2 3 4 5 6 7 8
*   Returns: a pointer to the new first element in the list.
*/
t_list  *rev_rotate(t_list *stack)
{
    t_list *last;
    t_list *tmp;

    if (!stack)
        return(NULL);
    if (stack->prev != NULL)
        stack = lst_find_head(stack);
    if (stack->next == NULL)
        return(stack);
    last = lst_find_tail(stack);
    tmp = last->prev;
    last->prev = NULL;
    last->next = stack;
    stack->prev = last;
    tmp->next = NULL;
    return(last);
}

/* push:
*   Pushes the first element in source stack to the beginning of the dest stack.
*   Ex.:
*   Source stack:   1 2 3 4 5 6 7 8 9 becomes:
*                   2 3 4 5 6 7 8 9
*   Dest stack:     0                 becomes:
*                   1 0
*   Returns: a pointer to the first element of the dest list.
*/
t_list  *push(t_list **src, t_list *dest)
{
    if ((*src) == NULL)
        return (dest);
    if ((*src)->prev != NULL)
        *src = lst_find_head(*src);
    if (dest && dest->prev != NULL)
        dest = lst_find_head(dest);
    if (!dest)
        dest = lst_new((*src)->nb);
    else
        lst_add_head(&dest, lst_new((*src)->nb));
    if ((*src)->next == NULL)
    {
        lst_del_one((*src));
        *src = NULL;
        return(dest);
    }
    *src = (*src)->next;
    lst_del_one((*src)->prev);
    (*src)->prev = NULL;
    return (dest);
}