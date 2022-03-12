#include "push_swap.h"

void ft_sa(t_node **head)
{
	t_node *next;

	if (!(*head))
		return ;
	else if (!(*head)->p_next)
		return ;
	next = (*head)->p_next;
  //printf(" HEAD %d NEXT %d ", (*head)->data, next->data);
  //printf("\nADRESS HEAD |%p|\n ADDRESS NEXT |%p|\n ", (*head), next);
  	(*head)->p_next = next->p_next;
  	next->p_next = (*head);
  	*head = next;
   //printf("\nADRESS HEAD |%p|\n ADDRESS NEXT |%p|\n ", (*head), next);  
}

void ft_sb(t_node **head);
{
    t_node	*next;

	if (!(*head))
		return ;
	else if (!(*head)->p_next)
		return ;
	next = (*head)->p_next;
	(*head)->p_next = next->p_next;
	next->p_next = (*head);
	*head = next;
}

void ft_ss(t_node **head_a, t_node **head_b)
{
	ft_sa()
}