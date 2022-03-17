#include "push_swap.h"

static void parser(t_node **head_a, t_node **head_b)
{
    int counter;

    counter = ft_lstlen(head_a);
    counter /= 2;
    while(counter)
    {
        ft_pb(head_a, head_b);
        counter--;
    }
}

static void	push_low(t_node **head_a, t_node **head_b, int *op)
{
	int		tmp;
	int		counter;
	t_node	*mv;

	mv = (*head_a);
	tmp = mv->data;
	counter = ft_lstlen(head_a);
	while(counter)
	{
		if (tmp > mv->data)
			tmp = mv->data;
		mv = mv->p_next;
		counter--;
	}
	while((*head_a)->data != tmp)
	{
		write(1, "ra\n", 3);
		ft_ra(head_a);
		(*op)++;
	}
	(*op)++;
	write(1, "pb\n", 3);
	ft_pb(head_a, head_b);
}

int half_sort(t_node **head_a, t_node **head_b)
{
    int op;
    int len_a;
    int len_b;

    op = 0;
    parser(head_a, head_b);
    len_a = ft_lstlen(head_a);
    len_b = ft_lstlen(head_b);
	while(len_a-- > 0)
		push_low(head_a, head_b, &op);
    printer(head_a, head_b);
    return (op);
}