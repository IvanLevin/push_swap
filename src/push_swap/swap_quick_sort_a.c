/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_quick_sort_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:11:23 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:05:43 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int				check_min_elem(t_swap *swap)
{
	if (swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1] == 2)
	{
		if (swap->stack_b[swap->top_b] < swap->stack_b[swap->top_b + 1])
			sb(swap);
		pa(swap);
		pa(swap);
		swap->cap[swap->cap_len] = swap->cap[swap->cap_len] - 2;
		return (1);
	}
	return (0);
}

int				sort_stack_1(t_swap *swap)
{
	if (swap->rec == 4)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot &&
				swap->stack_a[swap->top_a + 1] < swap->pivot)
		{
			pb(swap);
			pb(swap);
			swap->rec = swap->rec - 2;
			swap->cap_len++;
			swap->cap[swap->cap_len] = swap->cap[swap->cap_len - 1] + 2;
			return (1);
		}
	}
	return (0);
}

static	void	sort_stack_a_2(t_swap *swap)
{
	while (swap->flag != 0)
	{
		rra(swap);
		swap->flag--;
	}
	swap->cap_len++;
	swap->cap[swap->cap_len] = swap->cap[swap->cap_len - 1] + swap->check_a;
}

static	void	sort_stack_a_next(t_swap *swap)
{
	int		i;
	int		j;

	i = -1;
	j = swap->check_len;
	if (sort_stack_1(swap) == 1)
		return ;
	while (++i < j)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
		{
			pb(swap);
			swap->check_a++;
			swap->rec--;
		}
		else
		{
			if (i + 1 == j)
				break ;
			ra(swap);
			swap->flag++;
		}
	}
	sort_stack_a_2(swap);
}

void			sort_stack_a(t_swap *swap)
{
	while (1)
	{
		swap->check_a = 0;
		swap->check_len = swap->rec;
		if (swap->check_len <= 3)
		{
			if (swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1] == 2)
			{
				swap_stack_a(swap);
				pa(swap);
				pa(swap);
				swap_stack_a(swap);
				swap->cap[swap->cap_len] = swap->cap[swap->cap_len] - 2;
				return ;
			}
			swap_stack_a(swap);
			return ;
		}
		else
		{
			pivot_a(swap);
			sort_stack_a_next(swap);
		}
	}
}
