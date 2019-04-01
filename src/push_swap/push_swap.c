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

static	void	initialize_swap(t_swap *swap)
{
	int i;

	i = 0;
	while (i < num_of_covers(swap))
		swap->uns_mas[i++] = 0;
	swap->temp_cmd = 0;
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
	if (!(swap->cmnd = (char(*)[4])malloc(sizeof(char *) * swap->len * swap->len)))
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

void            move_cmd(t_swap *swap)
{
    while (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 2] && \
        ft_strequ(swap->cmnd[swap->temp_cmd], "end") != 1 && ft_strequ(swap->cmnd[swap->temp_cmd] , "") != 1)
    {
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 2])
            ft_strcpy(swap->cmnd[swap->temp_cmd], swap->cmnd[swap->temp_cmd + 2]);
        swap->temp_cmd++;
    }
    swap->temp_cmd = 0;
}


void            change_cmd_list(t_swap *swap)
{
    swap->temp_cmd = 0;
//    char    buf[4];

    while (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
        (ft_strequ(swap->cmnd[swap->temp_cmd], "end") != 1 && ft_strequ(swap->cmnd[swap->temp_cmd] , "") != 1))
    {
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "rra") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "ra") == 1)
            move_cmd(swap);
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "ra") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "rra") == 1)
            move_cmd(swap);
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "rb") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "rrb") == 1)
            move_cmd(swap);
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "rrb") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "rb") == 1)
            move_cmd(swap);
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "pb") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "pa") == 1)
            move_cmd(swap);
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "pa") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "pb") == 1)
            move_cmd(swap);
        if (swap->cmnd[swap->temp_cmd] && swap->cmnd[swap->temp_cmd + 1] && \
            ft_strequ(swap->cmnd[swap->temp_cmd], "pa") == 1 && ft_strequ(swap->cmnd[swap->temp_cmd + 1], "pb") == 1)
            move_cmd(swap);
        swap->temp_cmd++;
    }
    swap->temp_cmd = 0;
    while (ft_strequ(swap->cmnd[swap->temp_cmd], "end") != 1 && ft_strequ(swap->cmnd[swap->temp_cmd] , "") != 1)
    {
        if (ft_strequ(swap->cmnd[swap->temp_cmd], "np") != 1)
            printf("%s\n", swap->cmnd[swap->temp_cmd]);
        swap->temp_cmd++;
    }
}

void			push_swap2(int argc, char **argv, t_swap *swap)
{
	int			i;
	int			j;
	int			var;

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
	change_cmd_list(swap);
	free_struct(swap);
	free(swap);
}

void			push_swap(int argc, char **argv)
{
	t_swap		*swap;

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
	push_swap2(argc, argv, swap);
}
