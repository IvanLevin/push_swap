#include "../include/push_swap.h"

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
    swap->sorted = swap->len - swap->top_a;
}

int     check_splitted_a(t_swap *swap)
{
    int i;
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

int     check_elems_down_a(t_swap *swap)
{
    int i;

    i = swap->top_a;
    while (i < swap->len - swap->sorted)
    {
        if (swap->stack_a[i] < swap->pivot)
            return (1);
        i++;
    }
    return (0);
}

void    put_b(t_swap *swap)
{
    while (check_splitted_a(swap) == 0)
    {
//        if (check_elems_down_a(swap) == 0)
//            break;
        if (swap->stack_a[swap->top_a] < swap->pivot)
            pb(swap);
        else
        {
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

void    sort_toa3(t_swap *swap)
{
    int i;

    i = swap->top_b;
    if (swap->stack_b[i] > swap->stack_b[i + 1] && swap->stack_b[i] < swap->stack_b[i + 2])
    {
        pa(swap);
        sb(swap);
        pa(swap);
        sa(swap);
        pa(swap);
    }
    else if (swap->stack_b[i] < swap->stack_b[i + 1] && swap->stack_b[i] < swap->stack_b[i + 2])
    {
        if (swap->stack_b[i + 1] > swap->stack_b[i + 2])
        {
            sb(swap);
            pa(swap);
            sb(swap);
            pa(swap);
            pa(swap);
        }
        else
        {
            pa(swap);
            sb(swap);
            pa(swap);
            sa(swap);
            pa(swap);
            sa(swap);
        }
    }
    else if (swap->stack_b[i] > swap->stack_b[i + 1] && swap->stack_b[i] > swap->stack_b[i + 2])
    {
        if (swap->stack_b[i + 1] > swap->stack_b[i + 2])
        {
            pa(swap);
            pa(swap);
            pa(swap);
        }
        else
        {
            pa(swap);
            sb(swap);
            pa(swap);
            pa(swap);
        }
    }
    else if (swap->stack_b[i] < swap->stack_b[i + 1] && swap->stack_b[i] > swap->stack_b[i + 2])
    {
        sb(swap);
        pa(swap);
        pa(swap);
        pa(swap);
    }
    swap->temp--;
    swap->sorted = swap-> len - swap->top_a;
}

int    b_del(t_swap *swap)
{
    if (swap->sorted == swap->len)
        return (1);
    int j = 0;
    if (swap->temp == 2)
        split_stacks_toa2(swap);
    split_stacks_toa(swap);
    sort_a(swap);
    return (0);
}

void    split_stack_b(t_swap *swap)
{
    new_pivot_b(swap);
    while (1)
    {
        if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] == 3)
            sort_toa3(swap);
        if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] <= 4)
            sort_toa(swap);
        new_pivot_b(swap);
        if (b_del(swap) == 1)
            break;
    }
}