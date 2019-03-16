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


void	function_2(t_swap *swap, int swap_len)
{
	int 	i;
	int 	flag;

	if (swap_len <= 3)
	{
		if (check_sort(swap) == 0)
			return;
		swap_stack_a(swap);
		sort_print(swap);
		return;
	}
	i = -1;
	flag = 0;
	pivot_a(swap);
	while (++i < swap_len && check_sort(swap) == 1)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
		{
			pb(swap);
			swap->rec++;
		}
		else
		{
			if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
				sa(swap);
			ra(swap);
			flag++;
		}
		sort_print(swap);
	}
	while(flag != 0)
	{
		rra(swap);
		if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			sa(swap); // делит
		flag--;
		sort_print(swap);
	}
	if (swap->check_a - swap->top_a <= 3 && check_sort(swap) == 1)
		swap_stack_a(swap);
	else if (swap->check_a - swap->top_a > 3 && check_sort(swap) == 1)
	{
		function_2(swap, swap->check_a - swap->top_a);
		swap->rec = 0;
	}
	if (swap->rec)
	{
		swap->swap_len = swap->rec;
		pivot_b_test(swap);
		sort_stack_b(swap);
	}
}

void	sort_stack_b(t_swap *swap)
{
	int 	i;
	int 	check;

	i = 0;
	check = 0;
	swap->check_a = swap->top_a;
	while (i < swap->swap_len)
	{
		if (swap->stack_b[swap->top_b] >= swap->pivot)
		{
			pa(swap);
			if (swap->rec)
				swap->rec--;
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
			if (swap->rec)
				swap->rec--;
			check--;
			sort_print(swap);
		}
	function_2(swap, swap->swap_len);
	swap->rec = 0;
}

void	quick_sort(t_swap *swap)
{
	while (1)
	{
		pivot_b(swap);
		if (swap->cap_len < 0)
			return;
		else if (swap->cap_len - (swap->cap_len - 1) <= 0)
				swap->swap_len = swap->cap[swap->cap_len];
		else if (swap->cap_len == 0)
			swap->swap_len = swap->cap[swap->cap_len];
		else
			swap->swap_len = swap->cap[swap->cap_len] -
					swap->cap[swap->cap_len - 1];
		sort_stack_b(swap);
		swap->cap_len--;
		if (check_sort(swap) == 1)
			break;
	}
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