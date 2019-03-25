/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:03:00 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 11:09:20 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	change_alp(char c, int str_base)
{
	if (c >= 'a' && c <= (str_base + 'a' - 11))
		c = c - 'a' + '0' + 10;
	else if (c >= 'A' && c <= (str_base + 'A' - 11))
		c = c - 'A' + '0' + 10;
	return (c);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int					sign;
	unsigned int		res;

	sign = 1;
	res = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' ||
				*str == '\r' || *str == '\n' || *str == '\f' || *str == '\v'))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = ((*str == '-') && (str_base == 10)) ? -1 : 1;
		str++;
	}
	if (str_base >= 2 && str_base <= 16)
		while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <=
			(str_base + 'a' - 11)))
		{
			res = res * str_base + change_alp(*str, str_base) - '0';
			str++;
		}
	else
		return (0);
	return (res * sign);
}
