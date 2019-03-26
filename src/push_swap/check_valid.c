/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:56:55 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/26 18:04:45 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int		ft_atoi2(const char *str, int *j)
{
	long long int			nb;
	int						i;
	int						k;

	i = 0;
	k = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		k *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	if (nb > 9223372036854775807)
	{
		if (k > 0)
			return (-1);
		else
			return (0);
	}
	if (nb < -2147483648 || nb > 2147483647)
		j[0] = 1;
	return ((int)nb * k);
}

static	int		check_same(int var, int *arr_d, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (arr_d[i] == var)
			return (-1);
		i++;
	}
	arr_d[i] = var;
	return (0);
}

int				check_valid_num(int argc, char **argv)
{
	int		*arr_d;
	int		var;
	int 	check;
	int		i;
	int 	j;

	j = 0;
	if(!(arr_d = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	check = 0;
	i = 1;
	while (argc > 1)
	{
		var = ft_atoi2(argv[i], &j);
		if (var <= 2147483647 && var >= -2147483648)
		{
			if (j == 1)
				return (-1);
			if(check_same(var, arr_d, check) == -1)
			{
				free(arr_d);
				return (-1);
			}
		}
		else
		{
			free(arr_d);
			return (-1);
		}
		check++;
		i++;
		argc--;
	}
	free(arr_d);
	return (0);
}

static	int		check_valid_arg(char **argv, int i)
{
	int j;

	j = 0;
	if (argv[i][j] == '+' || argv[i][j] == '-')
		j++;
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	if ((argv[i][j - 1] == '+' || argv[i][j - 1] == '-'))
		return (-1);
	if (argv[i][j] != '\0' || j > 10)
		return (-1);
	return (0);
}

int				check_valid(int argc, char **argv)
{
	int		i;
	char    **tab;

	i = 1;
//
	if (argc < 1)
		return (-1);
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
		while (argc > 2)
		{
			if (check_valid_arg(argv, i) == -1)
				return (-1);
			i++;
			argc--;
		}
	return (0);
}
