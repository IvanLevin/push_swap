/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:30:15 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 18:30:16 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		rrr(t_swap *sw_a, t_swap *sw_b)
{
	int		i;
	int		temp;

	i = 1;
	temp = sw_a->stack_a[sw_a->len - 1];
	while (sw_a->len > i)
	{
		sw_a->stack_a[sw_a->len - i] = sw_a->stack_a[sw_a->len - i - 1];
		i++;
	}
	sw_a->stack_a[sw_a->len - i] = temp;
	i = 1;
	temp = sw_b->stack_b[sw_b->len - 1];
	while (sw_b->len > i)
	{
		sw_b->stack_b[sw_b->len - i] = sw_b->stack_a[sw_b->len - i - 1];
		i++;
	}
	sw_b->stack_b[sw_b->len - i] = temp;
	sw_a->score++;
	ft_strcpy(sw_a->cmnd[sw_a->temp_cmd++], "rrr");
}

void		rrb(t_swap *sw_b)
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
	sw_b->stack_b[sw_b->top_b] = temp;
	sw_b->score++;
	ft_strcpy(sw_b->cmnd[sw_b->temp_cmd++], "rrb");
}
