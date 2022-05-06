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
int			cmp(const char *str1, const char *str2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_newline(const char *str);
size_t		ft_strlen(char *str);
int			check_argv(char **argv, int argc);
int			check_doubles(t_node **head);
void		ft_putstr(char *str);
long long	ft_atoi(const char *str);
t_node		*ft_lstnew(int content);
int			is_sort(t_node **head);
int			ft_isdigit(int ch);
void		console(t_node **head_a, t_node **head_b);
char		**make_simple_argv(char **argv);
int			argc_counter(char **argv);
void		newargv_cleaner(char **argv, int argc);
char		**ft_split(char const *s, char c);
#endif