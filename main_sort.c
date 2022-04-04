#include "push_swap.h"

int count_rotation_b(t_node **head, int data)
{
    t_node	*mv;
	int		tmp;

	tmp = 0;
    mv = (*head);
	while (mv != NULL && mv->data != data)
	{
		tmp++;
		mv = mv->p_next;
	}
	if (tmp > ft_lstlen(head) / 2)
		return (ft_lstlen(head) - tmp);
	else
		return (tmp);
}

static int count_rotation_a(t_node **head_a, int data) // head and data need to sort
{
	int		before_min;
	int		tmp;
	t_node *mv;

	mv = (*head_a);
	before_min = 0;
	tmp = 0;
	while (mv != NULL && mv->data != find_min(head_a))
	{
		before_min++;
		mv = mv->p_next;
	}
	if (before_min == 1)
	{
		while (mv->data < data)
		{
			tmp++;
			mv = mv->p_next;
		}
		if (tmp > ft_lstlen(head_a) / 2)
			return (ft_lstlen(head_a) - tmp);
		else
			return (tmp);
	}
	else
		return (complex_counter(head_a, data, before_min));
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

static void move_in_a(t_node **head_a)
{
    int     min;
    int     counter;
    t_node  *mv;

    min = find_min(head_a);
	mv = (*head_a)->p_next;
	if (min == (*head_a)->data)
		min = find_min(&mv);
	else
		mv = (*head_a);
    counter = 0;
    while (mv->data != min)
    {
        counter++;
        mv = mv->p_next;
    }
    if  (counter == 1)
        basic_rotater(head_a, (*head_a)->data);
    else
        complex_rotater(head_a, (*head_a)->data, min);
}

void main_sort(t_node **head_a, t_node **head_b)
{
    int	it;

	it = ft_lstlen(head_b);
    while(it--)
    {
		zero_act(head_a, head_b);
        count_act(head_a, head_b);
        chose_n_move(head_a, head_b);
        move_in_a(head_a);
    }
	it = count_rotation_b(head_a, find_min(head_a));
	if (it > ft_lstlen(head_a) / 2)
	{
		it = ft_lstlen(head_a) - it;
		while (it--)
			ft_ra(head_a);
	}
	else
	{
		while (it--)
			ft_rra(head_a);
	}
	printer(head_a, head_b);
}