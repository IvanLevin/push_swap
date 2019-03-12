#include "push_swap.h"

int 	swap_pivot(t_swap *swap)
{
	int		*sort;
	int 	i;


	sort = (int *)malloc(sizeof(int) * swap->len);
	i = 0;
	while (i < swap->len)
	{
		sort[i] = swap->stack_a[i];
		i++;
	}
	sort = ft_selection_sort(sort, swap->len);
	swap->pivot = (0 + swap->len) / 2;
	return (sort[swap->pivot]);
}

int		check_sort(t_swap *swap)
{
	int i;

	i = 0;
	while (i < swap->len - 1)
	{
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort_insert(t_swap *swap)
{
	int	i;

	i = 0;

	while (check_sort(swap) == 1)
	{
		if (swap->stack_a[0] < swap->stack_a[1] && swap->stack_a[0] < \
		swap->stack_a[3] && swap->stack_a[3] > swap->stack_a[1])
			ra(swap);
		else if (swap->stack_a[0] > swap->stack_a[1])
			sa(swap);
		else if (swap->stack_a[2] < swap->stack_a[3] || (swap->stack_a[0] < \
		swap->stack_a[1] && swap->stack_a[1] < swap->stack_a[2] && \
        swap->stack_a[0] > swap->stack_a[3]))
			rra(swap);
		else if (swap->stack_a[0] > swap->stack_a[3] || \
		swap->stack_a[2] > swap->stack_a[3])
			ra(swap);
	}
	while (i < 4)
		ft_printf(TURQUOISE"%d ", swap->stack_a[i++]);
	printf(GREEN"\nSCORE = %d", swap->score);
}

void	sort_min(t_swap *swap)
{
	if (swap->len == 2 || (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a] < swap->stack_a[swap->len - 1]))
		sa(swap);
	else if (swap->stack_a[swap->top_a] < swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a] > swap->stack_a[swap->len - 1])
		rra(swap);
	else if (swap->stack_a[swap->top_a] < swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->len - 1])
	{
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->len - 1])
	{
		ra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->len - 1] && \
	swap->stack_a[swap->len - 1] > swap->stack_a[swap->top_a + 1])
		ra(swap);
}

void 			algorithm_sort(t_swap *swap)
{
	if (!check_sort(swap)) // Проверка, если все пришло отсортированное
		return;
	if (swap->len == 1) // Проверка на 1 значение
		return;
	else if (swap->len < 4) // Простая сортировка 2 или 3 значений
		sort_min(swap);
	else if (swap->len == 4)
		sort_insert(swap);
	swap->pivot = swap_pivot(swap);
	swap_quick_sort(swap);
}
