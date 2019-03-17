#include "push_swap.h"

void    sort_toa2(t_swap *swap)
{
    int i;

    i = 0;
    while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
    {
        find_max_min(swap);
        if (swap->stack_b[swap->top_b] == swap->max)
        {
            pa(swap);
            i++;
        } else if (swap->stack_b[swap->top_b] == swap->min) {
            pa(swap);
            ra(swap);
            i++;
        } else
            sb(swap);
    }
    while (check_sorted(swap) == 0)
        rra(swap);
//    swap->temp--;
    swap->sorted = swap->len - swap->top_a;
}

int     check_splitted_a(t_swap *swap)
{
    int i;
//    if (swap->top_a == swap->sorted)
//        return (1);
    i = swap->top_a;
    while (i < swap->len - swap->sorted)
    {
        if (swap->stack_a[i] < swap->pivot)
            return (0);
        else
            i++;
    }
    return (1);
}

void    put_b(t_swap *swap)
{
    int i;

    i = swap->top_a;
    while (check_splitted_a(swap) == 0)
    {
        if (swap->stack_a[swap->top_a] < swap->pivot)
            pb(swap);
        else {
            ra(swap);
            swap->unsorted++;
        }
    }
    while (swap->unsorted)
    {
        rra(swap);
        swap->unsorted--;
    }
    swap->uns_mas[swap->temp] = swap->len - swap->top_b;
}

int    b_del(t_swap *swap)
{
    if (swap->sorted == swap->len)
        return (1);
    int j = 0;
    split_stacks_toa(swap);
    printf("%d\n", swap->sorted);
    sort_a(swap);
    return (0);
}

void    split_stack_b(t_swap *swap)
{
    new_pivot_b(swap);
    while (swap->stack_a[swap->top_a] != 88)
    {
        if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] <= 4)
            sort_toa(swap);
        new_pivot_b(swap);
        if (b_del(swap) == 1)
            break;
    }
    while (1)
    {
        if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] <= 4)
            sort_toa(swap);
        new_pivot_b(swap);
        if (b_del(swap) == 1)
            break;
    }
}