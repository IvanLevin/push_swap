/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:09:45 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/28 15:44:09 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			initialize_swap(t_swap *swap)
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
	swap->flag = 0;
	swap->checker = 0;
}

static	int		check_valid_arg(char **argv, int i)
{
	int	j;

	j = 0;
	if (argv[i][j] == '+' || argv[i][j] == '-')
		j++;
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	if ((argv[i][j - 1] == '+' || argv[i][j - 1] == '-'))
		return (-1);
	if (argv[i][j] != '\0' || j > 10)
		return (-1);
	if (argv[i][j] >= 33 && argv[i][j] <= 47)
		return (-1);
	if (argv[i][j] >= 58 && argv[i][j] <= 126)
		return (-1);
	return (0);
}

int				check_vaild_2(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 1;
	if (argc == 2)
	{
		if (ft_strequ(argv[1], ""))
			return (-1);
		tab = ft_strsplit(argv[1], ' ');
		while (tab[i] != NULL)
		{
			if (check_valid_arg(tab, i) == -1)
				return (-1);
			i++;
		}
	}
	else
		while (argc > 1)
		{
			if (check_valid_arg(argv, i) == -1)
				return (-1);
			i++;
			argc--;
		}
	return (0);
}

int				check_valid(int argc, char **argv)
{
	if (argc < 1)
		return (-1);
	if (ft_strcmp(argv[argc - 1], "-v") == 0)
		argc--;
	if (check_vaild_2(argc, argv) == -1)
		return (-1);
	else
		return (0);
}
