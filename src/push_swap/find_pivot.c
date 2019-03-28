/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:15:39 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/27 19:02:21 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	new_pivot_a(t_swap *swap)
{
	int		*sort;
	int		i;
	int		j;

	i = 0;
	j = swap->top_a;
	if (!(sort = (int *)malloc(sizeof(int) * swap->len_a)))
		return ;
	while (i < swap->len_a)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->len_a);
	swap->pivot = swap->len_a / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	pivot_b_test(t_swap *swap)
{
	int		*sort;
	int		i;
	int		stack;
	int		len;

	i = 0;
	len = swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1];
	if (!(sort = (int *)malloc(sizeof(int) * len)))
		return ;
	stack = swap->top_b;
	while (i < len)
	{
		sort[i] = swap->stack_b[stack];
		i++;
		stack++;
	}
	sort = ft_selection_sort(sort, len);
	swap->pivot = len / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	pivot_a(t_swap *swap)
{
	int		*sort;
	int		i;
	int		j;

	i = 0;
	j = swap->top_a;
	if (!(sort = (int *)malloc(sizeof(int ) * swap->check_len)))
		return ;
	while (i < swap->check_len)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->check_len);
	swap->pivot = swap->check_len / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	pivot_b(t_swap *swap)
{
	if (swap->cap_len < 0)
		return ;
	else if (swap->cap_len - (swap->cap_len - 1) <= 0)
		swap->swap_len = swap->cap[swap->cap_len];
	else if (swap->cap_len == 0)
		swap->swap_len = swap->cap[swap->cap_len];
	else
		swap->swap_len = swap->cap[swap->cap_len] -
	swap->cap[swap->cap_len - 1];
}

void	put_stack_b(t_swap *swap)
{
	int		len;
	int		i;

	i = 0;
	len = swap->len_a;
	while (i < len)
	{
		if (swap->stack_a[swap->top_a] < swap->pivot)
			pb(swap);
		else
			ra(swap);
		i++;
	}
}
