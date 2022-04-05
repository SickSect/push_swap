#include "push_swap.h"

static int median_chunk(t_node *head_b, int chunk, int counter, int shield)
{
	while (counter != chunk / 2)
	{
		data = mv->data;
		m_mv = (*head_b);
		counter = 0;
		while (m_mv->data != shield)
		{
			if (m_mv->data < data)
				counter++;
			m_mv = m_mv->p_next;
		}
		mv = mv->p_next;
	}
	return (mv->data);
}

int	find_median_chunk(t_node **head_b, int chunk)
{
    t_node	*mv;
	t_node	*m_mv;
    int		shield;
	int		counter;
	int		data;

    mv = (*head_b);
	counter = chunk;
    while (--chunk)
        mv = mv->p_next;
	chunk = counter;
    shield = mv->data;
	mv = (*head_b);
	
}