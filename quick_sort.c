#include "push_swap.h"

static void turn_back(t_node **head_a, t_node **head_b, int *op)
{
	while((*head_b) != NULL)
	{
		(*op)++;
		write(1, "pa\n", 3);
		ft_pa(head_b, head_a);
	}
}

static void	push_low(t_node **head_a, t_node **head_b, int *op)
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
	while((*head_a)->data != tmp)
	{
		write(1, "ra\n", 3);
		ft_ra(head_a);
		(*op)++;
	}
	(*op)++;
	write(1, "pb\n", 3);
	ft_pb(head_a, head_b);
}

int one_by_one_sort(t_node **head_a, t_node **head_b)
{
	int	counter;
	int	op;

	op = 0;
	counter = ft_lstlen(head_a);
	while(counter-- > 1)
		push_low(head_a, head_b, &op);
	turn_back(head_a, head_b, &op);
	return (op);
}