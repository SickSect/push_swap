#include "push_swap.h"

int which_one(t_node **head, int tmp)
{
    t_node *mv;
    mv = (*head);
    while(mv != NULL)
    {

    }
	return (0);
}

int where(t_node **head, int num)
{
    (void)head;
    (void)num;
    t_node *mv;
   
    mv = (*head);
    while (mv != NULL)
    {
        mv->act = rotation(head, mv->data);
        mv = mv->p_next;
    }
    return (0);
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


