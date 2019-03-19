#include "push_swap.h"

void	sort_min(t_swap *swap)
{
	if ((swap->len_a == 2 && swap->stack_a[swap->top_a] >
			swap->stack_a[swap->top_a + 1]) || (swap->stack_a[swap->top_a] >
			swap->stack_a[swap->top_a + 1] && swap->stack_a[swap->top_a] <
			swap->stack_a[swap->top_a + 2]))
		sa(swap);
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] <
				swap->stack_a[swap->top_a +	1] && \
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2]))
		rra(swap);
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] <
	swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2]))
	{
		rra(swap);
		sa(swap);
	}
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] >
	swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2]))
	{
		ra(swap);
		sa(swap);
	}
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] >
	swap->stack_a[swap->top_a + 2] && \
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a + 1]))
		ra(swap);
}

void	swap_stack_a(t_swap *swap)
{
	if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] &&
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2])
	{
		sa(swap);
		ra(swap);
		sa(swap);
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2] &&
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a + 1])
	{
		sa(swap);
		ra(swap);
		sa(swap);
		rra(swap);
	}
	else if (swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2] &&
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a])
	{
		ra(swap);
		sa(swap);
		rra(swap);
	}
	else if (swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a] &&
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
		sa(swap);
	else if (swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a] &&
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2])
	{
		ra(swap);
		sa(swap);
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			sa(swap);
}

void	swap_stack_b(t_swap *swap)
{
	if (swap->stack_b[swap->top_b] > swap->stack_b[swap->top_b + 1] &&
	swap->stack_b[swap->top_b + 1] > swap->stack_b[swap->top_b + 2])
	{
		sb(swap);
		rb(swap);
		sb(swap);
		rrb(swap);
		sb(swap);
	}
	else if (swap->stack_b[swap->top_b] > swap->stack_b[swap->top_b + 2] &&
	swap->stack_b[swap->top_b + 2] > swap->stack_b[swap->top_b + 1])
	{
		sb(swap);
		rb(swap);
		sb(swap);
		rrb(swap);
	}
	else if (swap->stack_b[swap->top_b + 1] > swap->stack_b[swap->top_b + 2] &&
	swap->stack_b[swap->top_b + 2] > swap->stack_b[swap->top_b])
	{
		rb(swap);
		sb(swap);
		rrb(swap);
	}
	else if (swap->stack_b[swap->top_b + 2] > swap->stack_b[swap->top_b] &&
	swap->stack_b[swap->top_b] > swap->stack_b[swap->top_b + 1])
		sb(swap);
	else if (swap->stack_b[swap->top_b + 1] > swap->stack_b[swap->top_b] &&
	swap->stack_b[swap->top_b] > swap->stack_b[swap->top_b + 2])
	{
		rb(swap);
		sb(swap);
		rrb(swap);
		sb(swap);
	}
	else if (swap->stack_b[swap->top_b] > swap->stack_b[swap->top_b + 1])
		sb(swap);
}