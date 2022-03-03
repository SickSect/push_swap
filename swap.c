#include "push_swap.h"

struct s_node *f_sa(t_node *head, t_node *next)
{
    head->p_next = next->p_next;
    next->p_next = head;
    return (next);
}

struct s_node *f_sb(t_node *head, t_node *next)
{
    head->p_next = next->p_next;
    next->p_next = head;
    return (next);
}

void f_ss(t_node *head_a, t_node *head_b)
{
    head_a = f_sa(head_a,head_a->p_next);
    head_b = f_sb(head_b, head_b->p_next);
}

