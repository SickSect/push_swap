#include "push_swap.h"



static int check_moves(t_node **head_a, t_node **head_b)
{
    (void)head_a;
    int		it;
    t_node	*mv;
    int		*act_arr;

    act_arr = malloc(sizeof(int) * ft_lstlen(head_b));
    if (!act_arr)
        return (-1);
    mv = (*head_b);
    it = 0;
    while(mv != NULL)
    {
        act_arr[it] = rotation(head_b, mv->data);
        act_arr[it] += where(head_a, mv->data) + 1;
        it++;
        mv = mv->p_next;
    }
    which_one(head_a, head_b, act_arr);
	while(it--)
		printf("ACT #%d IS %d\n", it, act_arr[it]);
    free(act_arr);
    return (0);
}

void main_sort(t_node **head_a, t_node **head_b)
{
    check_moves(head_a, head_b);
    printer(head_a, head_b);
}