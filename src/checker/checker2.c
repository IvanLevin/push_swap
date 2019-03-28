/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:52:04 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/27 17:33:29 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			free_struct_check(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
	swap->pivot = 0;
	swap->score = 0;
	swap->top_a = 0;
	swap->cap_len = 0;
	swap->len_a = 0;
	swap->len_b = 0;
	swap->top_b = 0;
	swap->check_a = 0;
	swap->rec = 0;
	swap->swap_len = 0;
	swap->check = 0;
	swap->checker = 0;
}

static	void	initialize_swap_check(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < 10000)
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
	swap->flag = 0;
	swap->checker = 1;
}

static	int		mem_allocation_check(t_swap *swap)
{
	if (!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	return (0);
}

int				create_arr_check(int argc, char **argv, t_swap *swap)
{
	char	**tab;
	int		i;

	i = 0;
	if (argc == 2)
	{
		tab = ft_strsplit(argv[1], ' ');
		while (tab[i] != NULL)
			i++;
		swap->len = i;
		i--;
		mem_allocation_check(swap);
		while (i > 0)
		{
			swap->stack_a[i] = ft_atoi(tab[i]);
			i--;
		}
		swap->stack_a[i] = ft_atoi(tab[i]);
	}
	return (0);
}

void			push_check(int argc, char **argv, t_swap *swap)
{
	int		var;
	int		i;
	int		j;

	if (argc == 1)
		return ;
	if (argc == 2)
		create_arr_check(argc, argv, swap);
	else
	{
		swap->len = argc - 1;
		mem_allocation_check(swap);
	}
	initialize_swap_check(swap);
	i = 1;
	j = 0;
	if (argc > 2)
		while (argv[i])
		{
			var = ft_atoi(argv[i++]);
			swap->stack_a[j++] = var;
		}
}
