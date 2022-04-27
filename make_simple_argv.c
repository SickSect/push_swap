#include "push_swap.h"

void base_copier(char *orig, char **main, int index)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(orig);
    main[index] = malloc(sizeof(char) * len);
    main[index][len] = '\0';
    while(orig[i])
    {
        main[index][i] = orig[i];
        i++;
    }
}

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

static void writer(char **argv, char **simple, int new_argc)
{
	char **splitted;
	int i;
	int j;
	int it_in;

	i = 1;
	j = 0;
	while(argv[i] && j < new_argc)
	{
		if (is_complex(argv[i]) == 0)
			base_copier(argv[i], simple, j++);
		else
		{
			splitted = ft_split(argv[i], ' ');
			it_in = 0;
			while (splitted[it_in])
			{
				base_copier(splitted[it_in], simple, j);
				j++;
				it_in++;
			}
			free(splitted);
		}
		i++;
	}
}

char **make_simple_argv(char **argv)
{
	int new_argc;
	char **new_argv;

	new_argc = count_complex_argv(argv);
	printf("ARG IS %d\n", new_argc);
	new_argv = malloc(sizeof(char*) * new_argc);
	printf("THERE IS %d\n", new_argc);
	sleep(1);
	writer(argv, new_argv, new_argc);
	return (new_argv);
}