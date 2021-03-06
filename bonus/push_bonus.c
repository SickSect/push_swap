#include "push_swap_bonus.h"

void	ft_pb(t_node **head_a, t_node **head_b)
{
	t_node	*new_head;

	if (!(*head_a))
		return ;
	if (!(*head_b))
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

void	ft_pa(t_node **head_a, t_node **head_b)
{
	t_node	*new_head;

	if (!(*head_a))
		return ;
	if (!(*head_b))
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
