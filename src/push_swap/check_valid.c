/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:56:55 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:26 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int				atoi2_next(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	return (i);
}

int				ft_atoi2(const char *str, int *j)
{
	long long int			nb;
	int						i;
	int						k;

	i = 0;
	k = 1;
	nb = 0;
	i = atoi2_next(str, i);
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
	int	i;

	i = 0;
	while (i < j)
	{
		if (arr_d[i] == var)
		{
			free(arr_d);
			return (-1);
		}
		i++;
	}
	arr_d[i] = var;
	return (0);
}

int				check_valid_num_2(int *arr_d, int check, int argc, char **argv)
{
	int		i;
	int		j;
	int		var;

	j = 0;
	i = 1;
	while (argc-- > 1)
	{
		var = ft_atoi2(argv[i++], &j);
		if (var <= 2147483647 && var >= -2147483648)
		{
			if (j == 1)
				return (-1);
			if (check_same(var, arr_d, check++) == -1)
				return (-1);
		}
		else
		{
			free(arr_d);
			return (-1);
		}
	}
	return (0);
}

int				check_valid_num(int argc, char **argv)
{
	int		*arr_d;
	int		check;

	if (!(arr_d = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	if (ft_strcmp(argv[argc - 1], "-v") == 0)
		argc--;
	check = 0;
	if (check_valid_num_2(arr_d, check, argc, argv) == -1)
		return (-1);
	free(arr_d);
	return (0);
}
