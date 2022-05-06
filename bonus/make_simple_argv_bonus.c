#include "push_swap_bonus.h"

static void	splt_sleaner(char **splt)
{
	int	space;
	int	i;

	space = 0;
	i = 0;
	while (splt[space])
		space++;
	while (i < space)
	{
		free(splt[i]);
		i++;
	}
	free(splt);
}

int	argc_counter(char **argv)
{
	int		argc;
	int		i;
	char	**splt;
	int		space;

	i = 0;
	argc = 0;
	space = 0;
	while (argv[i])
	{
		if (argv[i][0] != '\0')
		{
			splt = ft_split(argv[i], ' ');
			while (splt[space] != NULL)
				space++;
			argc += space;
			splt_sleaner(splt);
			space = 0;
		}
		i++;
	}
	return (argc);
}

static char	*copy(char *orig)
{
	int		i;
	int		brace;
	char	*copy;

	i = 0;
	brace = ft_strlen(orig);
	copy = malloc(sizeof(char) * ft_strlen(orig) + 1);
	while (i < brace)
	{
		copy[i] = orig[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	copier(char **new_argv, int it, char *str)
{
	int		old_it;
	int		i;
	char	**splt;
	int		space;

	splt = ft_split(str, ' ');
	space = 0;
	i = 0;
	old_it = it;
	while (splt[space])
		space++;
	if (space == 1)
	{
		new_argv[it] = copy(splt[0]);
		splt_sleaner(splt);
		return (1);
	}
	else
	{
		while (i < space)
			new_argv[it++] = copy(splt[i++]);
		splt_sleaner(splt);
		return (it - old_it);
	}
}

char	**make_simple_argv(char **argv)
{
	char	**new_argv;
	int		i;
	int		it;
	int		argc;

	i = 0;
	it = 0;
	argc = argc_counter(argv);
	new_argv = malloc(sizeof(char *) * argc);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			i++;
		if (argv[i][0] != '\0')
		{
			it += copier(new_argv, it, argv[i]);
		}
		i++;
	}
	return (new_argv);
}
