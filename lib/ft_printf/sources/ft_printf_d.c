/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:37:25 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:33 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

static	int	ft_sp_zero_d_i(t_lists *list, int i, size_t len, char *arr)
{
	if (list->space == 1 && *arr != '-')
	{
		arr[i++] = ' ';
		len--;
	}
	while (len--)
		arr[i++] = '0';
	return (i);
}

static	int	extra_rigth_d_two(char *a1, char *ad, long long len, t_lists *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (list->plus == 1 && *ad != '-')
		len--;
	while (len--)
		a1[i++] = ' ';
	if (list->plus == 1 && *ad != '-')
		a1[i++] = '+';
	if ((*ad != '0' && list->dot) || (*ad != '0' && !list->dot))
		while (ad[j])
			a1[i++] = ad[j++];
	else
		a1[i++] = ' ';
	return (i);
}

static	int	extra_rigth_d(char *ar_1, char *ar_d, long long len, t_lists *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((list->plus == 1 && *ar_d == '-') || *ar_d == '-')
	{
		ar_1[i++] = '-';
		j++;
	}
	if (list->plus == 1 && *ar_d != '-')
	{
		ar_1[i++] = '+';
		len--;
	}
	if (!(list->dot))
		i = ft_sp_zero_d_i(list, i, len, ar_1);
	else
		while (len--)
			ar_1[i++] = ' ';
	while (ar_d[j])
		ar_1[i++] = ar_d[j++];
	return (i);
}

int			d_min_right(char *arr_1, char *arr_d, long long len, t_lists *list)
{
	int	i;

	i = 0;
	len = (long long)list->width - (long long)ft_strlen(arr_d);
	if (list->zero == 1)
		i = extra_rigth_d(arr_1, arr_d, len, list);
	else if (list->zero == 0)
		i = extra_rigth_d_two(arr_1, arr_d, len, list);
	return (i);
}

int			d_min_left(char *arr_1, char *arr_d, long long len, t_lists *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((list->plus == 1 && list->space == 1 && *arr_d != '-') \
		|| (list->plus == 1 && list->space == 0 && *arr_d != '-'))
	{
		arr_1[i++] = '+';
		len--;
	}
	else if (list->space == 1 && list->plus == 0 && *arr_d != '-')
	{
		arr_1[i++] = ' ';
		len--;
	}
	while (arr_d[j])
		arr_1[i++] = arr_d[j++];
	while (len--)
		arr_1[i++] = ' ';
	return (i);
}
