//
// Created by Germaine Kshlerin on 2019-03-15.
//

#include "push_swap.h"

void	new_pivot_a(t_swap *swap)
{
	int		*sort;
	int 	i;
	int 	j;

	i = 0;
	j = swap->top_a;
	if(!(sort = (int *)malloc(sizeof(int) * swap->len_a)))
		return;
	while (i < swap->len_a)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->len_a);
	swap->pivot = swap->len_a / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	pivot_b_test(t_swap *swap)
{
	int 	*sort;
	int 	i;
	int 	stack;

	i = 0;
	if(!(sort = (int *)malloc(sizeof(int) * swap->swap_len + 1)))
		return;
	stack = swap->top_b;
	while (i < swap->swap_len)
	{
		sort[i] = swap->stack_b[stack];
		i++;
		stack++;
	}
	sort = ft_selection_sort(sort, swap->swap_len);
	swap->pivot = swap->swap_len / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	pivot_a(t_swap *swap)
{
	int		*sort;
	int 	i;
	int 	j;

	i = 0;
	j = swap->top_a;
	if(!(sort = (int *)malloc(sizeof(int) * swap->check_a - swap->top_a  + 1)))
		return;
	while (i < swap->check_a - swap->top_a)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->check_a - swap->top_a);
	swap->pivot = (swap->check_a - swap->top_a) / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	pivot_b(t_swap *swap)
{
	int 	*sort;
	int 	i;
	int 	stack;

	i = 0;
	if (swap->cap_len < 0)
		return;
	else if (swap->cap_len - (swap->cap_len - 1) <= 0)
			swap->swap_len = swap->cap[swap->cap_len];
	else if (swap->cap_len == 0)
		swap->swap_len = swap->cap[swap->cap_len];
	else
		swap->swap_len = swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1];
	sort = (int *)malloc(sizeof(int) * swap->len_b - swap->swap_len + 1);
	stack = swap->top_b;
	while (i < swap->swap_len)
	{
		sort[i] = swap->stack_b[stack];
		i++;
		stack++;
	}
	sort = ft_selection_sort(sort, swap->swap_len);
	swap->pivot = swap->swap_len / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}

void	put_stack_b(t_swap *swap)
{
	int 	len;
	int 	i;

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
	sort_print(swap);
}