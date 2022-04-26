#include "push_swap.h"

static int count_complex_argv(char **argv)
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
			while (argv[i][j] == ' ')
				j++;
			if (ft_isdigit(argv[i][j]))
				counter++;
			while(ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
	return (counter);
}

static int is_complex(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

static void writer(char **argv, int argc, char **simple)
{
	(void)argc;
	(void)simple;
	char **splitted;
	(void)splitted;
	int i;
	//int j;

	i = 1;
	while(argv[i])
	{
		printf("IT IS %d\n", is_complex(argv[i]));
		i++;
	}
}

char **make_simple_argv(char **argv)
{
	int new_argc;
	char **new_argv;
	(void)new_argv;
	(void)new_argc;

	new_argc = count_complex_argv(argv);
	printf("ARG IS %d\n", new_argc);
	new_argv = malloc(sizeof(char*) * new_argc);
	writer(argv, new_argc, new_argv);
	return (NULL);
}