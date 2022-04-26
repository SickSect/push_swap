#include "push_swap.h"

void base_copier(char *orig, char **main, int index)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(orig);
    main[index] = malloc(sizeof(char) * len + 1);
    main[index][len] = '\0';
    while(orig[i])
    {
        main[index][i] = orig[i];
        i++;
    }
}