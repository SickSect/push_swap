#include "push_swap.h"

void check_on_next(t_node **head_a, int counter)
{
	if (counter == 2)
	{
		if ((*head_a)->data > (*head_a)->p_next->data)
            ft_sa(head_a);
	}
	else if (counter == 3)
	{
		if ((*head_a)->data > (*head_a)->p_next->data)
            ft_sa(head_a);
		if ((*head_a)->p_next->data > (*head_a)->p_next->p_next->data)
		{
			ft_ra(head_a);
			ft_sa(head_a);
			ft_rra(head_a);
		}
	}
	else if (counter > 4)
	{
		if ((*head_a)->data > (*head_a)->p_next->data)
            ft_sa(head_a);
		if ((*head_a)->p_next->data > (*head_a)->p_next->p_next->data)
		{
			ft_ra(head_a);
			ft_sa(head_a);
			ft_rra(head_a);
		}
		if ((*head_a)->p_next->p_next->data >(*head_a)->p_next->p_next->p_next->data)
		{
			ft_ra(head_a);
			ft_ra(head_a);
			ft_sa(head_a);
			ft_rra(head_a);
			ft_rra(head_a);
		}
	}
}

void amount_not_sorted(t_node **head_a, t_node **head_b)
{
	(void)head_a;
	(void)head_b;
	t_node *mv;
	int counter;

	mv = (*head_a);
	counter = 0;
	while (mv->p_next!= NULL)
	{
		if (mv->data > mv->p_next->data)
		{
			counter++;
		}
		mv = mv->p_next;
	}
	//printf("Not sorted elements is %d\n", counter);
}

static int median_chunk(t_node **head_b, int chunk, int shield)
{
	t_node	*mv;
	t_node	*m_mv;
	int		counter;

	mv = (*head_b);
	while(mv->data != shield)
	{
		m_mv = (*head_b);
		counter = 0;
		while (m_mv->data != shield)
		{
			if (m_mv->data < mv->data)
				counter++;
			m_mv = m_mv->p_next;
		}
		if (counter == chunk / 2)
			return (mv->data);
		mv = mv->p_next;
	}
	return (0);
}

int	find_median_chunk(t_node **head_b, int chunk)
{
    t_node	*mv;
    int		shield;
	int		counter;

    mv = (*head_b);
	counter = chunk;
    while (--counter != 0)
		mv = mv->p_next;
	if (mv->p_next == NULL)
		return (find_median(head_b));
	shield = mv->p_next->data;
	mv = (*head_b);
	return (median_chunk(head_b, chunk, shield));
}

int	find_amount(t_node **head)
{
	int len;

	len = ft_lstlen(head);
	if (len % 2 == 0 && len != 2)
		return (len / 2 - 1);
	else if (len == 2)
		return (1);
	else
		return (len / 2);

}