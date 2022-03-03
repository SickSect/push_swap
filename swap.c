#include "push_swap.h"

void f_sa(t_node *head, t_node *next)
{
    t_node *tmp;

    tmp = ft_lstnew(head->data);
    tmp->p_next = next->p_next;
    free(head);
    head = ft_lstnew(next->data);
    head->p_next = tmp;
    free(next);
}

void f_sb(t_node *head, t_node *next)
{
    t_node *tmp;

    tmp = ft_lstnew(head->data);
    tmp->p_next = next->p_next;
    free(head);
    head = ft_lstnew(next->data);
    head->p_next = tmp;
    free(next);
}

