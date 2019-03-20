/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:06:12 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 17:30:42 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_struct(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
}

static	void	initialize_swap(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->len)
	{
		swap->stack_a[i] = 0;
		swap->stack_b[i] = 0;
		i++;
	}
	i = 0;
	while (i < 100000)
		swap->cap[i++] = 0;
	swap->pivot = 0;
	swap->score = 0;
	swap->top_a = 0;
	swap->cap_len = 0;
	swap->len_a = swap->len;
	swap->len_b = 0;
	swap->top_b = swap->len;
	swap->check_a = 0;
	swap->rec = 0;
	swap->swap_len = 0;
	swap->check = 0;
}

static	int	mem_allocation(t_swap *swap)
{
	int	i;

	i = 0;
	if (!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	return (0);
}

void	push_swap(int argc, char **argv)
{
	t_swap	*swap;
	int		var;
	int		i;
	int		j;

	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
		return ;
	swap->len = argc - 1;
	if (mem_allocation(swap) == -1)
		return ;
	initialize_swap(swap);
	i = 1;
	j = 0;
	while (argv[i])
	{
		var = ft_atoi(argv[i++]);
		swap->stack_a[j++] = var;
	}
	algorithm_sort(swap);
	free_struct(swap);
}
