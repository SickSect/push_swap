#include "push_swap.h"

<<<<<<< HEAD
void ft_pb(t_node **head_a, t_node **head_b)
{
    t_node *new_head;

    if(!(*head_a))
        return ;
    if(!(*head_b))
    {
        new_head = (*head_a)->p_next;
        *head_b = *head_a;
        (*head_b)->p_next = NULL;
        *head_a = new_head;
    }
    else
    {
        new_head = (*head_a)->p_next;
        (*head_a)->p_next = *head_b;
        *head_b = *head_a;
        *head_a = new_head;
    }
}

void ft_pa(t_node **head_a, t_node **head_b)
{
    t_node *new_head;

    if(!(*head_a))
        return ;
    if(!(*head_b))
    {
        new_head = (*head_a)->p_next;
        *head_b = *head_a;
        (*head_b)->p_next = NULL;
        *head_a = new_head;
    }
    else
    {
        new_head = (*head_a)->p_next;
        (*head_a)->p_next = *head_b;
        *head_b = *head_a;
        *head_a = new_head;
    }
}

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
