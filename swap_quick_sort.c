#include "push_swap.h"

int 	swap_quick_sort (t_swap *swap)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < swap->len)
	{
		if (swap->stack_a[i] < swap->pivot)
			pb(swap);
		else
			ra(swap);
		i++;
	}

	i = 0;
	printf(TURQUOISE"-----------\n");
	while (i < swap->len)
	{
		if (i < swap->top_a && i < swap->top_b)
			printf("_ _\n");
		else if (i < swap->top_a && i >= swap->top_b)
			printf("_ %d\n", swap->stack_b[i]);
		else if (i >= swap->top_a && i < swap->top_b)
			printf("%d _\n", swap->stack_a[i]);
		else
			printf("%d %d\n", swap->stack_a[i], swap->stack_b[i]);
		i++;
	}
	return (0);
}