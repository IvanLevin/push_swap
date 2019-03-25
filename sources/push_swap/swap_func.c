/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:09:47 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 18:17:03 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_stack_a_2(t_swap *swap)
{
	if (swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a] &&
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
		sa(swap);
	else if (swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a] &&
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2])
	{
		ra(swap);
		sa(swap);
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1])
		sa(swap);
}

void	sort_min_2(t_swap *swap)
{
	if (swap->len_a != 2 && (swap->stack_a[swap->top_a] >
	swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2]))
	{
		ra(swap);
		sa(swap);
	}
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] >
	swap->stack_a[swap->top_a + 2] && \
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a + 1]))
		ra(swap);
}

void	sort_min(t_swap *swap)
{
	if ((swap->len_a == 2 && swap->stack_a[swap->top_a] >
	swap->stack_a[swap->top_a + 1]) || (swap->stack_a[swap->top_a] >
	swap->stack_a[swap->top_a + 1] && swap->stack_a[swap->top_a] <
	swap->stack_a[swap->top_a + 2]))
		sa(swap);
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] <
	swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2]))
		rra(swap);
	else if (swap->len_a != 2 && (swap->stack_a[swap->top_a] <
	swap->stack_a[swap->top_a + 1] && \
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2]))
	{
		rra(swap);
		sa(swap);
	}
	sort_min_2(swap);
}

void	swap_stack_a(t_swap *swap)
{
	if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 1] &&
	swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2])
	{
		sa(swap);
		ra(swap);
		sa(swap);
		rra(swap);
		sa(swap);
	}
	else if (swap->stack_a[swap->top_a] > swap->stack_a[swap->top_a + 2] &&
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a + 1])
	{
		sa(swap);
		ra(swap);
		sa(swap);
		rra(swap);
	}
	else if (swap->stack_a[swap->top_a + 1] > swap->stack_a[swap->top_a + 2] &&
	swap->stack_a[swap->top_a + 2] > swap->stack_a[swap->top_a])
	{
		ra(swap);
		sa(swap);
		rra(swap);
	}
	swap_stack_a_2(swap);
}
