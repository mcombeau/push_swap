#include "push_swap.h"

void populate_list(t_list *list, int *array)
{
    int i;
    i = 1;
    while (i < 10)
    {
        lst_add_tail(&list, lst_new(array[i]));
        i++;
    }
}

int main(void)
{
    int array[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t_list  *head;
    t_list  *tmp;
    t_list  *tail;

    head = lst_new(array[0]);
    populate_list(head, array);
    tmp = head;
    printf("\nLIST FROM HEAD:\n");
    while (tmp != NULL)
    {
        printf("%d ", tmp->nb);
        tmp = tmp->next;
    }
    printf("\nLIST FROM TAIL:\n");
    tail = lst_find_tail(head);
    while (tail != NULL)
    {
        printf("%d ", tail->nb);
        tail= tail->prev;
    }
    printf("\n");
    lst_clear(&head);
    return (0);
}