#include "push_swap.h"

int find_median(t_node **head)
{
    int counter;
    t_node *mv;
    t_node *m_mv;

    m_mv = (*head);
    while(m_mv != NULL)
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

void    sort(t_node **head_a, t_node **head_b)
{
    indexier(head_a);
    while(is_sort(head_a) == -1)
		quick_sort(head_a, head_b);
}