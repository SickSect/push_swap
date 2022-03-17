#include "push_swap.h"

static void ft_cleaner(t_node *head_a, t_node *head_b)
{
    while(head_a)
    {
        free(head_a);
        head_a = head_a->p_next;
    }
    free(head_a);
    while(head_b)
    {
        free(head_b);
        head_b = head_b->p_next;
    }
    free(head_b);
}

static int add_memory(char **argv, t_node **a, int argc)
{
    int     i;
    t_node *mv;

    i = 1;
    *a = malloc(sizeof(t_node));
    if (!a)
        return (-1); //!!!!
    (*a)->data = ft_atoi(argv[i++]);
    mv = *a;
    while (i < argc)
    {
        mv->p_next = ft_lstnew(ft_atoi(argv[i++]));
        mv = mv->p_next;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int op;
    (void)op;
    t_node *a;
    t_node *b;

    if (check_argv(argv, argc) == -1)
    {
        ft_putstr("Error\n");
        return (-1);
    }
    else if (check_argv(argv, argc) == 1)
        return (1);
    add_memory(argv, &a, argc);
    op = one_by_one_sort(&a, &b);
    //printer(&a, &b);
    //printf("OP IS %d", op);
    ft_cleaner(a, b);
    return (0);
}