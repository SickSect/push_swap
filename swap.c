#include "push_swap.h"

void f_sa(t_node *head, t_node *next)
{
    t_node *tmp;

    tmp = next;
    head->p_next = next->p_next;
    next->p_next = head;

   free(tmp);
}