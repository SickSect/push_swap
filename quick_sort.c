#include "push_swap.h"

static void check_prepush(t_node **head_a, t_node **head_b)
{
    int flg;

    flg = 0;
    if ((*head_b)->data < (*head_b)->p_next->data)
        ft_sb(head_b);
    if ((*head_b)->data < (*head_b)->p_next->p_next->data)
    {
        ft_sb(head_b);
        ft_rb(head_b);
        ft_sb(head_b);
        ft_pa(head_b, head_a);
        ft_rrb(head_b);
        flg = 1;
    }
    if (flg == 0)
        ft_pa(head_b, head_a);
}

static int	parcer_med_b(t_node **head_a, t_node **head_b, int chunk, int med)
{
	int counter;
    int checker;

    checker = 0;
	counter = 0;
	while (chunk--)
	{
		if ((*head_b)->data > med)
        {
            check_prepush(head_a, head_b);
            checker++;
        }
		else
		{
			counter++;
			ft_rb(head_b);
		}
        check_on_next(head_a, checker);
	}
	return (counter);
}

static void	parcer_b_to_a(t_node **head_a, t_node **head_b, int chunk)
{
    int med;
    int counter;
    int new_chunk;

    if (chunk == 1)
        ft_pa(head_b, head_a);
    else if (chunk == 2)
    {
        if ((*head_b)->data < (*head_b)->p_next->data)
            ft_sb(head_b);
        ft_pa(head_b, head_a);
        ft_pa(head_b, head_a);
        //printer(head_a, head_b);
    }
    else if (chunk == 3)
    {
        if ((*head_b)->data > (*head_b)->p_next->data && (*head_b)->data > (*head_b)->p_next->p_next->data)
            ft_pa(head_b, head_a);
        else if ((*head_b)->p_next->data > (*head_b)->data && (*head_b)->p_next->data > (*head_b)->p_next->p_next->data)
        {
            ft_sb(head_b);
            ft_pa(head_b, head_a);
        }
        else if ((*head_b)->p_next->p_next->data > (*head_b)->data && (*head_b)->p_next->p_next->data > (*head_b)->p_next->data)
        {
            ft_rb(head_b);
            ft_sb(head_b);
            ft_pa(head_b, head_a);
            ft_rrb(head_b);
        }
    }
	else
    {
        med = find_median_chunk(head_b, chunk);
        //printf("parcer b to a CHUNK IS %d median is %d\n", chunk, med);
        counter = parcer_med_b(head_a, head_b, chunk, med);
        new_chunk = counter;
        if (ft_lstlen(head_b) != new_chunk)
        {
            while (counter--)
		        ft_rrb(head_b);
        }
        //printer(head_a, head_b);
        //sleep(2);
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

    if (ft_lstlen(head_a) != 2)
	    med = find_median(head_a);
    else
    {
        if ((*head_a)->data < (*head_a)->p_next->data)
            ft_sa(head_a);
        /*
        if ((*head_a)->data > (*head_a)->p_next->data)
            med = (*head_a)->data;
        else
            med = (*head_a)->p_next->data;
            */
    }
    if (ft_lstlen(head_a) > 2)
	    chunk = parcer_a_to_b(head_a, head_b, med);
    if (ft_lstlen(head_a) != 3)
        quick_sort(head_a, head_b);
    half_sort(head_a, 4);
    //printf("I know that chunk is %d\n", chunk);
    parcer_b_to_a(head_a, head_b, chunk);
    if (is_sort(head_a) == -1)
    {
        //printf("NOT FIN\n");
        //printer(head_a, head_b);
        //sleep(2);
        //amount_not_sorted(head_a, head_b);
        quick_sort(head_a, head_b);
        //sleep(2);
    }
    //printer(head_a, head_b);
}