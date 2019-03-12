#include "push_swap.h"

void    find_max_min(t_swap *swap)
{
    int i;

    i = 0;
    swap->min = swap->stack_b[swap->top_b];
    swap->min = swap->stack_b[swap->top_b];
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

    i = 0;
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
            i++;
        }
        else
            sb(swap);
    }
    while (check_sorted(swap) == 0)
        ra(swap);
    swap->temp--;
    swap->sorted = swap->top_a;
}

int 	swap_quick_sort(t_swap *swap)
{
	int		i;
    int     j;

    j = 0;
	i = 0;
	while (i < swap->len)
    {
	    while (swap->top_a < swap->len - 3)
	    {
            split_stacks_tob(swap);
            new_pivot(swap);
        }
        sort_min(swap);
        swap->temp--;
        new_pivot_b(swap);
        sort_toa(swap);
        new_pivot_b(swap);
        split_stacks_toa(swap);
        sort_a(swap);
        swap->temp--;
        sort_toa(swap);
        new_pivot_b(swap);
        split_stacks_toa(swap);
//        printf(TURQUOISE"\n-----------\n");
//        while (j < num_of_covers(swap))
//            printf("%d ", swap->uns_mas[j++]);
//        sort_a(swap);
//        printf(TURQUOISE"\n-----------\n");
//        while (j < num_of_covers(swap))
//            printf("%d ", swap->uns_mas[j++]);
//        swap->temp--;
//        sort_toa(swap);
        break;
	}
	printf(TURQUOISE"\n-----------\n");
	ft_printf("len = %d, SCORE = %d",swap->len, swap->score);
	return (0);
}
