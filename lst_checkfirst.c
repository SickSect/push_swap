#include "push_swap.h"

int lst_checkfirst(t_node **head)
{
    t_node	*mv;

    mv = (*head)->p_next;
	while(mv->p_next != NULL)
	{
		if (mv->data > mv->p_next->data)
			return (-1);
		mv = mv->p_next;
	}
	return (0);
}