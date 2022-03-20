#include "push_swap.h"



static void turn_back(t_node **head_a, t_node **head_b)
{
	while((*head_b) != NULL)
		ft_pa(head_b, head_a);
}

void	push_low(t_node **head_a, t_node **head_b)
{
	int		tmp;
	int		counter;
	t_node	*mv;

	mv = (*head_a);
	tmp = mv->data;
	counter = ft_lstlen(head_a);
	while(counter)
	{
		if (tmp > mv->data)
			tmp = mv->data;
		mv = mv->p_next;
		counter--;
	}
	rotation(head_a, tmp);
	ft_pb(head_a, head_b);
}

int one_by_one_sort(t_node **head_a, t_node **head_b)
{
	int	counter;

	counter = ft_lstlen(head_a);
	while(counter-- > 0)
		push_low(head_a, head_b);
	turn_back(head_a, head_b);
	printer(head_a, head_b);
	return (0);
}