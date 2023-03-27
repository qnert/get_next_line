/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:40:12 by skunert           #+#    #+#             */
/*   Updated: 2023/03/27 20:52:49 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_bytes(int fd)
{
	int			read_value;
	char		*buff;

	buff = ft_calloc(BUFFER_SIZE, sizeof(char));
	read_value = read(fd, buff, BUFFER_SIZE);
	if (read_value >= 1)
		return (buff);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		s_len;
	char				*sub_str;

	i = 0;
	s_len = ft_strlen((char *)s);
	if (start > s_len)
		len = 0;
	if (len > s_len)
		len = s_len;
	if (start + len > s_len)
		len = s_len - start;
	sub_str = ft_calloc(len + 1, sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	while (start < s_len && i < len && s[start] != '\0' && s[i] != '\0')
	{
		if (start > ft_strlen((char *)s))
			break ;
		sub_str[i] = s[start];
		i++;
		start++;
	}
	return (sub_str);
}

char	*ft_str_trim_back(char const *s)
{
	unsigned int	cpy_len;

	cpy_len = 0;
	while (s[cpy_len])
	{
		cpy_len++;
		if (s[cpy_len] == '\n')
			break ;
	}
	return (ft_substr(s, 0, cpy_len + 1));
}

char	*ft_str_trim_front(char const *s)
{
	unsigned int	s_len;
	unsigned int	start;

	s_len = ft_strlen(s);
	start = 0;
	while (s[start])
	{
		start++;
		if (s[start] == '\n')
			break ;
	}
	return (ft_substr(s, start + 1, s_len - start));
}

char	*get_next_line(int fd)
{
	static char	*line_str;
	char		*tmp_buff;

	if (fd < 0)
		return (NULL);
	tmp_buff = read_bytes(fd);
	if (tmp_buff == NULL)
		return (NULL);
	while (tmp_buff != NULL)
	{
		if (line_str == NULL)
			line_str = tmp_buff;
		else
			line_str = ft_strjoin(line_str, tmp_buff);
		if (ft_strchr(line_str, '\n') != 0)
			break ;
		tmp_buff = read_bytes(fd);
	}
	tmp_buff = line_str;
	line_str = ft_str_trim_front(tmp_buff);
	return (ft_str_trim_back(tmp_buff));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;
// 	char	*s2;
// 	char	*s3;

// 	fd = open("read.txt", O_RDONLY);
// 	s = get_next_line(0);
// 	s2 = get_next_line(0);
// 	s3 = get_next_line(0);
// 	printf("%s", s);
// 	printf("%s", s2);
// 	printf("%s", s3);
// 	return (0);
// }
