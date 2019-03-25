/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:35:57 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:25 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

static void	initialize(t_lists *list)
{
	list->dotzero = 0;
	list->zeros = 0;
	list->spaces = 0;
	list->sharp = 0;
	list->dot = 0;
	list->minus = 0;
	list->zero = 0;
	list->space = 0;
	list->plus = 0;
	list->width = 0;
	list->precision = 0;
	list->mod = 0;
	list->spec = 0;
}

int			ft_printf(const char *argv, ...)
{
	va_list		ap;
	t_lists		*list;
	int			len;

	va_start(ap, argv);
	if (!(list = (t_lists *)malloc(sizeof(t_lists))))
		return (-1);
	list->len = 0;
	while (*argv)
	{
		if (*argv == '%')
		{
			initialize(list);
			argv = parsing((char *)argv, ap, list);
		}
		else
		{
			write(1, argv++, 1);
			list->len += 1;
		}
	}
	va_end(ap);
	len = list->len;
	free(list);
	return (len);
}
