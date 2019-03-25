/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:03:00 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 11:09:20 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_len_strchr(char *s, int c, int len)
{
	char	ch_a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ch_a = (char)c;
	while (s[j] != '\0' && s[j] != ch_a && (i < len))
	{
		i++;
		j++;
	}
	if (s[j] == ch_a)
		return (s[j]);
	else
		return (0);
}
