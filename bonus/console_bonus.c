#include "push_swap_bonus.h"

static void	cut_linker(t_node **head_a, t_node **head_b, char *command)
{
	if (cmp(command, "pa\n", 3) == 0
		&& (*head_a) != NULL && (*head_b) != NULL)
		ft_pa(head_b, head_a);
	else if (cmp(command, "pb\n", 3) == 0
		&& (*head_a) != NULL && (*head_b) != NULL)
		ft_pb(head_a, head_b);
	else if (cmp(command, "rra\n", 4) == 0 && (*head_a) != NULL)
		ft_rra(head_a);
	else if (cmp(command, "rrb\n", 4) == 0 && (*head_b) != NULL)
		ft_rrb(head_b);
	else if (cmp(command, "rrr\n", 4) == 0)
		ft_rrr(head_a, head_b);
}

static int	linker(t_node **head_a, t_node **head_b, char *command)
{
	if (cmp(command, "sa\n", 3) == 0 && (*head_a) != NULL)
		ft_sa(head_a);
	else if (cmp(command, "sb\n", 3) == 0 && (*head_b) != NULL)
		ft_sb(head_b);
	else if (cmp(command, "ss\n", 3) == 0
		&& (*head_a) != NULL && (*head_b) != NULL)
		ft_ss(head_a, head_b);
	else if (cmp(command, "ra\n", 3) == 0 && (*head_a) != NULL)
		ft_ra(head_a);
	else if (cmp(command, "rb\n", 3) == 0 && (*head_b) != NULL)
		ft_rb(head_b);
	else if (cmp(command, "rr\n", 3) == 0
		&& (*head_a) != NULL && (*head_b) != NULL)
		ft_rr(head_a, head_b);
	else if (cmp(command, "pa\n", 3) == 0 || cmp(command, "pb\n", 3) == 0
		|| cmp(command, "rra\n", 4) == 0 || cmp(command, "rrb\n", 4) == 0
		|| cmp(command, "rrr\n", 4) == 0)
		cut_linker(head_a, head_b, command);
	else
		return (0);
	return (1);
}

void	console(t_node **head_a, t_node **head_b)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
		{
			if (is_sort(head_a) == 0 && (*head_b) == NULL)
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
			break ;
		}	
		if (!linker(head_a, head_b, command))
		{
			ft_putstr("Error\n");
			free(command);
			return ;
		}
		free(command);
	}
}