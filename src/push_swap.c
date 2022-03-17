#include "../includes/push_swap.h"



int push_swap(int ac, char **av)
{
    t_data *stack_data;

    stack_data = stack_init(ac, av);
    if (!stack_data)
    {
        error_message();
        return (1);
    }
    do_tests(stack_data);
    data_clear(stack_data);
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