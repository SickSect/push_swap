#include "push_swap.h"

void pre_check(t_node **head_a, t_node **head_b)
{
	(void)head_b;
	t_node	*mv;
	int		last_data;
	int		count;
	int		fin_count;
	int min_fin_count;
	
	last_data = (*head_a)->data;
	mv = (*head_a)->p_next;
	count = 0;
	fin_count = 0;
	while (mv != NULL)
	{
		if (mv->data > last_data)
			count++;
		else
		{
			if (fin_count < count)
				fin_count = count;
			count = 0;
		}
		last_data = mv->data;
		mv = mv->p_next;
	}

	last_data = (*head_a)->data;
	mv = (*head_a)->p_next;
	count = 0;
	min_fin_count = 0;
	while (mv != NULL)
	{
		if (mv->data < last_data)
			count++;
		else
		{
			if (min_fin_count < count)
				min_fin_count = count;
			count = 0;
		}
		last_data = mv->data;
		mv = mv->p_next;
	}
	printf(" THERE IS %d ELEMENTS IS SORTED and %d reverse\n", fin_count, min_fin_count);
}