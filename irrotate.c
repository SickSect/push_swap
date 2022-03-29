#include "push_swap.h"
static int before_minimum(t_node *min)
{
	int res;

	res = 0;
	while (min != NULL)
	{
		min = min->p_next;
		res++;
	}
	return (res);
}

int find_ra(t_node **head)
{
	t_node *mv;
	int res;
	int min;
	int before_min;

	mv = (*head);
	res = 0;
	min = find_min(head);
	while (mv->data != min)
		mv = mv->p_next;
	before_min = ft_lstlen(head) - before_minimum(mv);
	if (before_min == 1)
	{
		while ((*head)->data > mv->data)
		{
			res++;
			mv = mv->p_next;
		}
	}
	else
	{
		while (mv != NULL)
		{
			if (mv->data > min && mv->data < (*head)->data)
				res = mv->data;
			mv = mv ->p_next;
		}
		mv = (*head)->p_next;
		while (mv->data != min)
		{
			if (mv->data > min && mv->data < (*head)->data)
				res = mv->data;
			mv = mv ->p_next;
		}
		min = 0;
		mv = (*head)->p_next;
		while (mv->data != res)
		{
			min++;
			mv = mv->p_next;
		}
		return (min);
	}
	return (res);
}

void	ft_rra(t_node **head)
{
	t_node	*pre_last;
	t_node	*last;

	if((*head)->p_next == NULL || !(*head))
		return ;
	pre_last = *head;
	while(pre_last->p_next->p_next != NULL)
		pre_last = pre_last->p_next;
	last = pre_last->p_next;
	pre_last->p_next = NULL;
	last->p_next = *head;
	*head = last;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node **head)
{
	t_node	*pre_last;
	t_node	*last;

	if((*head)->p_next == NULL || !(*head))
		return ;
	pre_last = *head;
	while(pre_last->p_next->p_next != NULL)
		pre_last = pre_last->p_next;
	last = pre_last->p_next;
	pre_last->p_next = NULL;
	last->p_next = *head;
	*head = last;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **head_a, t_node **head_b)
{
	ft_rra(head_a);
	ft_rrb(head_b);
}