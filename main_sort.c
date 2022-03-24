#include "push_swap.h"

void zero_act(t_node **head_a, t_node **head_b)
{
    t_node *mv;

    mv = (*head_a);
    while(mv != NULL)
    {
        mv->act = -1;
        mv = mv->p_next;
    }
    mv = (*head_b);
    while(mv != NULL)
    {
        mv->act = -1;
        mv = mv->p_next;
    }
}

static int check_moves(t_node **head_a, t_node **head_b)
{
    t_node	*mv;

    mv = (*head_b);
    while(mv != NULL)
    {
        mv->act = rotation(head_b, mv->data) + 1;
        where(head_a, mv->data);
        mv = mv->p_next;
    }
    mv = (*head_b);
    while (mv != NULL)
    {
        which_one(head_a, mv->data);
        mv = mv->p_next;
    }
    return (0);
}

void main_sort(t_node **head_a, t_node **head_b)
{
    zero_act(head_a, head_b);
    check_moves(head_a, head_b);
    printer(head_a, head_b);
}