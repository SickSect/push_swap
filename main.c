#include "push_swap.h"

void newargv_cleaner(char **argv)
{
    int i;
    int argc;

    i = 0;
    argc = 1;
    while (argv[argc])
        argc++;
    while (i < argc)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}

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

    i = 1;
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
    if (argc == 2 || argc == 1)
        return (-1);
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

int main(int argc, char **argv)
{
    (void)argc;
    t_node *a;
    t_node *b;
    char **new_argv;
    int new_argc;
    b = NULL;
    
    new_argv = make_simple_argv(argv);
    new_argc = count_complex_argv(argv) + 1;
    if (preview(new_argv, new_argc) == -1)
        return (0);
    add_memory(new_argv, &a, new_argc);
    if (check_doubles(&a) == -1)
    {
        newargv_cleaner(new_argv);
        ft_cleaner(a, b);
        ft_putstr("Error\n");
        return (-1);
    }
    if (new_argc == 3 || new_argc == 4)
        half_sort(&a, new_argc);
    if (is_sort(&a) == -1)
        sort(&a, &b);
    ft_cleaner(a, b);
    newargv_cleaner(new_argv);
    return (0);
}