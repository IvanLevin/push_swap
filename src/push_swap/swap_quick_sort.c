/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:20:43 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 18:20:48 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			swap_pivot(t_swap *swap)
{
	int		*sort;
	int		i;
	int		ret;

	sort = (int *)malloc(sizeof(int) * swap->len);
	i = 0;
	while (i < swap->len)
	{
		sort[i] = swap->stack_a[i];
		i++;
	}
	sort = ft_selection_sort(sort, swap->len);
	swap->pivot = (0 + swap->len) / 2;
	ret = sort[swap->pivot];
	free(sort);
	return (ret);
}

int			check_sort(t_swap *swap)
{
	int i;

	i = 0;
	while (i < swap->len - 1)
	{
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void		free_struct(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
	free(swap->uns_mas);
	free(swap->cmnd);
}

void		find_max_min(t_swap *swap)
{
	int i;

	i = 0;
	swap->min = swap->stack_b[swap->top_b];
	swap->max = swap->stack_b[swap->top_b];
	while (i < swap->uns_mas[swap->temp] - swap->uns_mas[swap->temp - 1])
	{
		if (swap->stack_b[i + swap->top_b] < swap->min)
			swap->min = swap->stack_b[i + swap->top_b];
		if (swap->stack_b[i + swap->top_b] > swap->max)
			swap->max = swap->stack_b[i + swap->top_b];
		i++;
	}
}

int			swap_quick_sort(t_swap *swap)
{
	while (swap->top_a <= swap->len - 3)
	{
		split_stacks_tob(swap);
		new_pivot(swap);
	}
	sort_min(swap);
	swap->temp--;
	split_stack_b(swap);
	return (0);
}
