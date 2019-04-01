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

#include <push_swap.h>

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
	ft_strcpy(sw_a->cmnd[sw_a->temp_cmd++], "ra");
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
	ft_strcpy(sw_b->cmnd[sw_b->temp_cmd++], "rb");
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
	while (swap->len - 1 > j++)
		swap->stack_b[j] = swap->stack_b[j + 1];
	swap->stack_a[i] = temp1;
	swap->stack_b[j] = temp2;
	swap->score++;
	ft_strcpy(swap->cmnd[swap->temp_cmd++], "rr");
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
	ft_strcpy(sw_a->cmnd[sw_a->temp_cmd++], "rra");
}
