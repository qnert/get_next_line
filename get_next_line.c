/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:40:12 by skunert           #+#    #+#             */
/*   Updated: 2023/03/31 15:50:35 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_bytes(int fd, char *line_str)
{
	char	*buff;
	int		read_value;

	if (line_str == NULL)
		line_str = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_value = 1;
	while (read_value > 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		read_value = read(fd, buff, BUFFER_SIZE);
		if (read_value == -1)
			return (free(buff), free(line_str), NULL);
		line_str = ft_strjoin_free(line_str, buff);
		if (ft_strchr(line_str, '\n') != 0)
			break ;
	}
	return (free (buff), line_str);
}

char	*ft_str_trim_back(char *line_str)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line_str[i] != '\n' && line_str[i])
		i++;
	i++;
	buff = ft_calloc(i + 1, sizeof(char));
	while (j < i)
	{
		buff[j] = line_str[j];
		j++;
	}
	return (buff);
}

char	*ft_str_trim_front(char *line_str)
{
	char	*new_line_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line_str[i] != '\n' && line_str[i])
		i++;
		if (line_str[i] == '\0')
			return (free(line_str), NULL);
	i++;
	new_line_str = ft_calloc(ft_strlen(line_str) - i + 1, sizeof(char));
	while (line_str[i + j] != '\0')
	{
		new_line_str[j] = line_str[i + j];
		j++;
	}
	new_line_str[j] = '\0';
	free (line_str);
	return (new_line_str);
}

char	*get_next_line(int fd)
{
	static char	*line_str;
	char		*ret_buff;

	if (BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	line_str = read_bytes(fd, line_str);
	if (line_str == NULL)
		free (line_str);
	ret_buff = ft_str_trim_back(line_str);
	line_str = ft_str_trim_front(line_str);
	return (ret_buff);
}

int	main(void)
{
	int		fd;
	char	*s;
	char	*s2;
	char	*s3;

	fd = open("text.txt", O_RDONLY);
	s = get_next_line(fd);
	s2 = get_next_line(fd);
	s3 = get_next_line(fd);
	printf("%s", s);
	printf("%s", s2);
	printf("%s", s3);
	return (0);
}
