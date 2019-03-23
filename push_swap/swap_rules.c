/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:15:22 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 18:17:03 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_swap *sw_a)
{
	int		i;
	int		temp;

	i = sw_a->top_a;
	if (sw_a->len - sw_a->top_a <= 1)
		return ;
	temp = sw_a->stack_a[i + 1];
	sw_a->stack_a[i + 1] = sw_a->stack_a[i];
	sw_a->stack_a[i] = temp;
	sw_a->score++;
	ft_printf("sa\n");
}

void	sb(t_swap *sw_b)
{
	int		i;
	int		temp;

	i = sw_b->top_b;
	if (sw_b->len - sw_b->top_b <= 1)
		return ;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
	sw_b->score++;
	ft_printf("sb\n");
}

void	pa(t_swap *swap)
{
	if (swap->len - swap->top_b == 0)
		return ;
	swap->top_a--;
	swap->stack_a[swap->top_a] = swap->stack_b[swap->top_b];
	swap->score++;
	swap->top_b++;
	swap->len_b--;
	swap->len_a++;
	ft_printf("pa\n");
}

void	pb(t_swap *swap)
{
	if (swap->len - swap->top_a <= 0)
		return ;
	swap->stack_b[swap->top_b - 1] = swap->stack_a[swap->top_a];
	swap->score++;
	swap->top_a++;
	swap->top_b--;
	swap->len_b++;
	swap->len_a--;
	ft_printf("pb\n");
}

void	ra(t_swap *sw_a)
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
	ft_printf("ra\n");
}
