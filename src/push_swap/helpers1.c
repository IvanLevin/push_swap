/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:27:34 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 14:27:37 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			split_stacks_tob(t_swap *swap)
{
	while (check_splitted(swap) == 0)
	{
		if (swap->stack_a[swap->top_a] <= swap->pivot)
		{
			pb(swap);
		}
		else
			ra(swap);
	}
	swap->uns_mas[swap->temp] = swap->len - swap->top_b;
	swap->temp++;
	return (0);
}

int			check_splitted(t_swap *swap)
{
	int		i;

	i = swap->top_a;
	while (i < swap->len)
	{
		if (swap->stack_a[i] <= swap->pivot)
			return (0);
		else
			i++;
	}
	return (1);
}

int			check_elems_down(t_swap *swap, int i)
{
	i = swap->top_b;
	while (i < swap->len - swap->uns_mas[swap->temp - 1])
	{
		if (swap->stack_b[i] >= swap->pivot)
			return (1);
		i++;
	}
	return (0);
}

int			split_stacks_toa2(t_swap *swap)
{
	int		i;

	i = 0;
	while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
	{
		if (check_elems_down(swap, i) == 0)
			break ;
		if (swap->stack_b[swap->top_b] >= swap->pivot)
			pa(swap);
		else
		{
			rb(swap);
		}
		i++;
	}
	swap->uns_mas[swap->temp] = swap->len - swap->top_b;
	while (swap->len - swap->sorted - swap->top_a > 3)
	{
		new_pivot_a(swap);
		swap->temp++;
		put_b(swap);
	}
	return (0);
}

void		split_stacks_toa_add(t_swap *swap)
{
	while (swap->len - swap->sorted - swap->top_a > 3)
	{
		new_pivot_a(swap);
		swap->temp++;
		put_b(swap);
	}
}
