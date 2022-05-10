#include "push_swap_bonus.h"

int	add_memory(char **argv, t_node **a, int argc)
{
	int		i;
	t_node	*mv;

	i = 1;
	*a = malloc(sizeof(t_node));
	if (!a)
		return (-1);
	mv = (*a);
	mv->data = ft_atoi(argv[i]);
	i++;
	while (i < argc)
	{
		mv->p_next = ft_lstnew(ft_atoi(argv[i++]));
		mv = mv->p_next;
	}
	return (0);
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

static int	after_preview(char **argv, int argc, t_node *a)
{
	if (check_doubles(&a) == -1)
	{
		ft_cleaner(a);
		newargv_cleaner(argv, argc);
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**new_argv;
	int		new_argc;

	b = NULL;
	new_argv = make_simple_argv(argv);
	new_argc = argc_counter(argv);
	if (preview(new_argv, new_argc) == -1)
	{
		newargv_cleaner(new_argv, new_argc);
		return (-1);
	}
	add_memory(argv, &a, argc);
	if (after_preview(new_argv, new_argc, a) == -1)
		return (-1);
	console(&a, &b);
	newargv_cleaner(new_argv, new_argc);
	ft_cleaner(a);
	free(b);
	return (0);
}
