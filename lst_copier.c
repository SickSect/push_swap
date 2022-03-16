#include "push_swap.h"

t_node	*lst_copier(t_node **head, t_node **copy)
{
	t_node *mv;
	t_node *copy;
	t_node *head_copy;

	mv = (*head);
	copy = malloc(sizeof(t_node));
	copy->data = mv->data;
	head_copy = copy;
	mv = mv->p_next;
	while(mv->p_next != NULL)
	{
		(*copy)->p_next = ft_lstnew(mv->data);
		mv = mv->p_next;
	}
	return (head_copy);
}