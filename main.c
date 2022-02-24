#include "push_swap.h"



int main(int argc, char **argv)
{
    (void)argc;
    //printf(" %d %c %c %c", argc, *argv[1], *argv[2], *argv[3]);
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
    a->data = ft_atoi(argv[i]);
    mv = a;
    i++;
    while (i < argc)
    {
        mv->p_next = ft_lstnew(ft_atoi(argv[i]));
        mv = mv->p_next;
        i++;
    }



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