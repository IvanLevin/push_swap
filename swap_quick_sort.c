/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:10:53 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 17:24:05 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_elems_down(t_swap *swap)
{
	int		i;
	int		j;

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

void		sort_stack_b_2(t_swap *swap)
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

void		sort_stack_b_next(t_swap *swap, int flag)
{
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

void		sort_stack_b(t_swap *swap)
{
	int		i;
	int		flag;

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
		sort_stack_b_next(swap, flag);
	}
}

void		quick_sort(t_swap *swap)
{
	while (1)
	{
		swap->check = 0;
		pivot_b(swap);

		if (swap->cap_len < 0)
			return;
		sort_stack_b(swap);
		swap->cap_len--;
		if (check_sort(swap) == 1)
			break;
		sort_print(swap);
	}
}
