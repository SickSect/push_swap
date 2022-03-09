#include "push_swap.h"

void ft_swap_sa(t_node *head, t_node *next)
{
    int	tmp;
	if(!head || !next)
		return ;
    tmp = head->data;
    head->data = next->data;
    next->data = tmp;
}

void ft_swap_sb(t_node *head, t_node *next)
{
    int	tmp;
	if(!head || !next)
		return ;
    tmp = head->data;
    head->data = next->data;
    next->data = tmp;
}

void ft_swap_ss(t_node *head_a, t_node *head_b)
{
    ft_swap_sa(head_a, head_a->p_next);
    ft_swap_sb(head_b, head_b->p_next);
}