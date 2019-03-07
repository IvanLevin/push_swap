#include "push_swap.h"

void    num_of_covers(t_swap *swap)
{
    int i;

    i = swap->len;
    while (i > 5)
        i /= 2;
    swap->cover_num = i;
}