/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:26:20 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/26 16:09:37 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	get_highest_target(t_stack **stack_a, int cmp, int target)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	if (cmp != INT_MAX)
		return (target);
	while (tmp_a)
	{
		if (tmp_a->index < cmp)
		{
			cmp = tmp_a->index;
			target = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		cmp_a;
	int		target_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	while (tmp_b)
	{
		tmp_a = *stack_a;
		cmp_a = INT_MAX;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < cmp_a)
			{
				cmp_a = tmp_a->index;
				target_pos = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
		target_pos = get_highest_target(stack_a, cmp_a, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
