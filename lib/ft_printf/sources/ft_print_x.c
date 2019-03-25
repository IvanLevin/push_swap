/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:35:19 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:22 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

static	void	ft_change_letter(char *tmp, char spec)
{
	int	i;

	i = 0;
	if (spec == 'X')
		while (tmp[i])
		{
			if ((tmp[i] >= 97 && tmp[i] <= 102) || tmp[i] == 'x')
				tmp[i] = (char)(tmp[i] - 32);
			i++;
		}
}

static	void	ft_printf_x3(t_lists *list, char *str, char *tmp, int tmp_i)
{
	if (list->minus && list->spaces > 0)
		tmp_i += fill_space_x(list->spaces, tmp, tmp_i);
	ft_change_letter(tmp, list->spec);
	if (list->sharp && *str == '0')
		ft_print_free2("0", list, 1);
	else
		ft_print_free(&tmp, list, tmp_i);
}

static	void	ft_printf_x2(t_lists *list, char *str, char *tmp)
{
	int			tmp_i;

	tmp_i = 0;
	if (!list->minus && list->spaces > 0 && !list->zeros)
	{
		tmp_i += fill_space_x(list->spaces, tmp, tmp_i);
		tmp_i += fill_sharp(tmp, tmp_i, list, list->base);
	}
	else if (!list->minus && list->zeros)
	{
		tmp_i += fill_space_x(list->spaces, tmp, tmp_i);
		tmp_i += fill_sharp(tmp, tmp_i, list, list->base);
		tmp_i += fill_zeros(list->zeros, tmp, tmp_i);
		list->zeros = 0;
	}
	if (!((list->spec == 'o' || list->spec == 'x' || list->spec == 'X') &&
	!ft_strcmp(str, "0") && list->sharp))
		tmp_i += fill_sharp(tmp, tmp_i, list, list->base);
	tmp_i += fill_zeros(list->zeros, tmp, tmp_i);
	if (!((list->dot || list->dotzero) && !ft_strcmp(str, "0")))
		while (*str)
			tmp[tmp_i++] = *str++;
	ft_printf_x3(list, str, tmp, tmp_i);
}

void			ft_printf_x(unsigned long long n, t_lists *list)
{
	char	*str;
	size_t	len;
	char	*tmp;

	if (list->base == 8 && list->sharp)
		list->sharp = 1;
	if (n == 0 && list->spec == 'x')
		list->sharp = 0;
	str = ft_itoa_base(n, list->base);
	len = ft_strlen(str);
	list->zeros = zeros_amount_x(list, (int)len);
	list->spaces = space_amount_x(str, list, (int)len);
	tmp = ft_strnew((size_t)list->width + list->precision);
	ft_printf_x2(list, str, tmp);
	free(str);
}
