#include "push_swap.h"

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



