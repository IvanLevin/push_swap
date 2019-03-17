#include "push_swap.h"

void    find_max_min(t_swap *swap)
{
    int i;

    i = 0;
    swap->min = swap->stack_b[swap->top_b];
    swap->max = swap->stack_b[swap->top_b];
    while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
    {
        if (swap->stack_b[i + swap->top_b] < swap->min)
            swap->min = swap->stack_b[i + swap->top_b];
        if (swap->stack_b[i + swap->top_b] > swap->max)
            swap->max = swap->stack_b[i + swap->top_b];
        i++;
    }
}

void    sort_toa(t_swap *swap)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] == 4)
    {
        new_pivot_b(swap);
        b_del(swap);
        sort_toa2(swap);
        flag = 1;
    }
    if (flag == 0)
        while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
        {
            find_max_min(swap);
            if (swap->stack_b[swap->top_b] == swap->max)
            {
                pa(swap);
                i++;
            }
            else if (swap->stack_b[swap->top_b] == swap->min)
            {
                pa(swap);
                ra(swap);
                swap->unsorted++;
                i++;
            }
            else
    //        else if (swap->stack_b[swap->top_b + 1] == swap->max || \
    //            swap->stack_b[swap->top_b + 1] == swap->min)
                sb(swap);
    //        else
    //        {
    //            rb(swap);
    //            swap->unsorted++;
    //        }
        }
    while (swap->unsorted)
    {
        rra(swap);
        swap->unsorted--;
    }
    while (check_sorted(swap) == 0)
        ra(swap);
    swap->temp--;
    swap->sorted = swap->len - swap->top_a;
}

int 	swap_quick_sort(t_swap *swap)
{
    while (swap->top_a < swap->len - 3)
    {
        split_stacks_tob(swap);
        new_pivot(swap);
    }
    sort_min(swap);
    swap->temp--;
    split_stack_b(swap);
	printf(TURQUOISE"\n-----------\n");
	ft_printf("len = %d, SCORE = %d",swap->len, swap->score);
	return (0);
}
