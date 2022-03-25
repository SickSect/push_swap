#include "push_swap.h"

int find_ra(t_node **head)
{
	int min;
	t_node *mv;

	mv = (*head);
	min = mv->data;
	while (mv != NULL)
	{
		if (min < mv->data)
			min = mv->data;
		mv - mv->p_next;
	}
	mv  = (*head);
	while(mv->data != min)
		mv = mv->p_next;
}

void	ft_rra(t_node **head)
{
	t_node	*pre_last;
	t_node	*last;

	if((*head)->p_next == NULL || !(*head))
		return ;
	pre_last = *head;
	while(pre_last->p_next->p_next != NULL)
		pre_last = pre_last->p_next;
	last = pre_last->p_next;
	pre_last->p_next = NULL;
	last->p_next = *head;
	*head = last;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node **head)
{
	t_node	*pre_last;
	t_node	*last;

	if((*head)->p_next == NULL || !(*head))
		return ;
	pre_last = *head;
	while(pre_last->p_next->p_next != NULL)
		pre_last = pre_last->p_next;
	last = pre_last->p_next;
	pre_last->p_next = NULL;
	last->p_next = *head;
	*head = last;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **head_a, t_node **head_b)
{
	ft_rra(head_a);
	ft_rrb(head_b);
}