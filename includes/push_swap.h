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

typedef struct s_stack
{
    struct s_list   *head;
    struct s_list   *tail;
} t_stack;

/* List Handling */
t_list  *lst_new(int nb);
void    lst_add_head(t_list **list, t_list *node);
void    lst_add_tail(t_list **list, t_list *node);
t_list	*lst_find_tail(t_list *lst);
t_list	*lst_find_head(t_list *lst);
void	lst_del_one(t_list *lst);
void	lst_clear(t_list **lst);

/* Utils */
long int ft_atoi(const char *str);

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

#endif