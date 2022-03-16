#include "push_swap.h"

void printer(t_node **head_a, t_node **head_b)
{
    t_node *mv;

    printf("\n");
    mv = *head_a;
    while(mv != NULL)
    {
        printf(" |A%d| ", mv->data);
        mv = mv->p_next;
    }
    printf("\n");
    mv = *head_b;
    while(mv != NULL)
    {
        printf(" |B%d| ", mv->data);
        mv = mv->p_next;
    }
}