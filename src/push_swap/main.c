/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:46:24 by breolson          #+#    #+#             */
/*   Updated: 2019/03/28 14:46:41 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	push_swap(argc, argv);
	return (0);
}
