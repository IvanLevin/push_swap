/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:33:16 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/27 18:22:33 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include "../lib/ft_printf/libft/libft.h"

int		get_next_line(const int fd, char **line);

# define MRES(a, b) { if(!a || !b) return (-1); else return (1);}

#endif
