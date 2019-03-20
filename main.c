/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:15:51 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 17:30:42 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	if (check_valid(argc, argv) == -1)
	{
		ft_putendl("\e[0;31mError");
		return (-1);
	}
	if (check_valid_num(argc, argv) == -1)
	{
		ft_putendl("\e[0;31mError");
		return (-1);
	}
//	ft_printf(BLUE);
	push_swap(argc, argv);
	return (0);
}
