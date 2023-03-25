/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:40:12 by skunert           #+#    #+#             */
/*   Updated: 2023/03/25 22:59:15 by skunert          ###   ########.fr       */
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
	{
		if (final_str == NULL)
			final_str = buff;
		else
			final_str = ft_strjoin(final_str, buff);
		printf("%s\n", final_str);
	}
	return (NULL);
}

int main(void)
{
	int		fd;

	fd = open("read.txt", O_RDONLY);
	read_bytes(fd);
	read_bytes(fd);
	read_bytes(fd);
	read_bytes(fd);
	read_bytes(fd);
	read_bytes(fd);

	return (0);
}
