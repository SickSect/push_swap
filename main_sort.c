#include "push_swap.h"

static void rotater_b(t_node **head, int act, int data)
{
    int counter;
    int ra;
    int rra;
    t_node *mv;

    mv = (*head);
    counter = 0;
    while (mv->act != act && mv->data != data)
    {
        counter++;
        mv = mv->p_next;
    }
    rra = ft_lstlen(head) - counter;
    ra = counter;
    if (ra < rra)
        while (ra--)
            ft_rb(head);
    else
        while (rra--)
            ft_rrb(head);
}

static void choose_match(t_node **head_a, t_node **head_b)
{
    (void)head_a;
    t_node *mv;
    int act;
    int data;

    mv = (*head_b);
    act = mv->act;
    data = mv->data;
    while (mv != NULL)
    {
        if (act >= mv->act && data > mv->data)
        {
            act = mv->act;
            data = mv->data;
        }
        mv = mv->p_next;
    }
    printf("PUSH WILL ACT %d NUM %d\n", act, data);
    rotater_b(head_b, act, data);
    ft_pa(head_b, head_a);
    //printf("ACT %d DATA %d\n", act, data);
}

static void zero_act(t_node **head_a, t_node **head_b)
{
    t_node *mv;

    mv = (*head_a);
    while(mv != NULL)
    {
        mv->act = -1;
        mv = mv->p_next;
    }
    mv = (*head_b);
    while(mv != NULL)
    {
        mv->act = -1;
        mv = mv->p_next;
    }
}

static int check_moves(t_node **head_a, t_node **head_b)
{
    t_node	*mv;

    mv = (*head_b);
    while(mv != NULL)
    {
        mv->act = rotation(head_b, mv->data) + 1;
        where(head_a, mv->data);
        mv = mv->p_next;
    }
    mv = (*head_b);
    while (mv != NULL)
    {
        mv->act += which_one(head_a, mv->data);
        mv = mv->p_next;
    }
    return (0);
}

void main_sort(t_node **head_a, t_node **head_b)
{
    int it;

    it = 4;
    while (it--)
    {
        zero_act(head_a, head_b);
        check_moves(head_a, head_b);
        choose_match(head_a, head_b);
        sort_in_a(head_a);
        printer(head_a, head_b);
    }

}