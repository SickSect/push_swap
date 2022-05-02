#include "push_swap_bonus.h"

void console(t_node **head_a, t_node **head_b)
{
    char *command;

    while (1)
    {
        command = get_next_line(0);
        if (command = NULL)
        {
            
        }
        if (!linker(head_a, head_b, command))
        {
            ft_putstr("Error\n");
            free(command);
            return ;
        }
        free(command);
    }
}