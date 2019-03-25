/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_amount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:05:15 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:48 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

int				space_amount_f(t_lists *list, int len, long minus)
{
	if (list->width > list->precision + 1 + len && !list->dot)
	{
		if (minus)
			return (list->width - list->precision - 1 - len + (int)minus);
		else if (list->plus)
			return (list->width - list->precision - 1 - len - list->plus);
		else
			return (list->width - len - list->precision - 1);
	}
	if (list->width > list->precision + 1 + len && list->dot)
	{
		if (minus)
			return (list->width - list->precision - len + (int)minus);
		else if (list->plus)
			return (list->width - list->precision - len - list->plus);
	}
	return (0);
}

int				zeros_amount_x2(t_lists *list, int len)
{
	if (len > 0 && list->precision && list->width)
	{
		if (list->width > list->precision)
			return (list->sharp != 1 ? list->precision - len : \
					list->precision - len - list->sharp);
		else
			return (list->sharp == 1 ? list->precision - len - list->sharp :
					list->precision - len);
	}
	if (len > 0 && list->width > list->precision)
		return (0);
	if (len > 0 && list->precision < list->width)
		return (list->precision - len);
	return (0);
}

int				zeros_amount_x(t_lists *list, int len)
{
	if (list->minus)
		list->zero = 0;
	if (list->sharp && list->minus && list->zero)
		return (0);
	if (!list->width && list->precision)
		return (list->precision - len - list->sharp);
	if (list->zero && !list->width && list->precision)
		return (list->precision - len);
	if (list->zero && list->precision && !list->width)
		return (0);
	if (list->zero && !list->precision && !list->width)
		return (list->width - list->sharp - len);
	if (list->zero && !list->precision && list->width)
	{
		if (list->dot)
			return (0);
		else
			return (list->width - list->sharp - len);
	}
	else
		return (zeros_amount_x2(list, len));
}

static	int		space_amount_x2(t_lists *list, int len)
{
	if (list->width > len && len < list->precision && list->sharp)
	{
		return (list->sharp == 1 ? list->width - list->precision : \
			list->width - list->precision - list->sharp);
	}
	if (!len && list->width)
		return (list->width);
	if (list->width > len && len < list->precision && !list->sharp)
		return (list->width - list->precision);
	if (len > 0 && list->width && !list->precision)
		return (list->width - list->sharp - len);
	else
	{
		if (len > 0 && list->width > list->precision && list->sharp)
			return (list->width - list->sharp - len);
		else if (len > 0 && list->width > list->precision && !list->sharp && \
			!list->minus)
			return (list->width - len);
		else if (len > 0 && list->width > list->precision && !list->sharp)
			return (list->width - len);
	}
	return (0);
}

int				space_amount_x(char *str, t_lists *list, int len)
{
	if (!ft_strcmp(str, "0"))
		return (list->width);
	if (list->width && list->sharp && list->minus && list->zero)
		return (list->width - len - list->sharp);
	if (list->zero && list->precision && !list->width)
		return (list->width - len);
	if (list->zero && list->precision && list->width)
	{
		if (list->precision < len)
			return (list->width - len - list->sharp);
		else
			return (list->width - list->precision - list->sharp);
	}
	if (list->zero && !list->precision && list->width && list->dot)
		return (list->width - list->sharp - len);
	if (list->zero && !list->precision && list->width && !list->dot)
		return (0);
	if (len > 0 && list->width > len && list->width < list->precision && \
			list->sharp)
	{
		if (list->width < list->precision)
			return (0);
	}
	return (space_amount_x2(list, len));
}
