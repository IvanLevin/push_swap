/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:20:43 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 18:20:48 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	find_max_min(t_swap *swap)
{
	int i;

	i = 0;
	swap->min = swap->stack_b[swap->top_b];
	swap->max = swap->stack_b[swap->top_b];
	while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
	{
		if (swap->stack_b[i + swap->top_b] < swap->min)
			swap->min = swap->stack_b[i + swap->top_b];
		if (swap->stack_b[i + swap->top_b] > swap->max)
			swap->max = swap->stack_b[i + swap->top_b];
		i++;
	}
}

int		swap_quick_sort(t_swap *swap)
{
	while (swap->top_a <= swap->len - 3)
	{
		split_stacks_tob(swap);
		new_pivot(swap);
	}
	sort_min(swap);
	swap->temp--;
	split_stack_b(swap);
	return (0);
}
