#include "../includes/push_swap.h"

int push_swap(int ac, char **av)
{
    t_list      *stack_a_head;
    t_list      *stack_a_tail;
    int         i;
    long int    nb;

    i = 1;
   
    while (i < ac && av[i])
    {
        nb = ft_atoi(av[i]);
        if (nb > INT_MAX || nb < INT_MIN)
        {
            error_message();
            lst_clear(&stack_a_head);
            return (1);
        }
        if (i == 1)
            stack_a_head = lst_new(nb);
        else
            lst_add_tail(&stack_a_head, lst_new(nb));
        i++;
    }
    stack_a_tail = lst_find_tail(stack_a_head);
    while (stack_a_head != NULL)
    {
        printf("%d ", stack_a_head->nb);
        stack_a_head = stack_a_head->next;
    }
    printf("\n");
    while (stack_a_tail != NULL)
    {
        printf("%d ", stack_a_tail->nb);
        stack_a_tail = stack_a_tail->prev;
    }
    printf("\n");
    lst_clear(&stack_a_tail);
    return (0);
}

/* main:
*   Checks if the input arguments are correct and launches push_swap if they are.
*/
int main(int ac, char **av)
{
    if (ac <= 1)
        return (0);
    if (!is_correct_input(av))
    {
        error_message();
        return (1);
    }
    push_swap(ac, av);
    return (0);
}