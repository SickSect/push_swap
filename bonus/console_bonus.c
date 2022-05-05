#include "push_swap_bonus.h"

static int	linker(t_node **head_a, t_node **head_b, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		ft_sa(head_a);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		ft_sb(head_b);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ft_ss(head_a, head_b);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ft_ra(head_a);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		ft_rb(head_b);
	else if (ft_strcmp(command, "rr\n", 3) == 0)
		ft_rr(head_a, head_b);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		ft_rra(head_a);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		ft_rrb(head_b);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		ft_rrr(head_a, head_b);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		ft_pa(head_b, head_a);
	else if (ft_strcmp(command, "pb\n", 3) == 0)
		ft_pb(head_a, head_b);
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
			if (!is_sort(head_a) && (*head_b) == NULL)
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