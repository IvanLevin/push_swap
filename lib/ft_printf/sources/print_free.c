/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:05:49 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:45 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

void	ft_print_free(char **str, t_lists *list, long long max)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return ;
	tmp = *str;
	while (max)
	{
		write(1, tmp++, 1);
		max--;
		i++;
	}
	free(*str);
	*str = NULL;
	list->len += i;
}

void	ft_print_free2(char *str, t_lists *list, long long max)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (max)
	{
		write(1, str++, 1);
		max--;
		i++;
	}
	list->len += i;
}
