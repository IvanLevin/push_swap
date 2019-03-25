/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:38:39 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:35 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

static	void	print_pl_sp_d_i(t_lists *ls, char *ar, char *a1)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*ar == '0' && ls->plus == '0')
		*ar = ' ';
	if (ls->plus == 1 && *ar != '-' && ls->spec != 'u')
	{
		a1[i++] = '+';
		if (!ls->dot || ar[j] != '0')
			while (ar[j])
				a1[i++] = ar[j++];
	}
	else if (ls->space == 1 && *ar != '-' && ls->spec != 'u')
	{
		a1[i++] = ' ';
		if (!ls->dot || ar[j] != '0')
			while (ar[j])
				a1[i++] = ar[j++];
	}
	else
		while (ar[j])
			a1[i++] = ar[j++];
	ft_print_free(&a1, ls, i);
}

static	void	print_width_d_i(t_lists *list, char *arr_d, long long len)
{
	char	*arr_1;
	int		i;

	i = 0;
	if (*arr_d == '0' && !list->zero && !list->width)
		*arr_d = ' ';
	len = list->width - len;
	arr_1 = ft_strnew((size_t)len);
	if (list->minus == 1)
		i = d_min_left(arr_1, arr_d, len, list);
	else if (list->minus == 0)
		i = d_min_right(arr_1, arr_d, len, list);
	ft_print_free(&arr_1, list, i);
	free(arr_1);
	free(arr_d);
}

static	void	print_precision_d_i(t_lists *list, char *arr_d, long long len)
{
	char	*arr_1;
	char	*arr_2;
	int		i;

	arr_1 = ft_strnew((size_t)list->precision + 1);
	len = list->precision - len;
	i = flag_width_d(list, arr_1, arr_d, len);
	free(arr_d);
	if (list->precision < list->width && list->width)
	{
		arr_2 = ft_strnew((size_t)list->width);
		i = list->minus == 1 ? pr_right_d(arr_1, arr_2, list) \
		: pr_left_d(arr_1, arr_2, list);
		free(arr_1);
		ft_print_free(&arr_2, list, i);
		free(arr_2);
	}
	else
	{
		ft_print_free(&arr_1, list, i);
		free(arr_1);
	}
}

void			print_d_i(t_lists *list, char *arr_d)
{
	long long	len;
	char		*arr_1;

	len = (long long)ft_strlen(arr_d);
	if ((long long)list->precision >= len && list->precision)
		print_precision_d_i(list, arr_d, len);
	else
	{
		if ((long long)list->width > len && list->width)
			print_width_d_i(list, arr_d, len);
		else if ((list->plus == 1 || list->space == 1))
		{
			arr_1 = ft_strnew((size_t)len + 1);
			print_pl_sp_d_i(list, arr_d, arr_1);
			free(arr_d);
		}
		else
			print_test(arr_d, list, (size_t)len);
	}
}

void			ft_printf_d_i_u(t_lists *list, char *specifier, va_list ap)
{
	if (*specifier == 'i' || *specifier == 'd' || *specifier == 'D')
		d_pars(list, specifier, ap);
	if (*specifier == 'u')
		u_pars(list, specifier, ap);
}
