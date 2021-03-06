#include "push_swap_bonus.h"

int	ft_lstlen(t_node **head)
{
	t_node	*tmp;
	int		counter;

	counter = 1;
	tmp = *head;
	while (tmp->p_next)
	{
		tmp = tmp->p_next;
		counter++;
	}
	tmp = NULL;
	return (counter);
}

void	ft_ra(t_node **head)
{
	t_node	*last;
	t_node	*tmp;

	if ((*head)->p_next == NULL || !(*head))
		return ;
	last = *head;
	while (last->p_next != NULL )
		last = last->p_next;
	last->p_next = *head;
	tmp = *head;
	*head = (*head)->p_next;
	tmp->p_next = NULL;
}

void	ft_rb(t_node **head)
{
	t_node	*last;
	t_node	*tmp;

	if ((*head)->p_next == NULL || !(*head))
		return ;
	last = *head;
	while (last->p_next != NULL )
		last = last->p_next;
	last->p_next = *head;
	tmp = *head;
	*head = (*head)->p_next;
	tmp->p_next = NULL;
}

void	ft_rr(t_node **head_a, t_node **head_b)
{
	if ((*head_a) != NULL)
		ft_ra(head_a);
	if ((*head_b) != NULL)
		ft_rb(head_b);
}
