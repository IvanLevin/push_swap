/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:53:46 by breolson          #+#    #+#             */
/*   Updated: 2019/03/29 11:54:02 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
