#include "push_swap.h"

void basic_rotater(t_node **head, int data)
{
    t_node  *mv;
    int     counter;

    mv = (*head)->p_next;
    counter = 0;
    while (mv != NULL && mv->data < data)
    {
        counter++;
        mv = mv->p_next;
    }
    if (counter < ft_lstlen(head) / 2)
    {
        while (counter--)
        {
            ft_sa(head);
            ft_ra(head);
        }
    }
    else
    {
        while (counter--)
        {
            ft_rra(head);
            ft_sa(head);
        }
    }
}

void complex_rotater(t_node **head, int data, int min)
{
    t_node *mv;

    mv = (*head);
    
}