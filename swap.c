#include "push_swap.h"

void	ft_sa(t_node **head)
{
	t_node	*next;

	if (*head == NULL || (*head)->p_next == NULL )
		return ;
	next = (*head)->p_next;
	(*head)->p_next = next->p_next;
	next->p_next = (*head);
	*head = next;
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ft_ss(t_node **head_a, t_node **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
}
