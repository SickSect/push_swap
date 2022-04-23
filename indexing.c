#include "push_swap.h"

static t_node *lower(t_node **head_a)
{
    t_node *mv;
    t_node *low;

    mv = (*head_a);
    low = (*head_a);
    while (mv != NULL)
    {
        if (low->data > mv->data)
            low = mv;
        mv = mv->p_next;
    }
    //printf("LOWEST IS %d\n", low->data);
    //sleep(2);
    return (low);
}

void sort_node(t_node**head_a, t_node *sort_me)
{
    (void)head_a;
    t_node *put_before;
    t_node *mv;
    int counter;
    t_node *lowest;

    mv = (*head_a);
    counter = 0;
    put_before = NULL;
    while (mv->data != sort_me->data)
    {
        counter++;
        mv = mv->p_next;
    }
    printf("I THINK WE NEED %d actions to catch it\n", counter);
    lowest = lower(head_a);
    mv = (*head_a)->p_next;
    while (lowest != NULL && put_before == NULL)
    {
        if (lowest->data > sort_me->data)
            put_before = lowest;
        lowest = lowest->p_next;
    }
    if (put_before == NULL)
    {
        while (mv != NULL && put_before == NULL)
        {
            if (mv->data > sort_me->data)
                put_before = mv;
            mv = mv->p_next;
        }
    }
    while (sort_me->p_next->data != put_before->data )
    {
        ft_sa(head_a);
        ft_ra(head_a);
    }
    printf("I NEED TO PUT SORT ME BEFORE %d\n", put_before->data);
    sleep(1);
}


t_node *is_sort_index(t_node **head_a)
{
    //printf("NEW FUNC TEST START\n");
    t_node *mv;
    t_node *lowest;
    t_node *sort_me;

    mv = (*head_a);
    sort_me = NULL;
    lowest = lower(head_a);
    while (mv->data != lowest->data)
        mv = mv->p_next;
    //printf("GO HERE %d\n", mv->data);
    //sleep(2);
    if ((*head_a)->data == lowest->data)
    {
        while (mv->p_next != NULL)
        {
            if (mv->data > mv->p_next->data)
                sort_me = mv;
            mv = mv->p_next;
        }
        return (sort_me);
    }
    else
    {
        while (lowest->p_next!= NULL)
        {
            if (lowest->data > lowest->p_next->data)
                sort_me = lowest;
            lowest = lowest->p_next;
        }
        printf("MOVE LOWEST OK\n");
        sleep(2);
        if (sort_me != NULL)
            return (sort_me);
        lowest = lower(head_a);
        mv = (*head_a);
        while (mv->data != lowest->data && mv != NULL)
        {
            //printf("I AM LOOKING FOR THIS %d\n", mv->data);
            if (mv->data > mv->p_next->data)
                sort_me = mv;
            mv = mv->p_next;
        }
        if (sort_me != NULL)
            return (sort_me);
    }
    return (NULL);
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