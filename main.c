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
    if (head_b)
        free(head_b);
}

int add_memory(char **argv, t_node **a, int argc)
{
    int     i;
    t_node *mv;

    i = 0;
    *a = malloc(sizeof(t_node));
    if (!a)
        return (-1);
    (*a)->data = ft_atoi(argv[i++]);
    mv = *a;
    while (i < argc)
    {
        mv->p_next = ft_lstnew(ft_atoi(argv[i++]));
        mv = mv->p_next;
    }
    return (0);
}

static int preview(char **argv, int argc)
{
    if (argc == 1 || argc == 0)
        return (0);
    if (check_argv(argv, argc) == -1)
    {
        ft_putstr("Error\n");
        return (-1);
    }
    else if (check_argv(argv, argc) == -1)
    {
       ft_putstr("Error\n");
        return (-1);
    }
    return (0);
}
static int count_simpler_argc(char **argv)
{
    int count;

    count = 0;
    while (argv[count])
    {
        count++;
    }
    return (count);
}

int main(int argc, char **argv)
{
    (void)argc;
    t_node *a;
    t_node *b;
    char **simple_argv;
    int new_argc;
    b = NULL;
    
    simple_argv = make_simple_argv(argv);
    new_argc = count_simpler_argc(simple_argv);
    if (preview(simple_argv, new_argc) == -1)
        return(-1);   
    add_memory(simple_argv, &a, new_argc);
    if (check_doubles(&a) == -1)
    {
        ft_cleaner(a, b);
        ft_putstr("Error\n");
        return (-1);
    }
    if (new_argc == 2 || new_argc == 3)
        half_sort(&a, new_argc + 1);
    if (is_sort(&a) == -1)
        sort(&a, &b);
    ft_cleaner(a, b);
    clean_argv(simple_argv, new_argc);
    return (0);
}