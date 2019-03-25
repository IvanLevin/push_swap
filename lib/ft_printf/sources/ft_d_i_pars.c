/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:04:22 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:05 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

void	d_pars(t_lists *list, char *specifier, va_list ap)
{
	if (*specifier == 'D' && !list->mod)
	{
		print_d_i(list, ft_itoa_long(va_arg(ap, long long)));
	}
	if ((*specifier == 'd' || *specifier == 'i') && !list->mod)
		print_d_i(list, ft_itoa_long(va_arg(ap, int)));
	else if (ft_strchr(&list->mod, 'h'))
		print_d_i(list, ft_itoa_long((short int)va_arg(ap, int)));
	else if (ft_strchr(&list->mod, 'l'))
		print_d_i(list, ft_itoa_long(va_arg(ap, long)));
	else if (ft_strchr(&list->mod, 'G'))
		print_d_i(list, ft_itoa_long((char)va_arg(ap, int)));
	else if (ft_strchr(&list->mod, 'K'))
		print_d_i(list, ft_itoa_long(va_arg(ap, long long int)));
}

void	u_pars(t_lists *list, char *specifier, va_list ap)
{
	list->spec = 'u';
	if (*specifier == 'u' && ft_strchr(&list->mod, 'l'))
		print_d_i(list, ft_itoa_long((unsigned long)va_arg(ap, long int)));
	else if (*specifier == 'u' && list->mod == 'K')
		print_d_i(list, ft_itoa_long((unsigned long long)va_arg(ap, long \
		long int)));
	else if (*specifier == 'u' && list->mod == 'G')
		print_d_i(list, ft_itoa_long((unsigned char)va_arg(ap, int)));
	else
		print_d_i(list, ft_itoa_long(va_arg(ap, unsigned int)));
}
