#include "push_swap.h"

t_node	*ft_push_pa(t_node *head_a, t_node *head_b)
{
    int	tmp;
	t_node	*new;
	t_node	*save;

    if (!head_b)
        return ;
    tmp = head_b->data;
	new = ft_lstnew(tmp);
	new->p_next = head_a;
	save = head_b;
	head_b = head_b->p_next;
	ft_lstdel(head_b);
	return (new);
}

t_node	*ft_push_pb(t_node *head_a, t_node *head_b)
{
    int	tmp;
	t_node	*new;

    if (!head_b)
        return ;
    tmp = head_a->data;
	new = ft_lstnew(tmp);
	new->p_next = head_b;
	return (new);
}