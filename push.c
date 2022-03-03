#include "push_swap.h"

void f_pb(t_node *head_a, t_node *head_b)
{

    if(!head_a)
        return ;
    if(!head_b)
    {
        head_b = ft_lstnew(head_a->data);
        t_node *tmp;
        tmp = head_a->p_next;
        head_a = tmp;
    }
    else
    {
        
    }
}