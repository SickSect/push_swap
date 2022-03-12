#include "push_swap.h"

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