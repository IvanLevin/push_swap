#include "push_swap.h"

void    put_sorted(t_swap *swap)
{
    --swap->temp_cover;
    while (swap->stack_a[swap->top_a] < swap->min_cover[swap->temp_cover])
        ra(swap);
}

int     prior(t_swap *swap)
{
    int minlen;
    int maxlen;

    swap->way = -1;
    if (swap->len_min - swap->top_b < (swap->len - swap->top_b) / 2 + 1)         // выше середины
    {
        swap->way = -1;
        minlen = swap->len_min - swap->top_b;
    }
    else    // ниже середины
    {
        swap->way = 1;
        minlen = swap->len - swap->len_min + 1;
    }
    if (swap->len_max - swap->top_b < (swap->len - swap->top_b) / 2 + 1)
    {
        swap->way = -1;
        maxlen = swap->len_max - swap->top_b;
    }
    else
    {
        swap->way = 1;
        maxlen = swap->len - swap->len_max + 1;
    }
    if (minlen < maxlen)
        return (swap->stack_b[swap->len_min]);
    else
        return (swap->stack_b[swap->len_max]);
}

int     find_max_min(t_swap *swap)
{
    int i;

    i = swap->top_b;
    swap->len_max = i;
    swap->len_min = i;
    swap->max = swap->stack_b[i];
    swap->min = swap->stack_b[i];
    while (i < swap->len)
    {
        if (swap->stack_b[i] < swap->min)
        {
            swap->min = swap->stack_b[i];
            swap->len_min = i;
        }
        if (swap->stack_b[i] > swap->max)
        {
            swap->max = swap->stack_b[i];
            swap->len_max = i;
        }
        i++;
    }
    return (prior(swap));
}

void    move_prior_to_the_top(t_swap *swap, int prior)
{
    int i;

    i = swap->top_b;
    while (i < swap->len)
    {
        if (swap->stack_b[i] == prior)
            break;
        if (swap->way == -1)
            while (swap->stack_b[i] != prior)
            {
                rb(swap);
            }
        else
            while (swap->stack_b[i] != prior) {
                rrb(swap);
            }
    }
}

void    sort_min_max(t_swap *swap, int prior)
{
    int i;

    i = swap->top_b;
    while (i < swap->len)
    {
        move_prior_to_the_top(swap, prior);
        if (swap->stack_b[i] == prior)
        {
            if (swap->stack_b[i] == swap->max) {
                pa(swap);
            }
            else if (swap->stack_b[i] == swap->min)
            {
                pa(swap);
                ra(swap);
            }
        }
        prior = find_max_min(swap);
        i++;
    }
    put_sorted(swap);
}

void    put_max_and_min(t_swap *swap)
{
    int i;
    int prior;

    i = 0;
    while (swap->top_b < swap->len)
    {
        prior = find_max_min(swap);
        sort_min_max(swap, prior);
    }
}



int 	swap_quick_sort(t_swap *swap)
{
	int		i;

	i = 0;
	while (i < swap->len)
    {
	    split_stacks_tob(swap);
	    if (swap->top_b < swap->len - 3)
	        new_pivot(swap);
	    split_stacks_toa(swap);
        new_pivot(swap);
//        split_stacks_toa(swap);
//        new_pivot(swap);
        put_max_and_min(swap);
        new_pivot(swap);
               split_stacks_tob(swap);
        break;
	}
	i = 0;
	printf(TURQUOISE"\n-----------\n");
	ft_printf("len = %d, SCORE = %d, cover_num = %d",swap->len, swap->score, swap->cover_num);
	return (0);
}
