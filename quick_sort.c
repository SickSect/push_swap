#include "push_swap.h"

static void	parse_list(t_node **head_a, t_node **head_b, int push, int mid)
{
		//printf("START PARS\n");
	while(push > 0)
	{
		if ((*head_a)->data < mid)
		{
				//printf("PUSH\n");
			ft_pb(head_a, head_b);
			ft_ra(head_a);
			push--;
		}
		else
		{
			ft_ra(head_a);
		}
	}
		//printf("FINISH PARS\n");
}



int quick_sort(t_node **head_a, t_node **head_b)
{
	(void)head_b;

	int tmp;
    int	op;
    int	len;
	int mid_data;
	t_node *mv;

    op = 0;
	len = ft_lstlen(head_a);
	len /= 2;
	tmp = len;
		//printf("LEN IS %d\n", len);
	mv = *head_a;
	while(len-- > 0)
		mv = mv->p_next;
	mid_data = mv->data;
	parse_list(head_a, head_b, tmp, mid_data);
	printer(head_a, head_b);
		//printf("MID IS %d\n", mid_data);
	return (op);
}