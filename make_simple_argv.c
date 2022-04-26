#include "push_swap.h"

static int count_complex_argv(char **argv, int argc)
{
    int new_argc;
    int	i;
    int	j;

    new_argc = argc;
	i = 0;
	j = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				new_argc++;
		}
		i++;
	}
	return (new_argc);
}

static void complex_writer(char **argv, int argc, int it, t_node **head_a)
{
	char **complex;

	complex = ft_split(argv[it], ' ');
}

static void write_complex_to_simple(char **argv, int argc, t_node **head_a)
{
	int	i;
	int	j;
	int flg;
	t_node *mv;

	j = 0;
	i = 1;
	flg = 0;
	mv = (*head_a);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if(argv[i][j] == ' ')
				flg = 1;
			j++;
		}
		if (flg == 1)
		{
			complex_writer(argv, argc, i, head_a);
		}
		else
		{
			mv = ft_lstnew(ft_atoi(argv[i]));
			mv = mv->p_next;
		}
		i++;
	}
}

void make_simple_argv(char **argv, int argc, t_node **a)
{
    // 1 45 "1 0 85 123" "1232"
    int		new_argc;
	int		it;

    new_argc = count_complex_argv(argv, argc);
	write_complex_to_simple(argv, new_argc, a);
}