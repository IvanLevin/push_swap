/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <breolson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:50:18 by breolson          #+#    #+#             */
/*   Updated: 2019/01/03 17:37:12 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int			checkline(char **stack, char **line)
{
	char			*br;
	char			*tmp;
	char			*tmp2;
	char			*tmp_stack;
	int				i;

	i = 0;
	br = *stack;
	while (br[i] != '\n')
		if (!br[i++])
			return (0);
	tmp_stack = &br[i];
	*tmp_stack = '\0';
	tmp2 = ft_strdup(*stack);
	free(*line);
	*line = tmp2;
	tmp = ft_strdup(tmp_stack + 1);
	free(*stack);
	*stack = tmp;
	return (1);
}

static	int			read_file(int fd, char **stack, char **line)
{
	char			*tmp;
	char			kycha[BUFF_SIZE + 1];
	int				ret;

	while ((ret = read(fd, kycha, BUFF_SIZE)) > 0)
	{
		kycha[ret] = '\0';
		if (*stack)
		{
			tmp = *stack;
			*stack = ft_strjoin(tmp, kycha);
			free(tmp);
			if (checkline(stack, line))
				return (1);
		}
		else
		{
			*stack = ft_strdup(kycha);
			if (checkline(stack, line))
				return (1);
		}
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*stack[MAX_FD];
	int				ret;

	if (fd < 0 || fd >= MAX_FD || line == NULL)
		return (-1);
	*line = ft_strnew(1);
	if (stack[fd])
		if (checkline(&stack[fd], line))
			return (1);
	if ((ret = read_file(fd, &stack[fd], line)) == 1)
		return (1);
	if (ret == -1)
		return (-1);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
		return (ret);
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
