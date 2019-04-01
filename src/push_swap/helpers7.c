/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:09:43 by breolson          #+#    #+#             */
/*   Updated: 2019/04/01 16:09:45 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			print_cmd(t_swap *swap)
{
	CMD = 0;
	while (EQU(CMNDS[CMD], "end") != 1 && \
		EQU(CMNDS[CMD], "") != 1)
	{
		printf("%s\n", CMNDS[CMD]);
		if (swap->flag_v == 1)
			print_stacks(swap);
		CMD++;
	}
}

void			move_cmd(t_swap *swap)
{
	int			i;

	while (CMNDS[CMD] && CMNDS[CMD + 2] && \
		EQU(CMNDS[CMD], "end") != 1 && \
		EQU(CMNDS[CMD], "") != 1)
	{
		i = CMD;
		ft_strcpy(CMNDS[i], CMNDS[i + 2]);
		swap->temp_cmd++;
	}
	CMD = 0;
}

void			change_cmd_list(t_swap *swap)
{
	CMD = 0;
	while (CMNDS[CMD] && CMNDS[CMD + 1] && \
		EQU(CMNDS[CMD], "end") != 1 && \
		EQU(CMNDS[CMD], "") != 1)
	{
		if ((CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "rra") == 1 && EQU(CMNDS[CMD + 1], "ra") == 1) \
			|| (CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "pa") == 1 && EQU(CMNDS[CMD + 1], "pb") == 1) \
			|| (CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "ra") == 1 && EQU(CMNDS[CMD + 1], "rra") == 1) \
			|| (CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "rb") == 1 && EQU(CMNDS[CMD + 1], "rrb") == 1) \
			|| (CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "rrb") == 1 && EQU(CMNDS[CMD + 1], "rb") == 1) \
			|| (CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "pb") == 1 && EQU(CMNDS[CMD + 1], "pa") == 1) \
			|| (CMNDS[CMD] && CMNDS[CMD + 1] && \
			EQU(CMNDS[CMD], "pa") == 1 && EQU(CMNDS[CMD + 1], "pb") == 1))
			move_cmd(swap);
		CMD++;
	}
	print_cmd(swap);
}
