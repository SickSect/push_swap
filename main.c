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

    mv = a;
    // JUST PRINT
    while (mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    printf("\n");
    mv = b;
    while (mv != NULL)
    {
        printf(" |B%d|", mv->data);
        mv = mv->p_next;
    }
    printf("\n");
    //
    f_sa(a, a->p_next);
    mv = a;
    // JUST PRINT
    while (mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    printf("\n");
    mv = b;
    while (mv != NULL)
    {
        printf(" |B%d| ", mv->data);
        mv = mv->p_next;
    }
    printf("\n");
    //
}