/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:08:03 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/26 18:24:52 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int		swap_pivot(t_swap *swap)
{
	int		*sort;
	int		i;

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
	int	i;

	i = swap->top_a;
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
}

void	algorithm_sort(t_swap *swap)
{
	if (!(check_sort(swap)))
		return ;
	if (swap->len == 1)
		return ;
	else if (swap->len < 4)
		sort_min(swap);
	else if (swap->len == 4)
		sort_insert(swap);
	else
	{
		swap->pivot = swap_pivot(swap);
		swap_quick_sort(swap);
	}
}

int		swap_quick_sort(t_swap *swap)
{
	int	i;

	i = 2;
	while (3 < swap->len - swap->len_b)
	{
		put_stack_b(swap);
		new_pivot_a(swap);
		swap->cap[i++] = swap->len_b;
	}
	swap->cap_len = i - 1;
	sort_min(swap);
	quick_sort(swap);
	return (0);
}
