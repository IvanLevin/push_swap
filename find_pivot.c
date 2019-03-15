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
	sort = (int *)malloc(sizeof(int) * swap->len_a);
	while (i < swap->len_a)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->len_a);
	swap->pivot = swap->len_a / 2;
	swap->pivot = sort[swap->pivot];
	i = 0;
	while (i < swap->len_a)
		printf("%d ", sort[i++]);
	printf("\n");
	free(sort);
}

void	pivot_a(t_swap *swap)
{
	int		*sort;
	int 	i;
	int 	j;

	i = 0;
	j = swap->top_a;
	sort = (int *)malloc(sizeof(int) * swap->check_a - swap->top_a);
	while (i < swap->check_a - swap->top_a)
		sort[i++] = swap->stack_a[j++];
	sort = ft_selection_sort(sort, swap->check_a - swap->top_a);
	swap->pivot = (swap->check_a - swap->top_a) / 2;
	swap->pivot = sort[swap->pivot];
	i = 0;
	while (i < swap->check_a - swap->top_a)
		printf("%d ", sort[i++]);
	printf("\n");
	free(sort);
}

void	pivot_b(t_swap *swap)
{
	int 	*sort;
	int 	i;
	int 	stack;
	int 	swap_len;

	i = 0;
	if (swap->cap_len < 0)
		return;
	else if (swap->cap_len - (swap->cap_len - 1) <= 0)
			swap_len = swap->cap[swap->cap_len];
	else if (swap->cap_len == 0)
		swap_len = swap->cap[swap->cap_len];
	else
		swap_len = swap->cap[swap->cap_len] - swap->cap[swap->cap_len - 1];
	sort = (int *)malloc(sizeof(int) * swap->len_b - swap_len);
	stack = swap->top_b;
	while (i < swap_len)
	{
		sort[i] = swap->stack_b[stack];
		i++;
		stack++;
	}
	sort = ft_selection_sort(sort, swap_len);
	swap->pivot = swap_len / 2;
	swap->pivot = sort[swap->pivot];
	free(sort);
}