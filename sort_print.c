/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:16:46 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 17:24:05 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	sort_print(t_swap *swap)
{
	int i;

	i = 0;
	printf(GREEN"        ----------------\n");
	printf("        ----------------\n");
	while (i < swap->len)
	{
		if (i < swap->top_a && i < swap->top_b)
			ft_printf("         _          _\n");
		else if (i < swap->top_a && i >= swap->top_b)
			ft_printf("         _ %10d\n", swap->stack_b[i]);
		else if (i >= swap->top_a && i < swap->top_b)
			ft_printf("%10d          _\n", swap->stack_a[i]);
		else
			ft_printf("%10d %10d\n", swap->stack_a[i], swap->stack_b[i]);
		i++;
	}
	printf("       ----------------\n");
	ft_printf(BLUE);
}
