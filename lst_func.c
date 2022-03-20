#include "push_swap.h"

void ft_lstdel(t_node *del)
{
    if (!del)
        return ;
    del->p_next = NULL;
    free(del);
}

void	lst_connect(t_node **head_a, t_node **head_b)
{
    int	counter;

    counter = ft_lstlen(head_b);
	printer(head_a, head_b);
    while(counter != 0)
    {
		ft_pa(head_b, head_a);
		counter--;
    }
	printer(head_a, head_b);
}

t_node  *lstlast(t_node **head)
{
    t_node *tmp;

    if (!(*head))
        return (NULL);
    tmp = *head;
    while(tmp->p_next != NULL)
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
	t_node *tmp;

	tmp = *head;
	while(tmp->p_next != NULL)
	{
		if (tmp->data > tmp->p_next->data)
			return (-1);
		tmp = tmp->p_next;
	}
	return (0);
}