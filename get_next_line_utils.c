/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:28 by skunert           #+#    #+#             */
/*   Updated: 2023/03/26 00:17:20 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *dst, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned int	i;

	ptr_dst = (unsigned char *) dst;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str_j;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = 0;
	j = 0;
	str_j = ft_calloc(len + 1, sizeof(char));
	if (!str_j)
		return (NULL);
	while (s1[i] != '\0')
	{
		str_j[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str_j[i + j] = s2[j];
		j++;
	}
	return (str_j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		s_len;
	char				*sub_str;

	i = 0;
	s_len = ft_strlen((char *)s);
	if (s_len - start > 0)
	{
		if (s_len - start < len || start > s_len)
			len = s_len;
	}
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
	unsigned int	s_len;
	unsigned int	cpy_len;

	s_len = ft_strlen(s);
	cpy_len = 0;
	while(s[cpy_len])
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
	while(s[start])
	{
		start++;
		if (s[start] == '\n')
			break ;
	}
	return (ft_substr(s, start + 1, s_len - start));
}

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)str);
	while (i < len)
	{
		if (str[i] == (char)c)
			return ((char *) str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *) str + i);
	return (0);
}
