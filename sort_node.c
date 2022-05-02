#include "push_swap.h"

static void	rotate_me(t_node **head_a, t_node *put_before)
{
	int		counter;
	t_node	*mv;

	counter = 0;
	mv = (*head_a);
	while (mv->data != put_before->data)
	{
		counter++;
		mv = mv->p_next;
	}
	if (counter > ft_lstlen(head_a) / 2)
	{
		counter = ft_lstlen(head_a) - counter;
		while (counter--)
			ft_rra(head_a);
	}
	else
	{
		while (counter--)
			ft_ra(head_a);
	}
}

static t_node	*complex_check(t_node **head_a, t_node **head_b, t_node *lowest)
{
	t_node	*mv;

	while (lowest != NULL)
	{
		if (lowest->data > (*head_b)->data)
			return (lowest);
		lowest = lowest->p_next;
	}
	mv = (*head_a);
	while (mv != NULL)
	{
		if (mv->data > (*head_b)->data)
			return (mv);
		mv = mv->p_next;
	}
	return (NULL);
}

static t_node	*basic_check(t_node **head_a, t_node **head_b)
{
	t_node	*mv;

    mv = (*head_a);
	while (mv != NULL)
	{
		if (mv->data > (*head_b)->data)
			return (mv);
		mv = mv->p_next;
	}
	return (NULL);
}

void	sort_node(t_node**head_a, t_node **head_b)
{
	t_node	*put_before;
	t_node	*lowest;

	put_before = NULL;
	lowest = lower(head_a);
	if (lowest->data == (*head_a)->data)
		put_before = basic_check(head_a, head_b);
	else
		put_before = complex_check(head_a, head_b, lowest);
	if (put_before != NULL)
		rotate_me(head_a, put_before);
}
