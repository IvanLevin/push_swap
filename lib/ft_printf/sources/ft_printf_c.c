/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:36:33 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:27 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

static	int	space_amount_c(t_lists *list)
{
	if (list->width > list->precision && list->width > 1)
		return (list->width - 1);
	return (0);
}

static	int	print_space(char *second, int space, int start)
{
	int	i;

	i = 0;
	while (space > i)
	{
		second[start++] = ' ';
		i++;
	}
	return (i);
}

static	int	print_c(char *first, char *second, int i)
{
	int	j;

	j = 0;
	second[i++] = first[j];
	return (i);
}

void		ft_printf_c(t_lists *list, va_list ap)
{
	char	first;
	char	*second;
	int		space;
	int		char_c;
	int		i;

	i = 0;
	char_c = va_arg(ap, int);
	first = (char)char_c;
	space = space_amount_c(list);
	second = ft_strnew((size_t)list->width);
	if (list->minus == 1)
	{
		i += print_c(&first, second, i);
		i += print_space(second, space, i);
		ft_print_free(&second, list, i);
	}
	else if (list->minus == 0)
	{
		i = print_space(second, space, i);
		i = print_c(&first, second, i);
		ft_print_free(&second, list, i);
	}
	free(second);
}
