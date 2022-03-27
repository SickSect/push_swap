#include "push_swap.h"

static void rotater_a(t_node **head)
{  
    int ra;
    int rra;

    ra = find_ra(head);
    rra = ft_lstlen(head) - ra;
	printf("RA %d RRA %d\n",ra, rra);
    if (rra < ra)
    {
       while (rra--)
	   {
		   ft_rra(head);
		   ft_sa(head);
	   }
    }
    else
    {
        if (ra == 0)
            ft_sa(head);
        while(ra--)
		{
			ft_sa(head);
			ft_ra(head);
		}
        
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
    else if (counter == 2)
    {
        ft_sa(head);
    }
    else
    {
        rotater_a(head);
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


