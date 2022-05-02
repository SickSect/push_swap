#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				act;
	int				data;
	struct s_node	*p_next;
}	t_node;

int			check_doubles(t_node **head);
long long	ft_atoi(const char *str);
int			ft_isdigit(int ch);
t_node		*ft_lstnew(int content);
int			is_sort(t_node **head);
t_node		*lstlast(t_node **head);
int			ft_lstlen(t_node **head);
void		ft_putstr(char *str);
void		ft_sa(t_node **head);
void		ft_sb(t_node **head);
void		ft_ss(t_node **head_a, t_node **head_b);
void		ft_pa(t_node **head_a, t_node **head_b);
void		ft_pb(t_node **head_a, t_node **head_b);
void		ft_ra(t_node **head_a);
void		ft_rb(t_node **head);
void		ft_rr(t_node **head_a, t_node **head_b);
void		ft_rra(t_node **head);
void		ft_rrb(t_node **head);
void		ft_rrr(t_node **head_a, t_node **head_b);
int			check_argv(char **argv, int argc);
t_node		*lower(t_node **head_a);
int			add_memory(char **argv, t_node **a, int argc);
char		*get_next_line(int fd);
#endif