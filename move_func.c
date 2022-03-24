#include "push_swap.h"

static void rotater_a(t_node **head, int counter)
{
    (void)head;
    (void)counter;   
    int ra;
    int rra;
    int tmp;

    ra = counter;
    rra = ft_lstlen(head) - counter;
    if (rra < ra)
    {
       
    }
    else
    {
        
    }
}

void sort_in_a(t_node **head)
{
    int counter;
    int data;
    t_node *mv;

    mv = (*head);
    data = mv->data;
    counter = 1;
    while (mv != NULL)
    {   
        if (data > mv->data)
            counter++;
        mv = mv->p_next;
    }
    if(ft_lstlen(head) - counter == 1)
    {
        ft_rra(head);
        ft_sa(head);
        ft_ra(head);
        ft_ra(head);
    }
    else
    {
        rotater_a(head, counter);
    }
}

int which_one(t_node **head, int tmp)
{
    t_node *mv;

    mv = (*head);
    while(mv != NULL)
    {
        if (tmp < mv->data)
            return (mv->act);
        mv = mv->p_next;
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


