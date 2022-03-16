#include "push_swap.h"

void	lst_connect(t_node **head_a, t_node **head_b)
{
    int	counter;

    counter = ft_lstlen(head_b);
	printer(head_a, head_b);
    while(counter != 0)
    {
		ft_pa(head_b, head_a);
		counter--;
    }
	printer(head_a, head_b);
}