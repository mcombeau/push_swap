#include "../includes/push_swap.h"

void debug_print_list(t_list *list)
{
    if (list == NULL)
        printf("NULL");
    while(list != NULL)
    {
        printf("%d ", list->nb);
        list = list->next;
    }
    printf("\n");
}

void    do_tests(t_data *stack_data)
{
    debug_print_list(stack_data->a);

    printf("\n--SWAP TEST:\n");
    debug_print_list(stack_data->a);
    stack_data->a = swap(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = swap(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = swap(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = swap(stack_data->a);
    debug_print_list(stack_data->a);

    printf("\n--ROTATE TEST:\n");
    debug_print_list(stack_data->a);
    stack_data->a = rotate(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = rotate(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = rotate(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = rotate(stack_data->a);
    debug_print_list(stack_data->a);

    printf("\n--REVERSE ROTATE TEST:\n");
    debug_print_list(stack_data->a);
    stack_data->a = rev_rotate(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = rev_rotate(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = rev_rotate(stack_data->a);
    debug_print_list(stack_data->a);
    stack_data->a = rev_rotate(stack_data->a);
    debug_print_list(stack_data->a);

    printf("\n--PUSH TEST:\n");
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);

    printf("Pushing stack a to b:\n");
    stack_data->b = push(&stack_data->a, stack_data->b);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
    
    stack_data->b = push(&stack_data->a, stack_data->b);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
    
    stack_data->b = push(&stack_data->a, stack_data->b);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
  
    printf("Pushing stack b to a:\n");
    stack_data->a = push(&stack_data->b, stack_data->a);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);

    stack_data->a = push(&stack_data->b, stack_data->a);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
    
    stack_data->a = push(&stack_data->b, stack_data->a);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
    
    stack_data->a = push(&stack_data->b, stack_data->a);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
    
    stack_data->a = push(&stack_data->b, stack_data->a);
    printf("Stack a\t:\t");
    debug_print_list(stack_data->a);
    printf("Stack b\t:\t");
    debug_print_list(stack_data->b);
}