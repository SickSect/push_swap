#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_node
{
    int length;
    int data;
    struct s_node *p_next;
}   t_node;

int	ft_atoi(const char *str);
int	ft_isdigit(int ch);
t_node	*ft_lstnew(int content);
void f_sa(t_node *head, t_node *next);


#endif