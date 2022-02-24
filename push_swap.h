#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_node
{
    int data;
    struct s_node *p_next;
}   t_node;

int	ft_atoi(const char *str);

#endif