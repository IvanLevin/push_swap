#include "push_swap.h"

static	int		check_sort(t_swap *swap)
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
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			sa(swap);
		else if (swap->stack_a[i] < swap->stack_a[i + 1] && \
		swap->stack_a[i] > swap->stack_a[swap->len - 1])
			rra(swap);
		else
			ra(swap);
	}
	i = 0;
	while (swap->stack_a[i])
		ft_printf("%d ", swap->stack_a[i++]);
}

void	sort_min(t_swap *swap)
{
	if (swap->len == 2 || (swap->stack_a[0] > swap->stack_a[1] && \
	swap->stack_a[0] < swap->stack_a[2]))
		sa(swap);
	else if (swap->stack_a[0] < swap->stack_a[1] && \
	swap->stack_a[0] > swap->stack_a[2])
		rra(swap);
	else if (swap->stack_a[0] < swap->stack_a[1] && \
	swap->stack_a[1] > swap->stack_a[2])
	{
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[0] > swap->stack_a[1] && \
	swap->stack_a[1] > swap->stack_a[2])
	{
		ra(swap);
		sa(swap);
	}
	else if (swap->stack_a[0] > swap->stack_a[2] && \
	swap->stack_a[2] > swap->stack_a[1])
		ra(swap);
}

void 			algorithm_sort(t_swap *swap)
{
	int		*sort;
	int		pivot;


	if (!check_sort(swap)) // Проверка, если все пришло отсортированное
		return;
	if (swap->len == 1) // Проверка на 1 значение
		return;
	else if (swap->len < 4) // Простая сортировка 2 или 3 значений
		sort_min(swap);
	else if (swap->len == 4)
		sort_insert(swap);
	sort = ft_selection_sort(swap->stack_a);
	swap->pivot = (0 + swap->len) / 2;
}
