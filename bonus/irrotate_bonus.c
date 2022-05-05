#include "push_swap_bonus.h"

void	ft_rra(t_node **head)
{
	t_node	*pre_last;
	t_node	*last;

	if ((*head)->p_next == NULL || !(*head))
		return ;
	pre_last = *head;
	while (pre_last->p_next->p_next != NULL)
		pre_last = pre_last->p_next;
	last = pre_last->p_next;
	pre_last->p_next = NULL;
	last->p_next = *head;
	*head = last;
}

void	ft_rrb(t_node **head)
{
	t_node	*pre_last;
	t_node	*last;

	if ((*head)->p_next == NULL || !(*head))
		return ;
	pre_last = *head;
	while (pre_last->p_next->p_next != NULL)
		pre_last = pre_last->p_next;
	last = pre_last->p_next;
	pre_last->p_next = NULL;
	last->p_next = *head;
	*head = last;
}

void	ft_rrr(t_node **head_a, t_node **head_b)
{
	if ((*head_a) != NULL)
		ft_rra(head_a);
	if ((*head_b) != NULL)
		ft_rrb(head_b);
}
