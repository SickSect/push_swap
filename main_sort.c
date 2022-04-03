#include "push_swap.h"

static int count_rotation_a(t_node **head_a, int data)
{
    t_node	*mv;
    int		mid;
    int		counter;

	counter = 0;
	mid = ft_lstlen(head_a) / 2;
	mv = (*head_a);
	while (mv != NULL && mv->data < data)
	{
		counter++;
		mv = mv->p_next;
	}
	if (counter < mid)
        return (counter);
    else
        return (ft_lstlen(head_a) - counter);
}

static int count_rotation_b(t_node **head, int data)
{
    t_node  *mv;
    int     mid;
    int     counter;

    mid = ft_lstlen(head) / 2;
    counter = 0;
	mv = (*head);
    while (mv != NULL && mv->data != data)
    {
        counter++;
        mv = mv->p_next;
    }
    if (counter < mid)
        return (counter);
    else
        return (ft_lstlen(head) - counter);
}

static void count_act(t_node **head_a, t_node **head_b)
{
    t_node *mv;
    
    mv = (*head_b);
    while (mv != NULL)
    {
        mv->act = count_rotation_b(head_b, mv->data);
        mv->act += count_rotation_a(head_a, mv->data);
        mv = mv->p_next;
    }
}

void main_sort(t_node **head_a, t_node **head_b)
{
    int it = 1;
    while(head_b != NULL && it--)
    {
		zero_act(head_a, head_b);
        count_act(head_a, head_b);
        chose_n_move(head_a, head_b);
    }
}