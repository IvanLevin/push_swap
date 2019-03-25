/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:03:00 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 11:09:19 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(long int n)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (n < 0)
	{
		check++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		check++;
	}
	if (n == 0 && check == 0)
		check++;
	return (check);
}

char		*ft_itoa(int n)
{
	char			*arr_itoa;
	int				sign;
	int				len;
	long int		k;

	k = (long int)n;
	len = 0;
	len = ft_len(k);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		k = -k;
	}
	if (!(arr_itoa = ((char *)malloc(sizeof(char) * len + 1))))
		return (NULL);
	arr_itoa[len--] = '\0';
	while (len >= 0)
	{
		arr_itoa[len--] = k % 10 + '0';
		k = k / 10;
	}
	if (sign == 1)
		arr_itoa[0] = '-';
	return (arr_itoa);
}
