/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:08:51 by breolson          #+#    #+#             */
/*   Updated: 2019/03/29 21:08:52 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_toa_3(t_swap *swap)
{
	if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
	{
		sb(swap);
		pa(swap);
		pa(swap);
	}
	else
	{
		pa(swap);
		pa(swap);
	}
}

void	sort_toa_2(t_swap *swap, int i)
{
	while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
	{
		find_max_min(swap);
		if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] == 2)
		{
			sort_toa_3(swap);
			break ;
		}
		else if (swap->stack_b[swap->top_b] == swap->max)
		{
			pa(swap);
			i++;
		}
		else if (swap->stack_b[swap->top_b] == swap->min)
		{
			pa(swap);
			ra(swap);
			swap->unsorted++;
			i++;
		}
		else
			sb(swap);
	}
}

void	sort4(t_swap *swap, int *flag)
{
	new_pivot_b(swap);
	b_del(swap);
	sort_toa2(swap);
	flag[0] = 1;
}

void	sort_toa(t_swap *swap)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] == 4)
		sort4(swap, &flag);
	if (flag == 0)
		sort_toa_2(swap, i);
	while (swap->unsorted)
	{
		rra(swap);
		swap->unsorted--;
	}
	while (check_sorted(swap) == 0)
		ra(swap);
	swap->temp--;
	swap->sorted = swap->len - swap->top_a;
}
