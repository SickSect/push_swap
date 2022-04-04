#include "push_swap.h"

int complex_counter(t_node **head_a, int data, int before_min)
{
	t_node	*mv;
	int		search;

	mv = (*head_a);
	search = 0;
	while (before_min-- && mv != NULL)
		mv = mv->p_next;
	while (mv != NULL && mv->data < data)
		mv = mv->p_next;
	if (mv == NULL)
	{
		mv = (*head_a);
		while (mv != NULL && mv->data < data)
			mv = mv->p_next;
	}
	search = count_rotation_b(head_a, mv->data);
	if (search < ft_lstlen(head_a) / 2)
		return (search);
	else
		return (ft_lstlen(head_a) - search);
	return (0);
}

static void ft_rotation_at_b(t_node **head_b, int act)
{
	t_node	*mv;
	int		counter;

	mv = (*head_b);
	counter = 0;
	while (mv->act != act)
	{
		counter++;
		mv = mv->p_next;
	}
}

void    parsing_by_med(t_node **by_med, t_node **push_here)
{
    int max;
    int min;
    int med;

    max = find_max(by_med);
    min = find_min(by_med);
    med = find_median(by_med);
    while (ft_lstlen(by_med) != 3)
    {
        if ((*by_med)->data != max && (*by_med)->data != min && (*by_med)->data != med)
            ft_pb(by_med, push_here);
        ft_ra(by_med);
    }
}

void chose_n_move(t_node **head_a, t_node **head_b)
{
    t_node	*mv;
	int		act;

	mv = (*head_b);
	act = mv->act;
	while (mv != NULL)
	{
		if (act > mv->act)
			act = mv->act;
		mv = mv->p_next;
	}
	ft_rotation_at_b(head_b, act);
	ft_pa(head_b, head_a);
}

