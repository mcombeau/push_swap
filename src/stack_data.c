#include "../includes/push_swap.h"

t_data  *stack_data_init(void)
{
    t_data *data;
    data = malloc(sizeof *data);
    if (!data)
        return NULL;
    data->a = NULL;
    data->b = NULL;
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