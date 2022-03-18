#include "push_swap.h"

static int is_digits(char *str)
{
    int i;
	int flg;

    i = 0;
	flg = 1;
    while(flg == 1 && str[i])
    {
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			flg = 1;
		else
			flg = -1;
        i++;
    }
    return (flg);
}

static int is_int(char *str)
{
    long long num;

    num = ft_atoi(str);
    if (num > 2147483647 || num < -2147483648)
        return (-1);
    return (0);
}

int check_argv(char **argv, int argc)
{
    int		it;

    it = 1;
    if (argc < 2)
        return (-1);
    else if (argc >= 2)
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
        if(argc == 2)
            return (1);
    }
	return (0);
}