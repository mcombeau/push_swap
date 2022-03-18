#include "../includes/push_swap.h"

/*  is_sorted:
*   Checks to see if a list is sorted in ascending order.
*   Returns: 1 if it is sorted, 0 if not.
*/
int is_sorted(t_list *stack)
{
    if (!stack)
        return (0);
    if (stack->prev != NULL)
        stack = lst_find_head(stack);
    while (stack != NULL && stack->next != NULL)
    {
        if (stack->nb > stack->next->nb)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    tiny_sort(t_data **stacks)
{
    if ((*stacks)->a->nb > (*stacks)->a_tail->nb)
    {
        printf("\t[tiny sort] Last nb is smaller than first.\n\t");
        do_action(stacks, "ra", 1);
        debug_print_list((*stacks)->a);
    }
    if ((*stacks)->a->nb > (*stacks)->a->next->nb)
    {
        printf("\t[tiny sort] Second nb is smaller than first.\n\t");
        do_action(stacks, "sa", 1);
        debug_print_list((*stacks)->a);
    }
    if ((*stacks)->a->next->nb > (*stacks)->a_tail->nb)
    {
        printf("\t[tiny sort] Last nb is smaller than second.\n\t");
        do_action(stacks, "rra", 1);
        debug_print_list((*stacks)->a);
    }
}

int sort(t_data **stack_data)
{
    if ((*stack_data)->b == NULL && is_sorted((*stack_data)->a))
        return (1);
    if ((*stack_data)->size <= 3)
    {
        printf("[sort] Sorting %d numbers.\n", (*stack_data)->size);
        tiny_sort(stack_data);
    }
//    do_action_tests(*stack_data);
//    do_sort_actions_test(stack_data);
//    printf("\n");
    return (sort(stack_data));
}