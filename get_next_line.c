/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrinite <ctrinite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:17:11 by ctrinite          #+#    #+#             */
/*   Updated: 2022/05/11 19:40:56 by ctrinite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd;

	buff = 	malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd = 1;
	while (!ft_strchr(left_str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_left_str(fd, left_str);
	if (!left_str)
		return (0);
	line = ft_getline(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}