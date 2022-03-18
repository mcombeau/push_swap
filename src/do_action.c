#include "../includes/push_swap.h"

void    do_swap(t_data **stacks, char *action, int times)
{
    int i;

    i = 0;
    while (i < times)
    {
        if (ft_strcmp("sa", action) == 0 || ft_strcmp("ss", action) == 0)
            (*stacks)->a = swap((*stacks)->a);
        if (ft_strcmp("sb", action) == 0 || ft_strcmp("ss", action) == 0)
            (*stacks)->b = swap((*stacks)->b);
        ft_putstr(action);
        ft_putstr("\n");
        i++;
    }
}

void    do_rotate(t_data **stacks, char *action, int times)
{
    int i;

    i = 0;
    while (i < times)
    {
        if (ft_strcmp("ra", action) == 0 || ft_strcmp("rr", action) == 0)
            (*stacks)->a = rotate((*stacks)->a);
        if (ft_strcmp("rb", action) == 0 || ft_strcmp("rr", action) == 0)
            (*stacks)->b = rotate((*stacks)->b);
        ft_putstr(action);
        ft_putstr("\n");
        i++;
    }
}

void    do_rev_rotate(t_data **stacks, char *action, int times)
{
    int i;

    i = 0;
    while (i < times)
    {
        if (ft_strcmp("rra", action) == 0 || ft_strcmp("rrr", action) == 0)
            (*stacks)->a = rev_rotate((*stacks)->a);
        if (ft_strcmp("rrb", action) == 0 || ft_strcmp("rrr", action) == 0)
            (*stacks)->b = rev_rotate((*stacks)->b);
        ft_putstr(action);
        ft_putstr("\n");
        i++;
    }
}

void    do_push(t_data **stacks, char *action, int times)
{
    int i;

    i = 0;
    while (i < times)
    {
        if (ft_strcmp("pa", action) == 0)
            (*stacks)->a = push(&(*stacks)->b, (*stacks)->a);
        if (ft_strcmp("pb", action) == 0)
            (*stacks)->b = push(&(*stacks)->a, (*stacks)->b);
        ft_putstr(action);
        ft_putstr("\n");
        i++;
    }
}

int do_action(t_data **stacks, char *action, int times)
{
    if (!(*stacks) || !action || !times)
        return(0);
    if (ft_strcmp("sa", action) == 0 || ft_strcmp("sb", action) == 0 || ft_strcmp("ss", action) == 0)
        do_swap(stacks, action, times);
    else if (ft_strcmp("ra", action) == 0 || ft_strcmp("rb", action) == 0 || ft_strcmp("rr", action) == 0)
        do_rotate(stacks, action, times);
    else if (ft_strcmp("rra", action) == 0 || ft_strcmp("rrb", action) == 0 || ft_strcmp("rrr", action) == 0)
        do_rev_rotate(stacks, action, times);
    else if (ft_strcmp("pa", action) == 0 || ft_strcmp("pb", action) == 0)
        do_push(stacks, action, times);
    reset_tails(stacks);
    return (1);
}