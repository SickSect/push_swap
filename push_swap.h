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
int	ft_isdigit(int ch);
t_node	*ft_lstnew(int content);
struct s_node *f_sa(t_node *head, t_node *next);
struct s_node *f_sb(t_node *head, t_node *next);
void f_ss(t_node *head_a, t_node *head_b);
void f_pb(t_node *head_a, t_node *head_b);

#endif