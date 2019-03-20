#include "push_swap.h"

int 	sort_stack_1(t_swap *swap)
{
	if (swap->rec == 4)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot &&
		swap->stack_a[swap->top_a + 1] < swap->pivot)
		{
			pb(swap);
			pb(swap);
			swap->rec = swap->rec - 2;
			swap->cap_len++;
			swap->cap[swap->cap_len] = swap->cap[swap->cap_len - 1] + 2;
			return (1);
		}
	}
	return (0);
}

static	void	sort_stack_a_next(t_swap *swap)
{
	int i;
	int j;

	i = -1;
	j = swap->check_len;
	if (sort_stack_1(swap) == 1)
		return;
	while (++i < j)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
		{
			pb(swap);
			swap->check_a++;
			swap->rec--;
		}
		else
		{
			if (i + 1 == j)
				break;
			ra(swap);
			swap->flag++;
		}
	}
		while(swap->flag != 0)
	{
		rra(swap);
		swap->flag--;
	}
	swap->cap_len++;
	swap->cap[swap->cap_len] = swap->cap[swap->cap_len - 1] + swap->check_a;
}

void			sort_stack_a(t_swap *swap)
{
	while (1)
	{
		swap->check_a = 0;
		swap->check_len = swap->rec;
		if (swap->check_len <= 3)
		{
			if (swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1] == 2)
				{
					swap_stack_a(swap);
					pa(swap);
					pa(swap);
					swap_stack_a(swap);
					swap->cap[swap->cap_len] = swap->cap[swap->cap_len] - 2;
					return;
				}
			if (check_sort(swap) == 0)
				return;
			swap_stack_a(swap);
			return;
			}
		else
		{
			pivot_a(swap);
			sort_stack_a_next(swap);
		}
	}
}

static	int	check_min_elem(t_swap *swap)
{
	if (swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1] == 2)
	{
		if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
			sb(swap);
		pa(swap);
		pa(swap);
		swap->cap[swap->cap_len] = swap->cap[swap->cap_len] - 2;
		return (1);
	}
	return (0);
}

int	check_elems_down(t_swap *swap)
{
	int i;
	int j;

	j = 0;
	i = swap->top_b;
	while (j < swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1])
	{
		if (swap->stack_b[i] >= swap->pivot)
			return (1);
		i++;
		j++;
	}
	return (0);
}

void			sort_stack_b_2(t_swap *swap)
{
	if (swap->stack_b[swap->top_b] >= swap->pivot)
	{
		pa(swap);
		swap->rec++;
	}
	else
	{
		rb(swap);
		swap->check++;
	}
}

void			sort_stack_b(t_swap *swap)
{
	int i;
	int flag;

	flag = 1;
	while (swap->cap[swap->cap_len] > swap->cap[swap->cap_len - 1])
	{
		if (check_min_elem(swap) == 1)
			return;
		swap->rec = 0;
		pivot_b_test(swap);
		i = -1;
		while (++i < swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1])
		{
			if (check_elems_down(swap) == 0)
				break;
			sort_stack_b_2(swap);
		}
		swap->cap[swap->cap_len] = swap->cap[swap->cap_len] - swap->rec;
		while (swap->check)
		{
			if (swap->cap_len == 2 && flag == 1)
			{
				swap->check = 0;
				flag = 0;
				break;
			}
			rrb(swap);
			swap->check--;
		}
		sort_stack_a(swap);
	}
}

void			quick_sort(t_swap *swap)
{
	while (1)
	{
//		swap_stack_b(swap);
		swap->check = 0;
		pivot_b(swap);

		if (swap->cap_len < 0)
			return;
		sort_stack_b(swap);
		swap->cap_len--;
		if (check_sort(swap) == 1)
			break;
		sort_print(swap);
//		printf("-----------------\n");
	}
}
