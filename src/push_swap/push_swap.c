/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:06:12 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/28 15:27:26 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	free_struct(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
}

static	int		mem_allocation(t_swap *swap)
{
	if (!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	return (0);
}

int				create_arr(int argc, char **argv, t_swap *swap)
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
		mem_allocation(swap);
		while (i > 0)
		{
			swap->stack_a[i] = ft_atoi(tab[i]);
			i--;
		}
		swap->stack_a[i] = ft_atoi(tab[i]);
	}
	return (0);
}

void			push_swap_2(int ac, char **ar, t_swap *swap, int var)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	initialize_swap(swap);
	if (ac > 2)
	{
		while (ar[i])
		{
			var = ft_atoi(ar[i++]);
			swap->stack_a[j++] = var;
		}
	}
	algorithm_sort(swap);
	free_struct(swap);
	free(swap);
}

void			push_swap(int argc, char **argv)
{
	t_swap	*swap;
	int		var;

	var = 0;
	swap = (t_swap *)malloc(sizeof(t_swap));
	if (argc == 1)
		return ;
	swap->flag_v = 0;
	if (ft_strcmp(argv[argc - 1], "-v") == 0)
	{
		swap->flag_v = 1;
		argc--;
	}
	if (argc == 2)
		create_arr(argc, argv, swap);
	else
	{
		swap->len = argc - 1;
		if (mem_allocation(swap) == -1)
			return ;
	}
	push_swap_2(argc, argv, swap, var);
}
