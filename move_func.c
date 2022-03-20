#include "push_swap.h"

void rotation(t_node **head_a, int tmp)
{
	int counter;
	int	ra;
	int	rra;
	t_node *mv;

	counter = 0;
	mv = (*head_a);
	while(mv->data != tmp)
	{
		mv = mv->p_next;
		counter++;
	}
	rra = ft_lstlen(head_a) - counter;
	ra = counter;
	if(ra > rra)
	{
		while(rra--)
			ft_rra(head_a);
	}
	else
	{
		while(ra--)
			ft_ra(head_a);
	}
}

void    push_less_med(t_node **head_a, t_node **head_b, int med)
{
    int tmp;
    t_node *mv;


    while (find_min(head_b) < med)
    {
        tmp = find_min(head_b);
        mv = (*head_b);
        while (mv != NULL)
        {
            if (mv->data < med && mv->data > tmp)
                tmp = mv->data;
            mv = mv->p_next;
        }
        rotation(head_b, tmp);
        ft_pa(head_b, head_a);
    }
}

void    push_more_med(t_node **head_a, t_node **head_b)
{
    int tmp;

    while ((*head_b)!= NULL)
    {
        tmp = find_max(head_b);
        rotation(head_b, tmp);
        ft_pa(head_b, head_a);
    }
}

