#include "push_swap.h"

static void ft_cleaner(t_node *head)
{
    while(head)
    {
        free(head);
        head = head->p_next;
    }
    free(head);
}

static void sort(t_node **head_a, t_node **head_b)
{
    int	quick;

	quick = quick_sort(head_a, head_b);
    (void)quick;
}

int main(int argc, char **argv)
{
    int     i;
    t_node *a;
    t_node *b;
    t_node *mv;

    i = 1;
    b = NULL;
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
    // make checker
    sort(&a, &b);
    ft_cleaner(a);
    ft_cleaner(b);
}