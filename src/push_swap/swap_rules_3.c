/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:33:36 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/26 16:08:58 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rb(t_swap *sw_b)
{
	int		i;
	int		temp;

	i = sw_b->top_b;
	temp = sw_b->stack_b[i];
	while (sw_b->len - 1 > i)
	{
		sw_b->stack_b[i] = sw_b->stack_b[i + 1];
		i++;
	}
	sw_b->stack_b[i] = temp;
	sw_b->score++;
	if (sw_b->checker == 0)
		ft_printf("rb\n");
	if (sw_b->flag_v == 1)
		sort_print(sw_b);
}

void	rra(t_swap *sw_a)
{
	int		i;
	int		temp;

	i = 1;
	temp = sw_a->stack_a[sw_a->len - 1];
	while (sw_a->len - sw_a->top_a > i)
	{
		sw_a->stack_a[sw_a->len - i] = sw_a->stack_a[sw_a->len - i - 1];
		i++;
	}
	sw_a->stack_a[sw_a->len - i] = temp;
	sw_a->score++;
	if (sw_a->checker == 0)
		ft_printf("rra\n");
	if (sw_a->flag_v == 1)
		sort_print(sw_a);
}

void	rrb(t_swap *sw_b)
{
	int		i;
	int		temp;

	i = 1;
	temp = sw_b->stack_b[sw_b->len - 1];
	while (sw_b->len - sw_b->top_b > i)
	{
		sw_b->stack_b[sw_b->len - i] = sw_b->stack_b[sw_b->len - i - 1];
		i++;
	}
	sw_b->stack_b[sw_b->len - i] = temp;
	sw_b->score++;
	if (sw_b->checker == 0)
		ft_printf("rrb\n");
	if (sw_b->flag_v == 1)
		sort_print(sw_b);
}
