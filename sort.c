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

void    parsing_by_med(t_node **by_med, t_node **push_here)
{
    int max;
    int min;
    int med;

    max = find_max(by_med);
    min = find_min(by_med);
    med = find_median(by_med);
    while (ft_lstlen(by_med) != 3)
    {
        if ((*by_med)->data != max && (*by_med)->data != min && (*by_med)->data != med)
            ft_pb(by_med, push_here);
        ft_ra(by_med);
    }
}

void    sort(t_node **head_a, t_node **head_b)
{
    (void)head_a;
    (void)head_b;
    pre_check(head_a, head_b);
    parsing_by_med(head_a, head_b);
    half_sort(head_a, 4);
    main_sort(head_a, head_b);
}