#include "push_swap.h"

t_node  *lstlast(t_node **head)
{
    t_node *tmp;

    if (!(*head))
        return (NULL);
    tmp = *head;
    while(tmp->p_next != NULL)
        tmp = tmp->p_next;
    return (tmp);
}