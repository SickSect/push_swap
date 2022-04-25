#include "push_swap.h"

int	parcer_med_b(t_node **head_a, t_node **head_b, int chunk, int med)
{
	int counter;
    int checker;

    checker = 0;
	counter = 0;
	while (chunk--)
	{
		if ((*head_b)->data > med)
        {
            if ((*head_b)->data < (*head_b)->p_next->data && (*head_b)->p_next->data > med)
                ft_sb(head_b);
            sort_node(head_a, head_b);
            ft_pa(head_b, head_a);
            checker++;
        }
		else
		{
			counter++;
			ft_rb(head_b);
		}
	}
	return (counter);
}

static int complex_chunk(t_node **head_a, t_node **head_b, int chunk)
{
    int med;
    int counter;
    int new_chunk;

    med = find_median_chunk(head_b, chunk);
    counter = parcer_med_b(head_a, head_b, chunk, med);
    new_chunk = counter;
    if (ft_lstlen(head_b) != new_chunk)
    {
		while(counter--)
			ft_rrb(head_b);
    }
    return (new_chunk);
}

static void	parcer_b_to_a(t_node **head_a, t_node **head_b, int chunk)
{
    int new_chunk;

    if (chunk == 1)
    {
        ft_pa(head_b, head_a);
    }
    else if (chunk == 2)
    {
        if ((*head_b)->data < (*head_b)->p_next->data)
            ft_sb(head_b);
        ft_pa(head_b, head_a);
        ft_pa(head_b, head_a);
    }
	else
    {
        new_chunk = complex_chunk(head_a, head_b, chunk);
        parcer_b_to_a(head_a, head_b, new_chunk);
    }
}

static int	parcer_a_to_b(t_node **head_a, t_node **head_b, int med)
{
    int it;
    int counter;

    counter = 0;
    it = find_amount(head_a);
    while (it != 0)
    {
        if ((*head_a)->data < med)
        {
            --it;
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

    if (ft_lstlen(head_a) > 3)
	    med = find_median(head_a);
    if (ft_lstlen(head_a) > 3)
	    chunk = parcer_a_to_b(head_a, head_b, med);
    if (ft_lstlen(head_a) > 3)
        quick_sort(head_a, head_b);
    else
        half_sort(head_a, ft_lstlen(head_a) + 1);
    parcer_b_to_a(head_a, head_b, chunk);
}   