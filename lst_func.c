#include "push_swap.h"

t_node	*lstlast(t_node **head)
{
	t_node	*tmp;

	if (!(*head))
		return (NULL);
	tmp = *head;
	while (tmp->p_next != NULL)
		tmp = tmp->p_next;
	return (tmp);
}

t_node	*ft_lstnew(int content)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
	{
		tmp = NULL;
		return (NULL);
	}
	tmp->data = content;
	tmp->p_next = NULL;
	return (tmp);
}

int	is_sort(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->p_next != NULL)
	{
		if (tmp->data > tmp->p_next->data)
			return (-1);
		tmp = tmp->p_next;
	}
	return (0);
}
