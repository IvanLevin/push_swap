#include "push_swap.h"

void	swap_stack_a(t_swap *swap)
{
	if (swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2] &&
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a])
	{
		ra(swap);
		sa(swap);
		rra(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] &&
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2] &&
	swap->stack_a[swap->top_a + 1] < swap->stack_a[swap->top_a + 2])
	{
		sa(swap);
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] &&
	swap->stack_a[swap->top_a] < swap->stack_a[swap->top_a + 2])
		sa(swap);
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] &&
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2])
	{
		sa(swap);
		rra(swap);
	}
	else if (swap->stack_a[swap->top_a] < swap->stack_a[swap->top_a + 1] &&
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2])
	{
		ra(swap);
		sa(swap);
		rra(swap);
		sa(swap);
	}

	if (swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a + 3])
	{
		ra(swap);
		ra(swap);
		sa(swap);
		rra(swap);
		rra(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
		sa(swap);
}

void	function_3(t_swap *swap)
{
	if (swap->rec == 1)
		pa(swap);
	else if (swap->rec == 2)
	{
		if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
			sb(swap);
		pa(swap);
		pa(swap);
	}
	else if (swap->rec == 3)
	{
		pa(swap);
		pa(swap);
		pa(swap);
		swap_stack_a(swap);
	}
	else if (swap->rec > 2)
	{
		sort_stack_b(swap);

	}

}

int		check_sort_a(t_swap *swap) // сортировка для стека А
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			return (1);
		i++;
	}
	return (0);
}

void	function_2(t_swap *swap, int swap_len)
{
	int 	i;
	int 	flag;

	if (swap_len <= 3)
	{
		swap_stack_a(swap);
		sort_print(swap);
		return;
	}
	i = 0;
	flag = 0;
	pivot_a(swap);

	while (i < swap_len)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
		{
			pb(swap);
//			if (swap->rec)
//			{
//				if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
//					sb(swap);
//			}
			swap->rec++;
		}
		else
		{
			ra(swap);
			flag++;

		}
		sort_print(swap);
		i++;
	}
	if (flag)
		while(flag)
		{
			rra(swap);
			if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
				sa(swap);
			flag--;
			sort_print(swap);
		}
	if (swap_len - swap->rec <= 3 && check_sort_a(swap) == 1)
	{
		swap_stack_a(swap);
		sort_print(swap);
	}
	if (swap->rec)
		function_3(swap);
}

void	sort_stack_b(t_swap *swap)
{
	int 	i;
	int 	check;
	int 	swap_len;

	i = 0;
	check = 0;
	swap->check_a = swap->top_a;
	swap->rec = 0;

	if (swap->cap_len < 0)
		return;
	else if (swap->cap_len - (swap->cap_len - 1) <= 0)
			swap_len = swap->cap[swap->cap_len];
	else if (swap->cap_len == 0)
		swap_len = swap->cap[swap->cap_len];
	else
		swap_len = swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1];

	while (i < swap_len)
	{
		if (swap->stack_b[swap->top_b] >= swap->pivot)
		{
			pa(swap);
			if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
				sa(swap);
		}
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
	function_2(swap, swap_len);
	swap->cap_len--;
}

void	quick_sort(t_swap *swap)
{
	int 	i;

//	while (swap->top_a != 0)
//	{
	pivot_b(swap);
	sort_stack_b(swap);
	pivot_b(swap);
	sort_stack_b(swap);
	pivot_b(swap);
	sort_stack_b(swap);
	pivot_b(swap);
	sort_stack_b(swap);


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

void	put_stack_b(t_swap *swap)
{
	int 	len;
	int 	i;

	i = 0;
	len = swap->len_a;
	printf("pivot = %d\n", swap->pivot);
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