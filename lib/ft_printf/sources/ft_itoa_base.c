/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:54:48 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:09 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

static	size_t	ft_kols(unsigned long long i, int base)
{
	size_t	k;

	k = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / base;
		k++;
	}
	return (k);
}

char			*ft_itoa_base(unsigned long long int i, int base)
{
	size_t	k;
	char	*str;
	size_t	t;

	k = ft_kols(i, base);
	t = 0;
	if (!(str = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	str[k--] = '\0';
	if (i == 0)
		str[0] = '0';
	while (i > 0)
	{
		t = i % base;
		if (t > 9)
			str[k] = (char)(t - 10 + 'a');
		else
			str[k] = (char)(t + '0');
		k--;
		i = i / base;
	}
	return (str);
}
