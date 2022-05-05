#include "push_swap_bonus.h"

static int	linker(t_node **head_a, t_node **head_b, char *command)
{
	(void)head_b;
	if (ft_strncmp(command, "sa\n", 3) == 0)
		ft_sa(head_a);
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