/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_filler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:05:15 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:50 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

int			fill_sharp(char *tmp, int tmp_i, t_lists *list, int base)
{
	if (list->sharp)
	{
		tmp[tmp_i] = '0';
		if (base == 16)
			tmp[tmp_i + 1] = 'x';
		list->sharp = 0;
		return (base == 16 ? 2 : 1);
	}
	return (0);
}

int			fill_zeros(int zeros, char *tmp, int tmp_i)
{
	int		i;

	i = 0;
	while (zeros > 0)
	{
		tmp[tmp_i++] = '0';
		zeros--;
		i++;
	}
	return (i);
}

int			fill_space_x(int space, char *tmp, int tmp_i)
{
	int		i;

	i = 0;
	while (space > 0)
	{
		tmp[tmp_i++] = ' ';
		space--;
		i++;
	}
	return (i);
}
