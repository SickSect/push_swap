#include "push_swap.h"

int count_complex_argv(char **argv)
{
    int counter;
	int i;
	int j;

	counter = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] != '\0' && argv[i][j] != ' ')
			{
				counter++;
				while (argv[i][j] != ' ' && argv[i][j] != '\0')
					j++;
			}
		}
		i++;
	}
	return (counter);
}

static int analize_argv(char *argv)
{
	int i;

	i = 0;
	while (argv[i++])
	{
		if (argv[i] == ' ')
			return (1);
	}
	return (0);
}

static void base_copier(char *argv, char **new_argv, int it)
{
	int len;
	int i;

	len = ft_strlen(argv);
	i = 0;
	new_argv[it] = malloc(sizeof(char) * len + 1);
	while (argv[i])
	{
		new_argv[it][i] = argv[i];
		i++;
	}
	new_argv[it][i] = '\0';
}

static int complex_copier(char *argv, char **new_argv, int it)
{
	char **splt;
	int amount_added;
	int j;
	int i;

	amount_added = 0;
	j = 0;
	splt = ft_split(argv, ' ');
	while (splt[amount_added])
		amount_added++;
	while (j < amount_added)
	{
		new_argv[it] = malloc(sizeof(char) * ft_strlen(splt[j]) + 1);
		i = 0;
		while (splt[j][i])
		{
			new_argv[it][i] = splt[j][i];
			i++;
		}
		new_argv[it][i] = '\0';
		it++;
		j++;
	}
	newargv_cleaner(splt);
	return (amount_added);
}

char **make_simple_argv(char **argv)
{
	int new_argc;
	char **new_argv;
	int	it;
	int len;

	it = 0;
	new_argc = count_complex_argv(argv) + 1;
	new_argv = malloc(sizeof(char*) * new_argc);
	len = ft_strlen(argv[0]);
	new_argv[0] = malloc(sizeof(char) * len + 1);
	while (it < len)
	{
		new_argv[0][it] = argv[0][it];
		it++;
	}
	new_argv[0][it] = '\0';
	it = 1;
	while (it < new_argc)
	{
		if (analize_argv(argv[it]) == 1)
			it += complex_copier(argv[it], new_argv, it) + 1;
		else
		{
			base_copier(argv[it], new_argv, it);
			it++;
		}
	}
	return (new_argv);
}