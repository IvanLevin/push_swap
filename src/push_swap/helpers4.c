/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:00:08 by breolson          #+#    #+#             */
/*   Updated: 2019/03/29 21:00:13 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_toa2(t_swap *swap)
{
	int i;

	i = 0;
	while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
	{
		find_max_min(swap);
		if (swap->stack_b[swap->top_b] == swap->max)
		{
			pa(swap);
			i++;
		}
		else if (swap->stack_b[swap->top_b] == swap->min)
		{
			pa(swap);
			ra(swap);
			i++;
		}
		else
			sb(swap);
	}
	while (check_sorted(swap) == 0)
		rra(swap);
	swap->sorted = swap->len - swap->top_a;
}

void	sort_toa3_4(t_swap *swap)
{
	sb(swap);
	pa(swap);
	pa(swap);
	pa(swap);
}

void	sort_toa3_3(t_swap *swap, int i)
{
	if (swap->stack_b[i + 1] > swap->stack_b[i + 2])
	{
		pa(swap);
		pa(swap);
		pa(swap);
	}
	else
	{
		pa(swap);
		sb(swap);
		pa(swap);
		pa(swap);
	}
}

void	sort_toa3_2(t_swap *swap, int i)
{
	if (swap->stack_b[i + 1] > swap->stack_b[i + 2])
	{
		sb(swap);
		pa(swap);
		sb(swap);
		pa(swap);
		pa(swap);
	}
	else
	{
		pa(swap);
		sb(swap);
		pa(swap);
		sa(swap);
		pa(swap);
		sa(swap);
	}
}

void	sort_toa3(t_swap *swap)
{
	int i;

	i = swap->top_b;
	if (swap->stack_b[i] > swap->stack_b[i + 1] && \
		swap->stack_b[i] < swap->stack_b[i + 2])
	{
		pa(swap);
		sb(swap);
		pa(swap);
		sa(swap);
		pa(swap);
	}
	else if (swap->stack_b[i] < swap->stack_b[i + 1] && \
		swap->stack_b[i] < swap->stack_b[i + 2])
		sort_toa3_2(swap, i);
	else if (swap->stack_b[i] > swap->stack_b[i + 1] && \
		swap->stack_b[i] > swap->stack_b[i + 2])
		sort_toa3_3(swap, i);
	else if (swap->stack_b[i] < swap->stack_b[i + 1] && \
		swap->stack_b[i] > swap->stack_b[i + 2])
		sort_toa3_4(swap);
	swap->temp--;
	swap->sorted = swap->len - swap->top_a;
}
