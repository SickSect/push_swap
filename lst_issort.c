#include "push_swap.h"

int	is_sort(t_node **head)
{
	t_node *tmp;

	tmp = *head;
	while(tmp->p_next != NULL)
	{
		if (tmp->data > tmp->p_next->data)
			return (-1);
		tmp = tmp->p_next;
	}
	return (0);
}