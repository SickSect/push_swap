#include "push_swap.h"
static int find_median(t_node **head, int num)
{
    int counter;
    t_node *mv;
    t_node *m_mv;

    mv = (*head);
    m_mv = (*head);
    while(m_mv->p_next != NULL)
    {
        counter = 0;
        while(mv->p_next != NULL)
        {
            if(mv->data > m_mv->data)
                counter++;
            mv = mv->p_next
        }
        if (counter == ft_lstlen(head) / 2)
        
        m_mv = m_mv->p_next;
    }
}

void    sort(t_node **head_a, t_node **head_b)
{
    
}