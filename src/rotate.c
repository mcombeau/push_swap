/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:18:17 by mcombeau          #+#    #+#             */
/*   Updated: 2022/09/28 11:13:19 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* do_ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* do_rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* do_rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
