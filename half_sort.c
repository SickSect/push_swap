#include "push_swap.h"

static void three_arg(t_node **head)
{
	t_node *last;

	last = lstlast(head);
	if (last->data < (*head)->data && last->data < (*head)->p_next->data)		
	{
		if ((*head)->data > (*head)->p_next->data)
			ft_sa(head);
		ft_ra(head);
	}
	else if ((*head)->p_next->data < (*head)->data && (*head)->p_next->data < last->data)
	{
		if (last->data > (*head)->data)
			ft_sa(head);
		else
		{
			ft_rra(head);
			ft_rra(head);
		}
	}
	else if ((*head)->data < (*head)->p_next->data && (*head)->data < last->data && (*head)->p_next->data > last->data)
	{
		ft_rra(head);
		ft_sa(head);
	}
}

void	half_sort(t_node **head, int argc)
{
	if (argc == 3)
	{
		if ((*head)->data > (*head)->p_next->data)
			ft_ra(head);
	}
	else if (argc == 4)
		three_arg(head);
	
}