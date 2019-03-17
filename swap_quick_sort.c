#include "push_swap.h"

static	void	sort_stack_a_next(t_swap *swap, int swap_len)
{
	int i;

	i = -1;
	while (++i < swap_len && check_sort(swap) == 1)
	{
		if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			sa(swap);
		if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
			sb(swap);
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
			swap->flag++;
		}

		sort_print(swap);
	}
	while(swap->flag != 0)
	{
		rra(swap);
		if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			sa(swap);
		swap->flag--;
		sort_print(swap);
	}
}



void			sort_stack_a(t_swap *swap, int swap_len)
{
	int i;

	i = 0;
	if (swap_len <= 3)
	{
		if (check_sort(swap) == 0)
			return;
		swap_stack_a(swap);
		sort_print(swap);
		return;
	}
	swap->flag = 0;
	pivot_a(swap);
	sort_stack_a_next(swap, swap_len);
	if (swap->check_a - swap->top_a <= 3 && check_sort(swap) == 1)
		swap_stack_a(swap);
	else if (swap->check_a - swap->top_a > 3 && check_sort(swap) == 1)
	{
		sort_stack_a(swap, swap->check_a - swap->top_a);
		swap->rec = 0;
	}
	if (swap->rec)
	{
		while (swap->rec > i)
		{
			if (!(check_sort_b(swap)))
			{
				while (swap->rec)
				{
					swap_stack_a(swap);
					pa(swap);
					swap->rec--;
					sort_print(swap);
				}
				swap_stack_a(swap);
				return;
			}
		}
		swap->swap_len = swap->rec;
		pivot_b_test(swap);
		sort_stack_b(swap);
	}
}

static	void	sort_stack_b_next(t_swap *swap)
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
		swap_stack_b(swap);
		rb(swap);
		swap->check++;
	}
}

void			sort_stack_b(t_swap *swap)
{
	int 	i;

	i = 0;
	swap->check = 0;
	swap->check_a = swap->top_a;
	while (i < swap->swap_len)
	{
		sort_stack_b_next(swap);
		sort_print(swap);
		//swap_stack_b(swap);
		i++;
	}
	if (swap->check != 0)
		while (swap->check)
		{
			rrb(swap);
			if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
				sb(swap);
			pa(swap);
			if (swap->rec)
				swap->rec--;
			swap->check--;
			sort_print(swap);
		}
	sort_stack_a(swap, swap->swap_len);
	swap->rec = 0;
}

void			quick_sort(t_swap *swap)
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
