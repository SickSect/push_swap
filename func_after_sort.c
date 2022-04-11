#include "push_swap.h"

void chunk_checker(t_node **head_a, t_node **head_b, int chunk)
{
    (void)head_a;
    (void)head_b;
    (void)chunk;
    
}

static void rotate_after_push(t_node **head, int counter)
{
    if (counter == 1)
        ft_sa(head);
    else if (counter < ft_lstlen(head) / 2)
    {
        while (counter--)
        {
            ft_sa(head);
            ft_ra(head);
        }
    }
    else
    {
        counter = ft_lstlen(head) - counter;
        while (counter--)
        {
            ft_rra(head);
            ft_sa(head);
        }
        ft_sa(head);
    }
}
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
    rotate_after_push(head, counter);
}

void complex_rotater(t_node **head, int data, int min)
{
    t_node  *mv;
    int     data_inn;
    int     counter;

    mv = (*head);
    counter = 0;
    while (mv->data != min && mv != NULL)
        mv = mv->p_next;
    while (mv != NULL && mv->data < data)
        mv = mv->p_next;
    if (mv == NULL)
    {
        mv = (*head)->p_next;
        while (mv != NULL && mv->data < data)
            mv = mv->p_next;
    }
    data_inn = mv->data;
    mv = (*head);
    while (mv != NULL && mv->data != data_inn)
    {
        counter++;
        mv = mv->p_next;
    }
    rotate_after_push(head, counter - 1);
}