#include "push_swap.h"

static void	sort_b(t_node **head)
{
	t_node *last;

	while(is_sort(head) == -1)
	{
		last = lstlast(head);
		if (((last->data > (*head)->p_next->data)) && (*head)->data > (*head)->p_next->data)
			ft_rb(head);
		else if (((last->data <= (*head)->p_next->data)) && (*head)->data > (*head)->p_next->data)
			ft_sb(head);
		else
			ft_rb(head);
	}
}

static void	sort_a(t_node **head)
{
	t_node *last;

	while(is_sort(head) == -1)
	{
		last = lstlast(head);
		if (((last->data > (*head)->p_next->data)) && (*head)->data > (*head)->p_next->data)
			ft_ra(head);
		else if (((last->data <= (*head)->p_next->data)) && (*head)->data > (*head)->p_next->data)
			ft_sa(head);
		else
			ft_ra(head);
	}
}

static void	parse_list(t_node **head_a, t_node **head_b, int push, int mid)
{
	while(push > 0)
	{
		if ((*head_a)->data < mid)
		{
			ft_pb(head_a, head_b);
			write(1, &"pb\n", 3);
			push--;
		}
		else
		{
			write(1, &"rb\n", 3);
			ft_ra(head_a);
		}
	}
}

static void half_sort(t_node **head_a, t_node **head_b)
{
	if(is_sort(head_a) == -1)
		sort_a(head_a);
	if(is_sort(head_b) == -1)
		sort_b(head_b);

}

int quick_sort(t_node **head_a, t_node **head_b)
{
	int tmp;
    int	op;
    int	len;
	int mid_data;
	t_node *mv;

    op = 0;
	len = ft_lstlen(head_a);
	len /= 2;
	tmp = len;
	mv = *head_a;
	while(len-- > 0)
		mv = mv->p_next;
	mid_data = mv->data;
	parse_list(head_a, head_b, tmp, mid_data);
	half_sort(head_a, head_b);
	lst_connect(head_a, head_b);
	return (op);
}