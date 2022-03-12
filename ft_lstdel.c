#include "push_swap.h"

void ft_lstdel(t_node *del)
{
    if (!del)
        return ;
    del->p_next = NULL;
    free(del);
}