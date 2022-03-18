#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_node
{
    int data;
    struct s_node *p_next;
}   t_node;

long long	ft_atoi(const char *str);
int		ft_isdigit(int ch);
t_node	*ft_lstnew(int content);
int		ft_lstlen(t_node **head);
void    ft_lstdel(t_node *del);
int     is_sort(t_node **head);
void	lst_connect(t_node **head_a, t_node **head_b);
t_node  *lstlast(t_node **head);
int     data_lstlast(t_node **head);
int     lst_checkfirst(t_node **head);
t_node	*lst_copier(t_node **head, t_node **copy);
void	ft_putstr(char *str);
void	ft_sa(t_node **head);
void	ft_sb(t_node **head);
void	ft_ss(t_node **head_a, t_node **head_b);
void	ft_pa(t_node **head_a, t_node **head_b);
void	ft_pb(t_node **head_a, t_node **head_b);
void	ft_ra(t_node **head_a);
void	ft_rb(t_node **head);
void	ft_rr(t_node **head_a, t_node **head_b);
void	ft_rra(t_node **head);
void	ft_rrb(t_node **head);
void	ft_rrr(t_node **head_a, t_node **head_b);
int     one_by_one_sort(t_node **head_a, t_node **head_b);
void	angle_sort(t_node **head_a, t_node **head_b);
int		check_argv(char **argv, int argc);
void	re_sort(t_node **head);
void printer(t_node **head_a, t_node **head_b);
#endif