#include "push_swap.h"

void 	sort_print(t_swap *swap)
{
	int i;

	i = 0;
	printf("-----------\n");
	while (i < swap->len)
	{
		if (i < swap->top_a && i < swap->top_b)
			ft_printf("_    _\n");
		else if (i < swap->top_a && i >= swap->top_b)
			ft_printf("_    %d\n", swap->stack_b[i]);
		else if (i >= swap->top_a && i < swap->top_b)
			ft_printf("%d    _\n", swap->stack_a[i]);
		else
			ft_printf("%d    %d\n", swap->stack_a[i], swap->stack_b[i]);
		i++;
	}
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
	len = swap->len;
	while (i < len)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
			pb(swap);
		else
			ra(swap);
		i++;
	}
	sort_print(swap);
}

int 	swap_quick_sort (t_swap *swap)
{
	int		i;

	i = 0;
	while (i < swap->len)
	{
		while (3 < swap->len - swap->len_b)
		{
			put_stack_b(swap);
			new_pivot_a(swap);
		}
		i++;
	}
	sort_min(swap);
	sort_print(swap);
	return (0);
}