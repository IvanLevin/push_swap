#include "push_swap.h"

void   sort_a(t_swap *swap)
{
    int i;

    i = swap->top_a;
        if (swap->stack_a[i] > swap->stack_a[i + 1] && swap->stack_a[i] < swap->stack_a[i + 2])
        {
            sa(swap);
            ra(swap);
            ra(swap);
            ra(swap);

        }
}

int    check_sorted(t_swap *swap)
{
    int i;

    i = swap->top_a;
    while (i < swap->len - 1)
    {
        if (swap->stack_a[i] > swap->stack_a[i + 1])
            return (0);
        else
            i++;
    }
    return (1);
}

int    num_of_covers(t_swap *swap)
{
    int i;
    int j;

    j = 0;
    i = swap->len;
    while (i > 3)
    {
        i /= 2;
        j++;
    }
    return (j * 2);
}