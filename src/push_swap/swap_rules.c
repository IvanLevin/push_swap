/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:23:44 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 18:23:50 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		sa(t_swap *sw_a)
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
	ft_strcpy(sw_a->cmnd[sw_a->temp_cmd++], "sa");
}

void		sb(t_swap *sw_b)
{
	int		i;
	int		temp;

	if (sw_b->len - sw_b->top_b <= 1)
		return ;
	i = sw_b->top_b;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
	sw_b->score++;
	ft_strcpy(sw_b->cmnd[sw_b->temp_cmd++], "sb");
}

void		ss(t_swap *swap)
{
	int		i;
	int		temp;

	if (swap->len - swap->top_a <= 1)
		return ;
	if (swap->len - swap->top_b <= 1)
		return ;
	i = 0;
	temp = swap->stack_a[i + 1];
	swap->stack_a[i + 1] = swap->stack_a[i];
	swap->stack_a[i] = temp;
	temp = swap->stack_b[i + 1];
	swap->stack_b[i + 1] = swap->stack_b[i];
	swap->stack_b[i] = temp;
	swap->score++;
	ft_strcpy(swap->cmnd[swap->temp_cmd++], "ss");
}

void		pa(t_swap *swap)
{
	if (swap->len - swap->top_b == 0)
		return ;
	swap->top_a--;
	swap->stack_a[swap->top_a] = swap->stack_b[swap->top_b];
	swap->score++;
	swap->top_b++;
	ft_strcpy(swap->cmnd[swap->temp_cmd++], "pa");
	if (swap->flag_v == 1)
		print_stacks(swap);
}

void		pb(t_swap *swap)
{
	if (swap->len - swap->top_a <= 0)
		return ;
	swap->stack_b[swap->top_b - 1] = swap->stack_a[swap->top_a];
	swap->score++;
	swap->top_a++;
	swap->top_b--;
	ft_strcpy(swap->cmnd[swap->temp_cmd++], "pb");
}
