#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
    int             nb;
    struct s_list   *next;
    struct s_list   *prev;
} t_list;

typedef struct s_data
{
    struct s_list   *a;
    struct s_list   *a_tail;
    struct s_list   *b;
    struct s_list   *b_tail;
    int size;
} t_data;

/* push_swap */
int push_swap(int ac, char **av);
int sort(t_data **stack_data);

/* Data Structure */
t_data  *stack_init(int ac, char **av);
t_data  *stack_data_init(void);
void	data_clear(t_data *data);
void    reset_tails(t_data **data);

/* List Handling */
t_list  *lst_new(int nb);
void    lst_add_head(t_list **list, t_list *node);
void    lst_add_tail(t_list **list, t_list *node);
t_list	*lst_find_tail(t_list *lst);
t_list	*lst_find_head(t_list *lst);
void	lst_del_one(t_list *lst);
void	lst_clear(t_list **lst);

/* List actions */
int     do_action(t_data **stacks, char *action, int times);
void    do_swap(t_data **stacks, char *action, int times);
void    do_rotate(t_data **stacks, char *action, int times);
void    do_rev_rotate(t_data **stacks, char *action, int times);
void    do_push(t_data **stacks, char *action, int times);
t_list  *swap(t_list *stack);
t_list  *rotate(t_list *stack);
t_list  *rev_rotate(t_list *stack);
t_list  *push(t_list **src, t_list *dest);

/* Utils */
long int ft_atoi(const char *str);
int ft_strcmp(const char *s1, const char *s2);
void    ft_putstr(char *str);

/* Error */
void    error_message(void);

/* Input Check */
int is_correct_input(char **av);
int is_digit(char c);
int is_sign(char c);
int arg_is_number(char *av);
int arg_is_zero(char *av);
int have_duplicates(char **av);
int nbstr_cmp(const char *s1, const char *s2);

/* Debug */
void    debug_print_list(t_list *list);
void    do_action_tests(t_data *stack_data);
void    do_sort_actions_test(t_data **stack_data);


#endif