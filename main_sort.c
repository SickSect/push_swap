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

static void move_in_a(t_node **head)
{
    int     min;
    int     counter;
    t_node  *mv;

    min = find_min(head);
    counter = 0;
    mv = (*head);
    while (mv->data != min)
    {
        counter++;
        mv = mv->p_next;
    }
    if  (counter == 1)
        basic_rotater(head, (*head)->data);
        //complex_rotater(head);
}

void main_sort(t_node **head_a, t_node **head_b)
{
    int it = 1;
    while(head_b != NULL && it--)
    {
		zero_act(head_a, head_b);
        count_act(head_a, head_b);
        chose_n_move(head_a, head_b);
        move_in_a(head_a);
    }
}