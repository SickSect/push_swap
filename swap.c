#include "push_swap.h"

/*
struct s_node *f_sa(t_node *head, t_node *next)
{
    if (!head)
        return (NULL);
    if (!next)
        return (head);
    head->p_next = next->p_next;
    next->p_next = head;
    return (next);
}

struct s_node *f_sb(t_node *head, t_node *next)
{
    if (!head)
        return (NULL);
    if (!next)
        return (head);
    head->p_next = next->p_next;
    next->p_next = head;
    return (next);
}

void f_ss(t_node *head_a, t_node *head_b)
{
    head_a = f_sa(head_a,head_a->p_next);
    head_b = f_sb(head_b, head_b->p_next);
}
*/

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