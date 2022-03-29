#include "push_swap.h"


static t_node *best_way(t_node **head)
{
	t_node *mv;
	t_node *ret;

	mv = (*head);
	ret = (*head);
	while (mv != NULL)
	{
		if (mv->act > ret->act)
			ret = mv;
		mv = mv->p_next;
	}
	return (ret);
}
static int better_way(t_node **head)
{
	t_node *mv;
	int	last;
	int counter;

	mv = (*head)->p_next;
	last = (*head)->data;
	counter = 1;
	while (mv != NULL)
	{
		if (mv->data > last)
		{
			counter++;
			last = mv->data;
		}
		mv = mv->p_next;
	}
	return (counter);
}

t_node *pre_check(t_node **head_a)
{
	t_node *mv;
	t_node *best;

	mv = lstlast(head_a);
	if ((*head_a)->data > (*head_a)->p_next->data)
		ft_sa(head_a);
	if ((*head_a)->data > mv->data)
		ft_rra(head_a);
	mv = (*head_a);
	while (mv != NULL)
	{
		mv->act = better_way(&mv);
		mv = mv->p_next;
	}
	best = best_way(head_a);
	return (best);
}

void smart_parcing (t_node **head_a, t_node **head_b, t_node *start)
{
	
}