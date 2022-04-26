/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:26:29 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/26 17:14:04 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

void	rotate_one(t_stack **a, t_stack **b, int *cost, char stack)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (stack == 'a')
				do_ra(a);
			else if (stack == 'b')
				do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (stack == 'a')
				do_rra(a);
			else if (stack == 'b')
				do_rrb(b);
			(*cost)++;
		}
	}
}

void	calculate_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_one(a, b, &cost_a, 'a');
	rotate_one(a, b, &cost_b, 'b');
	do_pa(a, b);
}
