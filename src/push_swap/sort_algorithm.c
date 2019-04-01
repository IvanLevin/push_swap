/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:57:01 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 14:57:03 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		sort_insert(t_swap *swap)
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
}

void		sort_min3(t_swap *swap)
{
	rra(swap);
	sa(swap);
}

void		sort_min2(t_swap *swap)
{
	ra(swap);
	sa(swap);
}

void		sort_min(t_swap *swap)
{
	if (swap->len - swap->top_a == 2)
	{
		if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			sa(swap);
	}
	else if (swap->len == 2 || \
		(swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] \
			&& swap->stack_a[swap->top_a] < swap->stack_a[swap->len - 1]))
		sa(swap);
	else if (swap->stack_a[swap->top_a] < swap->stack_a[swap->top_a + 1] \
		&& swap->stack_a[swap->top_a] > swap->stack_a[swap->len - 1])
		rra(swap);
	else if (swap->stack_a[swap->top_a] < swap->stack_a[swap->top_a + 1] \
		&& swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->len - 1])
		sort_min3(swap);
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] \
		&& swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->len - 1])
		sort_min2(swap);
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->len - 1] && \
		swap->stack_a[swap->len - 1] > swap->stack_a[swap->top_a + 1])
		ra(swap);
	swap->sorted = swap->len - swap->top_a;
}

void		algorithm_sort(t_swap *swap)
{
	if (!check_sort(swap))
		return ;
	if (swap->len == 1)
		return ;
	else if (swap->len < 4)
		sort_min(swap);
	else if (swap->len == 4)
		sort_insert(swap);
	swap->pivot = swap_pivot(swap);
	swap_quick_sort(swap);
	ft_strcpy(swap->cmnd[swap->temp_cmd], "end");
}
