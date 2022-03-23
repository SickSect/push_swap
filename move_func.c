#include "push_swap.h"

int which_one(t_node **head_a, t_node **head_b, int *arr_act)
{
	
	return (0);
}

int where(t_node **head, int num)
{
    t_node *mv;
    int counter;
    int a_counter;

    counter = 0;
    mv = (*head);
    while(mv != NULL)
    {
        if (mv->data < num)
        {
            counter++;
            mv = mv->p_next;
        }
        else if (mv->data > num)
            mv = NULL;
    }
    a_counter = (ft_lstlen(head) + 1) - counter;
    if (a_counter > counter)
        return (counter);
    else
        return (a_counter);
}

int	rotation(t_node **head_a, int tmp)
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
		return (rra);
	else
		return (ra);
}


