#include "push_swap.h"

void printer(t_node **head_a, t_node **head_b)
{
    t_node *mv;

    printf("A\n");
    mv = *head_a;
    while(mv != NULL)
    {
        printf(" |%d", mv->data);
        printf(" M_%d| ", mv->act);
        mv = mv->p_next;
    }
    printf("\nB\n");
    mv = *head_b;
    while(mv != NULL)
    {
        printf(" |%d", mv->data);
        printf(" M_%d| ", mv->act);
        mv = mv->p_next;
    }
}