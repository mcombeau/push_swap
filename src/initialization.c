#include "../includes/push_swap.h"

t_data  *stack_init(int ac, char **av)
{
    t_data      *stacks;
    int         i;
    long int    nb;

    stacks = stack_data_init();
    if (!stacks)
        return (NULL);
    i = 1;
    while (i < ac && av[i])
    {
        nb = ft_atoi(av[i]);
        if (nb > INT_MAX || nb < INT_MIN)
        {
            data_clear(stacks);
            return (NULL);
        }
        if (i == 1)
            stacks->a = lst_new(nb);
        else
            lst_add_tail(&(stacks->a), lst_new(nb));
        i++;
    }
    return (stacks);
}