/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:40:12 by skunert           #+#    #+#             */
/*   Updated: 2023/03/25 23:45:13 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char	*read_bytes(int fd)
{
	int			read_value;
	static char	*final_str;
	char		*buff;

	buff = ft_calloc(4, sizeof(char));
	read_value = read(fd, buff, 4);
	if (read_value >= 1)
		return (buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line_str;
	char		*tmp_buff;

	tmp_buff = read_bytes(fd);
	while (tmp_buff != NULL)
	{
		if (line_str == NULL)
			line_str = tmp_buff;
		else
			line_str = ft_strjoin(line_str, tmp_buff);
		tmp_buff = read_bytes(fd);
	}
	return (line_str);
}

int main(void)
{
	int		fd;
	char	*s;

	fd = open("read.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n", s);
	return (0);
}
