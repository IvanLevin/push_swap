/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:39:19 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:39 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

void		ft_print_fby1(long double pnt, t_lists *list)
{
	char	*tmp;

	if (!list->dot || (list->dot && list->sharp))
	{
		ft_print_free2(".", list, 1);
		if (!(list->sharp && list->dot))
		{
			while (list->precision)
			{
				pnt = pnt * 10;
				tmp = ft_itoa_long((__int128_t)pnt);
				ft_print_free(&tmp, list, (long long)ft_strlen(tmp));
				pnt = pnt - (long)pnt;
				list->precision--;
			}
		}
	}
}

long double	ft_get_addit(t_lists *list, long double n, int prec)
{
	long double	addit;

	addit = 0.5;
	if ((n - (long)n) * 10 == 5 && list->dot && (long)n % 2 == 0)
		addit -= 0.5;
	else
		while (prec)
		{
			addit /= 10;
			prec--;
		}
	n += addit;
	return (n);
}

void		place_left_f(t_lists *list, char *tmp, long minus, long double n)
{
	char	*str;
	int		tmp_i;

	tmp_i = 0;
	str = ft_itoa_long((long long)n);
	if (minus)
		ft_print_free2("-", list, 1);
	else if (list->plus)
		ft_print_free2("+", list, 1);
	while (*str)
		tmp[tmp_i++] = *str++;
	ft_print_free(&tmp, list, tmp_i);
	n = n - (long long)n;
	ft_print_fby1(n, list);
	tmp_i = 0;
	tmp_i += fill_space_x(list->spaces, tmp, tmp_i);
	ft_print_free(&tmp, list, tmp_i);
}

void		place_right_f(t_lists *list, char *tmp, long minus, long double n)
{
	char	*str;
	int		tmp_i;

	tmp_i = 0;
	str = ft_itoa_long((long long)n);
	if (list->zero)
	{
		if (minus)
			ft_print_free2("-", list, 1);
		else if (list->plus)
			ft_print_free2("+", list, 1);
		tmp_i += fill_zeros(list->spaces, tmp, tmp_i);
	}
	else
	{
		tmp_i += fill_space_x(list->spaces, tmp, tmp_i);
		if (minus)
			tmp[tmp_i++] = '-';
		else if (list->plus)
			tmp[tmp_i++] = '+';
	}
	while (*str)
		tmp[tmp_i++] = *str++;
	ft_print_free(&tmp, list, tmp_i);
	ft_print_fby1(n - (long)n, list);
}

void		ft_printf_f(t_lists *list, long double n)
{
	long	minus;
	int		len;
	char	*tmp;

	len = 0;
	minus = (long)n >> 63;
	if (list->precision <= 0 && !(list->dot))
		list->precision = 6;
	if (minus)
		n *= -1;
	n = ft_get_addit(list, n, list->precision);
	len += ft_strlen(ft_itoa_long((long long)n));
	tmp = ft_strnew((size_t)(list->precision + 1 + len - minus < list->width ? \
				list->width - list->precision - 1 : len - minus));
	list->spaces = space_amount_f(list, (int)len, minus);
	if (!list->minus)
		place_right_f(list, tmp, minus, n);
	else
		place_left_f(list, tmp, minus, n);
}
