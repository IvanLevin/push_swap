/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_d_or_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:35:02 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:20 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

int		pr_left_d(char *arr, char *arr2, t_lists *list)
{
	int		i;
	int		j;
	int		max;
	int		p;

	i = 0;
	j = 0;
	p = 0;
	if (*arr == '+' || *arr == ' ' || *arr == '-')
		max = list->width - list->precision - 1;
	else
		max = list->width - list->precision;
	while (max > 0)
	{
		arr2[j++] = ' ';
		max--;
		p++;
	}
	while (arr[i])
	{
		arr2[j++] = arr[i++];
		p++;
	}
	return (p);
}

int		pr_right_d(char *arr, char *arr2, t_lists *list)
{
	int		i;
	int		j;
	int		p;

	j = 0;
	i = 0;
	p = 0;
	while (arr[i])
	{
		arr2[j++] = arr[i++];
		p++;
	}
	while (list->width > j)
	{
		arr2[j++] = ' ';
		p++;
	}
	return (p);
}

int		fill_zero(char *arr, t_lists *list, char *ap, long long max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (list->spec != 'u' && ((list->plus == 1 && *ap != '-') ||
			(list->space == 1 && *ap != '-')))
		i = 1;
	if (*ap == '-' && list->spec != 'u')
	{
		arr[i++] = '-';
		j = 1;
	}
	while (max-- > 0)
		arr[i++] = '0';
	while (ap[j])
		arr[i++] = ap[j++];
	return (i);
}

int		flag_width_d(t_lists *list, char *ar1, char *ar2, long long len)
{
	int	i;

	i = 0;
	if (*ar2 == '-')
		len++;
	if (list->plus == 1 && *ar2 != '-' && list->spec != 'u')
	{
		ar1[i] = '+';
		i = fill_zero(ar1, list, ar2, len);
	}
	else
	{
		if (list->space == 1 && *ar2 != '-')
		{
			ar1[i] = ' ';
			i = fill_zero(ar1, list, ar2, len);
		}
		else
			i = fill_zero(ar1, list, ar2, len);
	}
	return (i);
}
