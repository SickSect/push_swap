#include "push_swap.h"

static void	parcer_med_b(t_node **head_a, t_node **head_b, int chunk)
{
	(void)head_a;
    int med;
	int counter;

    med = find_median_chunk(head_b, chunk);
	counter = 0;
	printf("med is %d ", med);
	while (chunk--)
	{
		if ((*head_b)->data > med)
			ft_pa(head_b, head_a);
		else
		{
			counter++;
			ft_rb(head_b);
		}
	}
	while (counter--)
	{
		ft_rrb(head_b);
		ft_pa(head_b, head_a);
	}
}

static void	parcer_b_to_a(t_node **head_a, t_node **head_b, int chunk)
{
    (void)head_a;
    (void)head_b;
    if (chunk == 1)
        ft_pa(head_b, head_a);
	else
		parcer_med_b(head_a, head_b, chunk);
	printf("  CHUNK IS %d\n", chunk);
}

static int	parcer_a_to_b(t_node **head_a, t_node **head_b, int med)
{
    int it;
    int counter;

    counter = 0;
    it = ft_lstlen(head_a) / 2;
    while (it)
    {
        if ((*head_a)->data < med)
        {
            it--;
            ft_pb(head_a, head_b);
            counter++;
        }
	    else
		    ft_ra(head_a);
    }
    return (counter);
}

void	quick_sort(t_node **head_a, t_node **head_b)
{
	int	med;
    int chunk;

    if (ft_lstlen(head_a) != 2)
	    med = find_median(head_a);
    else
    {
        if ((*head_a)->data > (*head_a)->p_next->data)
            med = (*head_a)->data;
        else
            med = (*head_a)->p_next->data;
    }
	chunk = parcer_a_to_b(head_a, head_b, med);
    //printf("CHUNK IS %d\n", chunk);
    if (ft_lstlen(head_a) != 1)
        quick_sort(head_a, head_b);
    parcer_b_to_a(head_a, head_b, chunk);
    printer(head_a, head_b);
}