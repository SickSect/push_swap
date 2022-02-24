#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*tmp;

	tmp = (t_node*)malloc(sizeof(*tmp));
	if (!tmp)
	{
		tmp = NULL;
		return (NULL);
	}
	tmp->data = content;
	tmp->p_next = NULL;
	return (tmp);
}