#include "push_swap.h"

void	newargv_cleaner(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

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

static int	after_preview(char **new_argv, int new_argc, t_node *a, t_node *b)
{
	if (check_doubles(&a) == -1)
	{
		ft_cleaner(a);
		newargv_cleaner(new_argv, new_argc);
		ft_putstr("Error\n");
		return (-1);
	}
	if (new_argc == 3 || new_argc == 4)
		half_sort(&a, new_argc);
	if (is_sort(&a) == -1)
		sort(&a, &b);
	newargv_cleaner(new_argv, new_argc);
	ft_cleaner(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**new_argv;
	int		new_argc;

	(void)argc;
	b = NULL;
	new_argv = make_simple_argv(argv);
	new_argc = argc_counter(argv);
	if (preview(new_argv, new_argc) == -1)
	{
		newargv_cleaner(new_argv, new_argc);
		return (-1);
	}
	add_memory(new_argv, &a, new_argc);
	after_preview(new_argv, new_argc, a, b);
	return (0);
}