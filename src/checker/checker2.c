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
	swap->pivot = 0;
	swap->score = 0;
	swap->top_a = 0;
	swap->top_b = swap->len;
	swap->max = 0;
	swap->min = 0;
	swap->temp = 2;
	swap->unsorted = 0;
	swap->sorted = 0;
	swap->checker = 1;
}

static	int		mem_allocation_check(t_swap *swap)
{
	if (!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if (!(swap->cmnd = (char(*)[4])malloc(sizeof(char *) * \
		swap->len * swap->len)))
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

t_swap			*push_check(int argc, char **argv)
{
	t_swap	*swap;
	int		var;
	int		i;
	int		j;

	swap = (t_swap *)malloc(sizeof(t_swap));
	if (argc == 1)
		return (0);
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
	return (swap);
}
