#include "push_swap.h"

t_node	*lower(t_node **head_a)
{
	t_node	*mv;
	t_node	*low;

	mv = (*head_a);
	low = (*head_a);
	while (mv != NULL)
	{
		if (low->data > mv->data)
			low = mv;
		mv = mv->p_next;
	}
	return (low);
}

static void	swap_data_to_act(t_node **head_a)
{
	t_node	*mv;
	int		tmp;

	mv = (*head_a);
	while (mv != NULL)
	{
		tmp = mv->data;
		mv->data = mv->act;
		mv->act = tmp;
		mv = mv->p_next;
	}
}

void	indexier(t_node **head_a)
{
	t_node	*mv;
	t_node	*m_mv;
	int		counter;

	mv = (*head_a);
	while (mv != NULL)
	{
		counter = 1;
		m_mv = (*head_a);
		while (m_mv != NULL)
		{
			if (mv->data > m_mv->data)
				counter++;
			m_mv = m_mv->p_next;
		}
		mv->act = counter;
		mv = mv->p_next;
	}
	swap_data_to_act(head_a);
}
