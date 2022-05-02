#include "push_swap.h"

static int	is_digits(char *str)
{
	int	i;
	//int	flg;

    i = 0;
	//flg = 1;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		else
			return (-1);
	}
    return (1);
}

static int	is_int(char *str)
{
	long long	num;

    num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	return (0);
}

int	check_doubles(t_node **head)
{
	int		counter;
	t_node	*mv;
	t_node	*m_mv;

	m_mv = (*head);
	while (m_mv != NULL)
	{
		counter = 0;
		mv = (*head);
		while (mv != NULL)
		{
			if (mv->data == m_mv->data)
				counter++;
			mv = mv->p_next;
		}
		if (counter != 1)
			return (-1);
		m_mv = m_mv->p_next;
	}
	return (0);
}

int	check_argv(char **argv, int argc)
{
	int	it;

	it = 1;
	if (argc == 2)
		return (-1);
	else if (argc > 3)
	{
		while (it < argc)
		{
			if (is_digits(argv[it]) == -1)
				return (-1);
			it++;
		}
		it = 1;
		while (it < argc)
		{
			if (is_int(argv[it]) == -1)
				return (-1);
			it++;
		}
	}
	return (0);
}
