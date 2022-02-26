#include "push_swap.h"

void alloc_mem(t_node *a, t_node *b)
{
    b = malloc(sizeof(t_node));
    if (!b)
        return (0);
    a = malloc(sizeof(t_node));
    if (!a)
        return (0);
}

int main(int argc, char **argv)
{
    int     i;
    t_node *a;
    t_node *b;
    t_node *mv;

    i = 1;
    alloc_mem(a, b);
    a->data = ft_atoi(argv[i++]);
    mv = a;
    while (i < argc)
    {
        mv->p_next = ft_lstnew(ft_atoi(argv[i++]));
        mv = mv->p_next;
    }


    mv = f_sa(a, a->p_next);
    // JUST PRINT
    while (mv->p_next != NULL)
    {
        printf(" res = %d\n", mv->data);
        mv = mv->p_next;
    }
    printf(" res = %d\n FIN\n", mv->data);
    //
    f_sa(a, a->p_next);
}