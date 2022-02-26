#include "push_swap.h"



int main(int argc, char **argv)
{
    int     i;
    t_node *a;
    t_node *b;
    t_node *mv;

    i = 1;
    b = malloc(sizeof(t_node));
    if (!b)
        return (0);
    a = malloc(sizeof(t_node));
    if (!a)
        return (0);
    a->data = ft_atoi(argv[i++]);
    mv = a;
    while (i < argc)
    {
        mv->p_next = ft_lstnew(ft_atoi(argv[i++]));
        mv = mv->p_next;
    }



    // JUST PRINT
    mv = a;
    while (mv->p_next != NULL)
    {
        printf(" res = %d\n", mv->data);
        mv = mv->p_next;
    }
    printf(" res = %d\n FIN\n", mv->data);
    //
    f_sa(a, a->p_next);
    // JUST PRINT
    mv = a;
    while (mv->p_next != NULL)
    {
        printf(" res = %d\n", mv->data);
        mv = mv->p_next;
    }
    printf(" res = %d\n", mv->data);
    //
}