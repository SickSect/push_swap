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
  
    mv = a;
    while (mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    mv = b;
    printf("\n");
    while (mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    ft_ra(&a);
    mv = a;
    printf("\n");
    while (mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    mv = b;
    printf("\n");
    while (mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    ft_cleaner(a);
}