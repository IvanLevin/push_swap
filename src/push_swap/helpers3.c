/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:45:33 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 14:45:37 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		check_splitted_a(t_swap *swap)
{
	int i;

	i = swap->top_a;
	while (i < swap->len - swap->sorted)
	{
		if (swap->stack_a[i] < swap->pivot)
			return (0);
		else
			i++;
	}
	return (1);
}

int		check_elems_down_a(t_swap *swap)
{
	int i;

	i = swap->top_a;
	while (i < swap->len - swap->sorted)
	{
		if (swap->stack_a[i] < swap->pivot)
			return (1);
		i++;
	}
	return (0);
}

void	put_b(t_swap *swap)
{
	while (check_splitted_a(swap) == 0)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
			pb(swap);
		else
		{
			ra(swap);
			swap->unsorted++;
		}
	}
	while (swap->unsorted)
	{
		rra(swap);
		swap->unsorted--;
	}
	swap->uns_mas[swap->temp] = swap->len - swap->top_b;
}

int		b_del(t_swap *swap)
{
	if (swap->sorted == swap->len)
		return (1);
	if (swap->temp == 2)
		split_stacks_toa2(swap);
	split_stacks_toa(swap);
	sort_a(swap);
	return (0);
}

void	split_stack_b(t_swap *swap)
{
	new_pivot_b(swap);
	while (1)
	{
		if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] == 3)
			sort_toa3(swap);
		if (swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1] <= 4)
			sort_toa(swap);
		new_pivot_b(swap);
		if (b_del(swap) == 1)
			break ;
	}
}
