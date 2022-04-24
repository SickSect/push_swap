#include "push_swap.h"

static t_node *lower(t_node **head_a)
{
    t_node *mv;
    t_node *low;

    mv = (*head_a)->p_next;
    low = (*head_a)->p_next;
    while (mv != NULL)
    {
        if (low->data > mv->data)
            low = mv;
        mv = mv->p_next;
    }
    return (low);
}

void sort_node(t_node**head_a)
{
    t_node *put_before;
    t_node *mv;
    t_node *lowest;

    put_before = NULL;
    lowest = lower(head_a);
    if (lowest->data == (*head_a)->p_next->data)
    {
        mv = (*head_a)->p_next;
        while (mv != NULL)
        {
            if (mv->data > (*head_a)->data)
            {
                put_before = mv;
                printf("FIND BY COMMON WAY %d\n", put_before->data);
                mv = NULL;
            }
            else
                mv = mv->p_next;
        }
    }
    else
    {
        while (lowest != NULL)
        {
            if (lowest->data > (*head_a)->data)
            {
                put_before = lowest;
                printf("FIND BY COMPLEX WAY %d\n", put_before->data);
                lowest = NULL;
            }
            else
                lowest = lowest->p_next;
        }
        if (put_before == NULL)
        {
            mv = (*head_a)->p_next;
            while (mv != NULL)
            {
                if (mv->data > (*head_a)->data)
                {
                    put_before = mv;
                    printf("FIND BY COMPLEX WAY %d\n", put_before->data);
                    mv = NULL;
                }
                else
                    mv = mv->p_next;
            }
        }
    }
    printf("PUT NEW ELEMENT BEFORE %d\n", put_before->data);
    if (put_before != NULL)
    {
        while ((*head_a)->p_next->data != put_before->data )
        {
            ft_sa(head_a);
            ft_ra(head_a);
        }
    }
}


int is_sort_index(t_node **head_a)
{
    //printf("NEW FUNC TEST START\n");
    t_node *mv;
    int     lowest;

    lowest = lower(head_a)->data; // aby but not first element
    printf("low is %d\n", lowest);
    sleep(1);
    if ((*head_a)->p_next->data == lowest)
    {
        mv = (*head_a)->p_next;
        while (mv != NULL)
        {
            if (mv->data > (*head_a)->data)
            {
                printf("FOUND BY COMMON TRY %d\n", mv->data);
                return (mv->data);
            }
            mv = mv->p_next;
        }
    }
    else
    {
        mv = lower(head_a);
        while (mv != NULL)
        {
            if (mv->data > (*head_a)->data)
            {
                printf("FOUND BY COMPLEX TRY %d\n", mv->data);
                return (mv->data);
            }
            mv = mv->p_next;
        }
        mv = (*head_a)->p_next;
        while (mv != NULL && mv->data != lowest)
        {  
            if (mv->data > (*head_a)->data)
            {
                printf("FOUND BY COMPLEX TRY %d\n", mv->data);
                return (mv->data);
            }
            mv = mv->p_next;
        }
    }
    return (-1);
}

static void swap_data_to_act(t_node **head_a)
{
    t_node *mv;
    int tmp;

    mv = (*head_a);
    while (mv != NULL)
    {
        tmp = mv->data;
        mv->data = mv->act;
        mv->act = tmp;
        mv = mv->p_next;
    }
}

void indexier(t_node **head_a)
{
    t_node *mv;
    t_node *m_mv;
    int counter;

    mv = (*head_a);
    while (mv != NULL)
    {
        counter = 1;
        m_mv = (*head_a);
        while (m_mv != NULL)
        {
            if (mv->data > m_mv->data)
                counter++;
            m_mv = m_mv->p_next;
        }
        mv->act = counter;
        mv = mv->p_next;
    }
    swap_data_to_act(head_a);
}