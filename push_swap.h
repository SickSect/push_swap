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

int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
t_node	*ft_lstnew(int content);
int		ft_lstlen(t_node **head);
void    ft_lstdel(t_node *del);
void	ft_sa(t_node **head);
void	ft_sb(t_node **head);
void	ft_ss(t_node **head_a, t_node **head_b);
void	ft_pa(t_node **head_a, t_node **head_b); // WARNING
void	ft_pb(t_node **head_a, t_node **head_b); // WARNING
void	ft_ra(t_node **head_a);
void	ft_rb(t_node **head);
void	ft_rr(t_node **head_a, t_node **head_b);
void	ft_rra(t_node **head);
void	ft_rrb(t_node **head);
void	ft_rrr(t_node **head_a, t_node **head_b);

#endif