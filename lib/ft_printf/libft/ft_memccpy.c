/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:03:00 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 11:09:20 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr_1;
	size_t			i;

	i = -1;
	c = (unsigned char)c;
	arr = (unsigned char*)src;
	arr_1 = (unsigned char*)dst;
	while (++i < n)
		if ((arr_1[i] = arr[i]) == c)
			return (&arr_1[i + 1]);
	return (NULL);
}
