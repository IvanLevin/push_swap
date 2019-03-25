/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:03:00 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 11:09:20 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*arr_1;
	unsigned char	*arr_2;

	arr_1 = (unsigned char *)str1;
	arr_2 = (unsigned char *)str2;
	while (n > 0 && (*arr_1 == *arr_2))
	{
		arr_1++;
		arr_2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*arr_1 - *arr_2);
}
