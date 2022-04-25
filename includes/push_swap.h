/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:47:42 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/25 17:38:41 by mcombeau         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

/* Initialization */
t_stack		*init_stack(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

/* push_swap */

/* Operations */
void		push(t_stack **src, t_stack **dest);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		swap(t_stack *stack);
void		do_sa(t_stack *stack_a);
void		do_sb(t_stack *stack_b);
void		do_ss(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack **stack);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		rev_rotate(t_stack **stack);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

/* Stack functions */
t_stack		*get_stack_tail(t_stack *stack);
t_stack		*get_stack_before_tail(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_tail(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* List actions */

/* Utils */
long int	ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *str);

/* Error */
void		exit_error(void);

/* Input Check */
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

/* Debug */

#endif