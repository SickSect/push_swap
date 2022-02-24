#include "push_swap.h"



int main(int argc, char **argv)
{
    (void)argc;
    //printf(" %d %c %c %c", argc, *argv[1], *argv[2], *argv[3]);
    t_node *head_a;
    t_node *head_b;

    head_b = malloc(sizeof(t_node));
    if (!head_b)
        return (0);
    head_a = malloc(sizeof(t_node));
    if (!head_a)
        return (0);
    head_a->data = ft_atoi(argv[1]);
    printf("%d",head_a->data);

}