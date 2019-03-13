#include "push_swap.h"

void	pivot_b(t_swap *swap)
{
	int 	*sort;
	int 	i;

	i = swap->len_b;
	sort = (int *)malloc(sizeof(int) * swap->len_b - swap->cap[swap->cap_len]);
//	while (swap->stack_b[i] && i > swap->)
}

void	quick_sort(t_swap *swap)
{
	pivot_b(swap);

}

void 	sort_print(t_swap *swap)
{
	int i;

	i = 0;
	printf(GREEN"        ----------------\n");
	while (i < swap->len)
	{
		if (i < swap->top_a && i < swap->top_b)
			ft_printf("         _          _\n");
		else if (i < swap->top_a && i >= swap->top_b)
			ft_printf("         _ %10d\n", swap->stack_b[i]);
		else if (i >= swap->top_a && i < swap->top_b)
			ft_printf("%10d          _\n", swap->stack_a[i]);
		else
			ft_printf("%10d %10d\n", swap->stack_a[i], swap->stack_b[i]);
		i++;
	}
	printf("       ----------------\n");
	ft_printf(BLUE);
}

void	new_pivot_a(t_swap *swap)
{
	int		*sort;
	int 	i;
	int 	j;

	i = 0;
	j = swap->top_a;
	sort = (int *)malloc(sizeof(int) * swap->len_a);
	while (i < swap->len_a)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->len_a);
	swap->pivot = swap->len_a / 2;
	swap->pivot = sort[swap->pivot];
	printf("\n");

}

void	put_stack_b(t_swap *swap)
{
	int 	len;
	int 	i;

	i = 0;
	len = swap->len_a;
	printf("pivot = %d\n", swap->pivot);
	while (i < len)
	{
		if (swap->stack_a[swap->top_a] <= swap->pivot)
			pb(swap);
		else
			ra(swap);
		i++;
	}
	sort_print(swap);
}

int 	swap_quick_sort(t_swap *swap)
{
	int		i;
	int 	cap;

	i = 0;
	while (3 < swap->len - swap->len_b)
	{
		put_stack_b(swap);
		new_pivot_a(swap);
		swap->cap[i++] = swap->len_b;
		printf("cap = %d \n", swap->cap[i - 1]);
	}
	swap->cap_len = i - 1;
	sort_min(swap);
	quick_sort(swap);

	return (0);
}