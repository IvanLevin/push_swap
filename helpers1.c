#include "push_swap.h"

int     split_stacks_tob(t_swap *swap)
{
    int i = 0;
    while (i < swap->len)
    {
        if (swap->stack_a[i] < swap->pivot)
        {
            pb(swap);
            i++;
        }
        else
            ra(swap);
        if (i >= swap->len / 2)
            break;
    }
    return (0);
}

int     split_stacks_toa(t_swap *swap)
{
    int i;

    i = swap->top_b;
    print_stacks(swap);
    while (check_splitted(swap) == 0)
    {
        if (swap->stack_b[i] >= swap->pivot)
        {
            pa(swap);
            i++;
        }
        else
            rb(swap);
        print_stacks(swap);
    }
    return (0);
}

void     new_pivot(t_swap *swap)
{
    int *sort;
    int i;
    int j;

    j = 0;
    sort = (int *)malloc(sizeof(int) * (swap->len - swap->top_b));
    i = swap->top_b;
    while (i < swap->len)
    {
        sort[j++] = swap->stack_b[i];
        i++;
    }
    sort = ft_selection_sort(sort, swap->len - swap->top_b);
    i = 0;
    while (i < swap->len - swap->top_b)
    {
        ft_printf("%d ", sort[i]);
        i++;
    }
    swap->pivot = sort[(swap->len - swap->top_b) / 2];
//    swap->max_cover = swap->stack_a[swap->len - 1];
    swap->min_cover[swap->temp_cover++] = swap->stack_a[swap->top_a];
}

int     check_splitted(t_swap *swap)
{
    int i;

    i = swap->top_b;
    while (i < swap->len)
    {
        if (swap->stack_b[i] >= swap->pivot)
            return (0);
        else
            i++;
    }
    return (1);
}

void    print_stacks(t_swap *swap)
{
    int i;

    i = 0;
    while (i < swap->len)
    {
        if (i < swap->top_a && i < swap->top_b)
            ft_printf("    _      _\n");
        else if (i < swap->top_a && i >= swap->top_b)
            ft_printf("   _      %d\n", swap->stack_b[i]);
        else if (i >= swap->top_a && i < swap->top_b)
            ft_printf("   %-7d _\n", swap->stack_a[i]);
        else
            ft_printf("   %-7d %d\n", swap->stack_a[i], swap->stack_b[i]);
        i++;
    }
}