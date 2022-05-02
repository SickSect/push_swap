#include "push_swap_bonus.h"

static void	ft_cleaner(t_node *head_a)
{
	t_node	*fr;

	fr = head_a->p_next;
	while (fr != NULL)
	{
		free(head_a);
		head_a = fr;
		fr = fr->p_next;
	}
	free(head_a);
}

static int	preview(char **argv, int argc)
{
	if (argc == 2 || argc == 1)
		return (-1);
	if (check_argv(argv, argc) == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}

static int after_preview(char **new_argv, int new_argc, t_node *a, t_node *b)
{
	if (check_doubles(&a) == -1)
	{
		ft_cleaner(a);
		ft_putstr("Error\n");
		return (-1);
	}
	newargv_cleaner(new_argv, new_argc);
	ft_cleaner(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	
	b = NULL;
	if (preview(argv, argc) == -1)
		return (-1);
	add_memory(argv, &a, argc);
	after_preview(argv, argc, a, b);
	return (0);
}