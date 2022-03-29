#include "push_swap.h"

/*
static int up_count(t_node **head_a)
{
	t_node	*mv;
	int		last_data;
	int		count;

	last_data = (*head_a)->data;
	mv = (*head_a)->p_next;
	count = 0;
	while (mv != NULL)
	{
		if (mv->data > last_data)
			count++;
		last_data = mv->data;
		mv = mv->p_next;
	}
	return (count);
}

static int dw_count(t_node **head_a)
{
	t_node	*mv;
	int		last_data;
	int		count;

	last_data = (*head_a)->data;
	mv = (*head_a)->p_next;
	count = 0;
	while (mv != NULL)
	{
		if (mv->data < last_data)
			count++;
		last_data = mv->data;
		mv = mv->p_next;
	}
	return (count);
}
*/

static void up_cut(t_node **head_a, t_node **head_b)
{
	printf("UP\n");
	int cycle;
	int last_data;

	cycle = ft_lstlen(head_a);
	last_data = (*head_a)->data;
	while(cycle--)
	{
		if (last_data < (*head_a)->p_next->data)
		{
			ft_ra(head_a);
			last_data = (*head_a)->data;
		}
		else
		{
			ft_sa(head_a);
			ft_pb(head_a, head_b);
		}
	}
	ft_ra(head_a);
}

void pre_check(t_node **head_a, t_node **head_b)
{
	up_cut(head_a, head_b);
	printer(head_a, head_b);
}