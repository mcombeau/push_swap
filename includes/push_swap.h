/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:47:42 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/26 17:02:28 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */
t_stack		*init_stack(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

/* Sorting Algorithms */
int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position */
void		get_position(t_stack **stack);
int			get_lowest_index_position(t_stack **stack);
int			get_highest_target(t_stack **stack_a, int cmp, int target);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		get_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */
void		rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		rotate_one(t_stack **a, t_stack **b, int *cost, char stack);
void		calculate_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */
void		push(t_stack **src, t_stack **dest);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		swap(t_stack *stack);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		rev_rotate(t_stack **stack);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

/* Stack Functions */
t_stack		*get_stack_tail(t_stack *stack);
t_stack		*get_stack_before_tail(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_tail(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* Utils */
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

/* Error */
void		exit_error(void);

/* Input Check */
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

#endif