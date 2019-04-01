/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:17:48 by breolson          #+#    #+#             */
/*   Updated: 2019/03/29 23:17:49 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void		print_stacks(t_swap *swap)
{
	int i;

	i = 0;
	while (i < swap->len)
	{
		if (i < swap->top_a && i < swap->top_b)
			ft_printf("	 _	  _\n");
		else if (i < swap->top_a && i >= swap->top_b)
			ft_printf("	 _	  %d\n", swap->stack_b[i]);
		else if (i >= swap->top_a && i < swap->top_b)
			ft_printf("   %-7d _\n", swap->stack_a[i]);
		else
			ft_printf("   %-7d %d\n", swap->stack_a[i], swap->stack_b[i]);
		i++;
	}
}

void		new_pivot_b(t_swap *swap)
{
	int *sort;
	int i;
	int j;

	j = 0;
	sort = NULL;
	if (swap->temp > 0)
	sort = (int *)malloc(sizeof(int) * (swap->uns_mas[swap->temp] - \
		swap->uns_mas[swap->temp - 1]));
	i = swap->top_b;
	if (swap->temp > 0)
		while (i < swap->top_b + swap->uns_mas[swap->temp] - \
			swap->uns_mas[swap->temp - 1])
		{
			if (i < swap->len)
				sort[j++] = swap->stack_b[i];
			else
				break ;
			i++;
		}
	if (swap->temp > 0)
		sort = ft_selection_sort(sort, swap->uns_mas[swap->temp] - \
			swap->uns_mas[swap->temp - 1]);
	if (j != 0)
		swap->pivot = sort[j / 2];
	free(sort);
}

void		new_pivot_a(t_swap *swap)
{
	int		*sort;
	int		i;
	int		j;
	int		n;

	n = swap->len - swap->sorted;
	j = 0;
	i = swap->top_a;
	sort = (int *)malloc(sizeof(int) * (n - i));
	while (i < n)
	{
		sort[j++] = swap->stack_a[i];
		i++;
	}
	sort = ft_selection_sort(sort, (n - swap->top_a));
	swap->pivot = sort[(n - swap->top_a) / 2];
	free(sort);
}

void		split_stacks_toa(t_swap *swap)
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
			swap->unsorted++;
		}
		i++;
	}
	while (swap->unsorted)
	{
		rrb(swap);
		swap->unsorted--;
	}
	swap->uns_mas[swap->temp] = swap->len - swap->top_b;
	split_stacks_toa_add(swap);
}

void		new_pivot(t_swap *swap)
{
	int *sort;
	int i;
	int j;

	j = 0;
	sort = (int *)malloc(sizeof(int) * (swap->len - swap->top_a));
	i = swap->top_a;
	while (i < swap->len)
	{
		sort[j++] = swap->stack_a[i];
		i++;
	}
	sort = ft_selection_sort(sort, swap->len - swap->top_a);
	swap->pivot = sort[(swap->len - swap->top_a) / 2];
	free(sort);
}
