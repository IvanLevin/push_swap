/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:50:35 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 14:50:36 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	free_struct(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
	free(swap->uns_mas);
}

static	void	initialize_swap(t_swap *swap)
{
	int i;

	i = 0;
	while (i < num_of_covers(swap))
		swap->uns_mas[i++] = 0;
	swap->pivot = 0;
	swap->score = 0;
	swap->top_a = 0;
	swap->top_b = swap->len;
	swap->max = 0;
	swap->min = 0;
	swap->temp = 2;
	swap->unsorted = 0;
	swap->sorted = 0;
	swap->checker = 0;
}

int				mem_allocation(t_swap *swap)
{
	if (!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->uns_mas = (int *)malloc(sizeof(int) * num_of_covers(swap))))
		return (-1);
	return (0);
}

int				create_arr(int argc, char **argv, t_swap *swap)
{
	char		**tab;
	int			i;

	i = 0;
	if (argc == 2)
	{
		tab = ft_strsplit(argv[1], ' ');
		while (tab[i] != NULL)
			i++;
		swap->len = i - 1;
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

void			push_swap(int argc, char **argv)
{
	t_swap		*swap;
	int			var;
	int			i;
	int			j;

	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
		return ;
	swap->flag_v = 0;
	if (argc == 1)
		return ;
	if (ft_strcmp(argv[argc - 1], "-v") == 0)
	{
		argc -= 1;
		swap->flag_v = 1;
	}
	if (argc == 2)
		create_arr(argc, argv, swap);
	else
	{
		swap->len = argc - 1;
		if (mem_allocation(swap) == -1)
			return ;
	}
	initialize_swap(swap);
	i = 1;
	j = 0;
	if (argc > 2)
	{
		while (argv[i])
		{
			var = ft_atoi(argv[i++]);
			swap->stack_a[j++] = var;
		}
	}
	algorithm_sort(swap);
	ft_printf("---------------------------\nSCORE = %d", swap->score);
	free_struct(swap);
	free(swap);
}
