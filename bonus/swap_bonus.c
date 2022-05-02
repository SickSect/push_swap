#include "push_swap_bonus.h"

void	ft_sa(t_node **head)
{
	t_node	*next;

	if (*head == NULL || (*head)->p_next == NULL )
		return ;
	next = (*head)->p_next;
	(*head)->p_next = next->p_next;
	next->p_next = (*head);
	*head = next;
}

void	ft_sb(t_node **head)
{
	t_node	*next;

	if (*head == NULL || (*head)->p_next == NULL )
		return ;
	next = (*head)->p_next;
	(*head)->p_next = next->p_next;
	next->p_next = *head;
	*head = next;
}

void	ft_ss(t_node **head_a, t_node **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
}
