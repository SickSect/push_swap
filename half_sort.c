#include "push_swap.h"

static void	three_arg(t_node **h)
{
	t_node	*l;

	l = lstlast(h);
	if (l->data < (*h)->data && l->data < (*h)->p_next->data)
	{
		if ((*h)->data > (*h)->p_next->data)
			ft_sa(h);
		ft_rra(h);
	}
	else if ((*h)->p_next->data < (*h)->data && (*h)->p_next->data < l->data)
	{
		if (l->data > (*h)->data)
			ft_sa(h);
		else
		{
			ft_rra(h);
			ft_rra(h);
		}
	}
	else if ((*h)->data < (*h)->p_next->data
		&& (*h)->data < l->data && (*h)->p_next->data > l->data)
	{
		ft_rra(h);
		ft_sa(h);
	}
}

void	half_sort(t_node **head, int argc)
{
	if (argc == 3)
	{
		if ((*head)->data > (*head)->p_next->data)
			ft_ra(head);
	}
	else if (argc == 4)
		three_arg(head);
}

int	add_memory(char **argv, t_node **a, int argc)
{
	int		i;
	t_node	*mv;
	
	i = 1;
	*a = malloc(sizeof(t_node));
	if (!a)
		return (-1);
	(*a)->data = ft_atoi(argv[i]);
	i += 1;
    mv = *a;
	while (i < argc)
	{
		mv->p_next = ft_lstnew(ft_atoi(argv[i++]));
		mv = mv->p_next;
	}
	return (0);
}
