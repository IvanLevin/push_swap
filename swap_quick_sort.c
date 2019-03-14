#include "push_swap.h"

void	pivot_b(t_swap *swap)
{
	int 	*sort;
	int 	i;
	int 	stack;

	i = 0;
	sort = (int *)malloc(sizeof(int) * swap->len_b - swap->cap[swap->cap_len- 1]);
	stack = swap->top_b;
	while (i < swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1])
	{
		sort[i] = swap->stack_b[stack];
		i++;
		stack++;
	}
	sort = ft_selection_sort(sort, swap->cap[swap->cap_len] -
			swap->cap[swap->cap_len - 1]);
	swap->pivot = (swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1]) / 2;
	swap->pivot = sort[swap->pivot];
		printf("pivot = %d\n", swap->pivot);
		i = 0;
		while (i < swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1])
			printf("%d ", sort[i++]);
		printf("\n");
	free(sort);
}

void	function_2(t_swap *swap, int check_a)
{
	int i;
	int check;
	int das;

	i = 0;
	das = 0;
	check = swap->top_a;
	new_pivot_a(swap);
//	while (i < swap->stack_a[check_a] - swap->stack_a[swap->top_a])
//	{
//		if (swap->stack_a[check] >= swap->pivot)
//		{
//			if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
//				sa(swap);
//			pb(swap);
//		}
//		else
//		{
//			pb(swap);
//			das++;
//		}
//		i++;
//		sort_print(swap);
//	}
//	if (das != 0)
//		while (das)
//		{
//			rra(swap);
//			das--;
//			sort_print(swap);
//		}


}
void 	function_1(t_swap *swap)
{
	if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
		sb(swap);
	pa(swap);
	if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
		sa(swap);
	pa(swap);

}

void	sort_stack_b(t_swap *swap)
{
	int 	i;
	int 	check;

	i = 0;
	check = 0;
	int check_a = swap->top_a;
	printf("pivot = %d\n", swap->pivot);
	while (1)
	{
		while (i < swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1])
		{
			if (swap->stack_b[swap->top_b] >= swap->pivot)
				function_1(swap);
			else
			{
				rb(swap);
				check++;
			}
			i++;
			sort_print(swap);
		}
		if (check != 0)
			while (check)
			{
				rrb(swap);
				pa(swap);
				check--;
				sort_print(swap);

			}
		else
			break;
	}
	function_2(swap, check_a);
}

void	quick_sort(t_swap *swap)
{
	int 	i;

//	while (swap->top_a != 0)
//	{
	pivot_b(swap);
	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	pivot_b(swap);
//	sort_stack_b(swap);
//	}
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
	i = 0;
	while (i < swap->len_a)
		printf("%d ", sort[i++]);
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