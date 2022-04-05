#include "push_swap.h"

static int median_chunk(t_node **head_b, int chunk, int shield)
{
	t_node	*mv;
	t_node	*m_mv;
	int		counter;

	mv = (*head_b);
	while(mv->data != shield && counter != chunk / 2)
	{
		m_mv = (*head_b);
		counter = 0;
		while (m_mv->data != shield && counter != chunk / 2)
		{
			if (m_mv->data < mv->data)
				counter++;
			m_mv = m_mv->p_next;
		}
		mv = mv->p_next;
	}
	m_mv = (*head_b);
	printf("MID IS %d\n", m_mv->data);
	return (m_mv->data);
}

int	find_median_chunk(t_node **head_b, int chunk)
{
    t_node	*mv;
    int		shield;
	int		counter;

    mv = (*head_b);
	counter = chunk;
    while (--counter)
        mv = mv->p_next;
    shield = mv->data;
	mv = (*head_b);
	return (median_chunk(head_b, chunk, shield));
}