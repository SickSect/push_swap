#include "push_swap.h"

int find_median(t_node **head)
{
    int counter;
    t_node *mv;
    t_node *m_mv;

    m_mv = (*head);
    while(m_mv->p_next != NULL)
    {
        mv = (*head);
        counter = 0;
        while(mv != NULL)
        {
            if(mv->data > m_mv->data)
                counter++;
            mv = mv->p_next;
        }
        if (counter == ft_lstlen(head) / 2)
            return (m_mv->data);
        m_mv = m_mv->p_next;
    }
    return (0);
}

int find_max(t_node **head)
{
    t_node *mv;
    int     tmp;

    mv = (*head);
    tmp = mv->data;
    while(mv != NULL)
    {
        if (tmp < mv->data)
            tmp = mv->data;
        mv = mv->p_next;
    }
    return (tmp);
}

int find_min(t_node **head)
{
    t_node *mv;
    int     tmp;

    mv = (*head);
    tmp = mv->data;
    while(mv != NULL)
    {
        if (tmp > mv->data)
            tmp = mv->data;
        mv = mv->p_next;
    }
    return (tmp);
}

void zero_act(t_node **head_a, t_node **head_b)
{
    t_node *mv;

    mv = (*head_a);
    while(mv != NULL)
    {
        mv->act = 0;
        mv = mv->p_next;
    }
    mv = (*head_b);
    while(mv != NULL)
    {
        mv->act = 0;
        mv = mv->p_next;
    }
}

void    sort(t_node **head_a, t_node **head_b)
{
    t_node *here;
   
    here = pre_check(head_a);
    if (here->act <= 3)
        parsing_by_med(head_a, head_b);
    else
        smart_parcing(head_a, head_b, here);
    main_sort(head_a, head_b);
    printer(head_a, head_b);
}