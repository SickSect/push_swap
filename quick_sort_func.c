#include "push_swap.h"

static void correct_pos(t_node **head_a, int chunk)
{
	int data;
	t_node *mv;
	int	counter;
	int tmp;

	counter = 0;
	if (is_sort(head_a) == -1)
	{
		data = (*head_a)->data;
		mv = (*head_a)->p_next;
		while (mv->data < data && chunk--)
		{
			counter++;
			mv = mv->p_next;
		}
		tmp = counter;
		//printf("COUNTER IS %d\n", counter);
		if (counter == 1)
			ft_sa(head_a);
		else
		{
			while (tmp--)
			{
				ft_sa(head_a);
				ft_ra(head_a);
			}
			while(counter--)
				ft_rra(head_a);
		}
	}
}

void check_on_next(t_node **head_a, int counter)
{
	(void)counter;
	correct_pos(head_a, counter);
	/*
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
	else if (counter >= 4)
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
	*/
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