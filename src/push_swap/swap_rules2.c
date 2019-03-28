/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:25:14 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 18:25:17 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void		ra(t_swap *sw_a)
{
	int		i;
	int		temp;

	i = sw_a->top_a;
	temp = sw_a->stack_a[i];
	while (sw_a->len - 1 > i)
	{
		sw_a->stack_a[i] = sw_a->stack_a[i + 1];
		i++;
	}
	sw_a->stack_a[i] = temp;
	sw_a->score++;
	if (sw_a->checker == 0)
		ft_printf("ra\n");
	if (sw_a->flag_v == 1)
		print_stacks(sw_a);
}

void		rb(t_swap *sw_b)
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
		print_stacks(sw_b);
}

void		rr(t_swap *swap)
{
	int		i;
	int		j;
	int		temp1;
	int		temp2;

	i = swap->top_a;
	j = swap->top_b;
	temp1 = swap->stack_a[i];
	temp2 = swap->stack_b[j];
	while (swap->len - 1 > i)
	{
		swap->stack_a[i] = swap->stack_a[i + 1];
		i++;
	}
	while (swap->len - 1 > j)
	{
		swap->stack_b[j] = swap->stack_b[j + 1];
		j++;
	}
	swap->stack_a[i] = temp1;
	swap->stack_b[j] = temp2;
	swap->score++;
	if (swap->checker == 0)
		ft_printf("rr\n");
	if (swap->flag_v == 1)
		print_stacks(swap);
}

void		rra(t_swap *sw_a)
{
	int i;
	int temp;

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
		print_stacks(sw_a);
}
