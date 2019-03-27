/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:50:47 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/27 16:38:57 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	int		check_sort_c(t_swap *swap)
{
	int	i;

	i = swap->top_a;
	if (swap->len_b != 0)
		return (1);
	while (i < swap->len - 1)
	{
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void			print_ok(t_swap *swap)
{
	if (check_sort_c(swap) == 1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_struct_check(swap);
}

static	int		rule_checking(t_swap *swap, char *line)
{
	if (ft_strequ(line, "pa"))
		pa(swap);
	else if (ft_strequ(line, "pb"))
		pb(swap);
	else if (ft_strequ(line, "rra"))
		rra(swap);
	else if (ft_strequ(line, "rrb"))
		rrb(swap);
	else if (ft_strequ(line, "sb"))
		sb(swap);
	else if (ft_strequ(line, "ra"))
		ra(swap);
	else if (ft_strequ(line, "rb"))
		rb(swap);
	else if (ft_strequ(line, "ss"))
		ss(swap);
	else if (ft_strequ(line, "rrr"))
		rrr(swap, swap);
	else if (ft_strequ(line, "rr"))
		rr(swap, swap);
	else if (ft_strequ(line, "sa"))
		sa(swap);
	else
		return (0);
	return (1);
}

static	int		check_valid_1(int argc, char **argv)
{
	if (*argv[1] >= '0' && *argv[1] <= '9')
	{
		if (check_valid(argc, argv) == -1)
		{
			ft_putendl("Error\n");
			return (-1);
		}
		if (check_valid_num(argc, argv) == -1)
		{
			ft_putendl("Error\n");
			return (-1);
		}
		return (0);
	}
	else
	{
		ft_putendl("Error\n");
		return (-1);
	}
}

int				main(int argc, char **argv)
{
	t_swap	*swap;
	char	*line;

	if (argc == 1)
		return (-1);
	if (check_valid_1(argc, argv) == -1)
		return (-1);
	swap = push_check(argc, argv);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, ""))
			break ;
		if (!(rule_checking(swap, line)))
		{
			free(line);
			ft_putendl("Error\n");
			return (0);
		}
		free(line);
	}
	print_ok(swap);
	return (0);
}
