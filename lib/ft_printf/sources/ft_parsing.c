/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:34:32 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:14 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

char	*parsing2(char *argv, va_list ap, t_lists *list)
{
	if (*argv == 'h' || *argv == 'l' || *argv == 'L')
		argv = ft_modifier(argv, list);
	if (data_types(argv, ap, list))
		argv++;
	return (argv);
}

char	*parsing(char *argv, va_list ap, t_lists *list)
{
	argv++;
	if (*argv == '-' || *argv == '+' || *argv == ' ' || \
		*argv == '#' || *argv == '0')
		argv = ft_flag(argv, list);
	if (*argv == '*' || (*argv >= '0' && *argv <= '9'))
		argv = ft_width(argv, ap, list);
	if (*argv == '.' || (*argv == '.' && (*(argv + 1) == '*' || \
		(*(argv + 1) >= '0' && *(argv + 1) <= '9'))))
	{
		list->dotzero = *(argv + 1) == '0' ? 1 : 0;
		argv = ft_accuracy(argv, ap, list);
	}
	if (*argv == '.')
	{
		list->precision = 0;
		argv++;
	}
	if (*argv == '%')
	{
		argv = ft_percent(argv, list);
		return (argv);
	}
	return (parsing2(argv, ap, list));
}
