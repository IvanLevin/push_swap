/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:52:04 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/26 18:06:37 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			free_struct_check(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
}

static	void	initialize_swap_check(t_swap *swap)
{
	int	i;

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
	swap->checker = 1;
}

static	int		mem_allocation_check(t_swap *swap)
{
	if (!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	return (0);
}

t_swap			*push_check(int argc, char **argv)
{
	t_swap	*swap;
	int		var;
	int		i;
	int		j;

	swap = (t_swap *)malloc(sizeof(t_swap));
	swap->len = argc - 1;
	mem_allocation_check(swap);
	initialize_swap_check(swap);
	i = 1;
	j = 0;
	while (argv[i])
	{
		var = ft_atoi(argv[i++]);
		swap->stack_a[j++] = var;
	}
	return (swap);
}
