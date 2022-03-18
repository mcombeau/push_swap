#include "../includes/push_swap.h"

t_data  *stack_data_init(void)
{
    t_data *data;
    data = malloc(sizeof *data);
    if (!data)
        return NULL;
    data->a = NULL;
    data->a_tail = NULL;
    data->b = NULL;
    data->b_tail = NULL;
    return (data);
}

void	data_clear(t_data *data)
{
	if (!data)
		return ;
    lst_clear(&(data->a));
    lst_clear(&(data->b));
    free(data);
    data = NULL;
}

void    reset_tails(t_data **data)
{
    if((*data)->a != NULL)
    {
        if ((*data)->a_tail == NULL || (*data)->a_tail->next != NULL)
            (*data)->a_tail = lst_find_tail((*data)->a);
    }
    else
        (*data)->a_tail = NULL;
    if((*data)->b != NULL)
    {
        if((*data)->b_tail == NULL || (*data)->b_tail->next != NULL)
            (*data)->b_tail = lst_find_tail((*data)->b);
    }
    else
        (*data)->b_tail = NULL;
}