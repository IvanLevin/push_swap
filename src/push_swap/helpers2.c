/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:37:54 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 14:37:58 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void		sort_a(t_swap *swap)
{
	int i;

	i = swap->top_a;
	if (swap->len - swap->top_a - swap->sorted == 2)
	{
		if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
			sa(swap);
	}
	else if (swap->stack_a[i] > swap->stack_a[i + 1] && \
		swap->stack_a[i] < swap->stack_a[i + 2])
		sa(swap);
	else if (swap->stack_a[i] > swap->stack_a[i + 1] && \
		swap->stack_a[i] > swap->stack_a[i + 2])
	{
		if (swap->stack_a[i + 1] > swap->stack_a[i + 2])
		{
			sa(swap);
			ra(swap);
			sa(swap);
			rra(swap);
			sa(swap);
		}
		else
		{
			pb(swap);
			ra(swap);
			pa(swap);
			sa(swap);
			rra(swap);
		}
	}
	else if (swap->stack_a[i] < swap->stack_a[i + 1] && \
		swap->stack_a[i] > swap->stack_a[i + 2])
	{
		if (swap->stack_a[i + 1] > swap->stack_a[i + 2])
		{
			ra(swap);
			sa(swap);
			rra(swap);
			sa(swap);
		}
	}
	else if (swap->stack_a[i] < swap->stack_a[i + 1] && \
		swap->stack_a[i] < swap->stack_a[i + 2])
	{
		if (swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2])
		{
			pb(swap);
			sa(swap);
			pa(swap);
		}
	}
	swap->sorted = swap->len - swap->top_a;
}

int			check_sorted(t_swap *swap)
{
	int i;

	i = swap->top_a;
	while (i < swap->len - 1)
	{
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int			num_of_covers(t_swap *swap)
{
	int i;
	int j;

	j = 0;
	i = swap->len;
	while (i > 3)
	{
		i /= 2;
		j++;
	}
	return (j * 2);
}
