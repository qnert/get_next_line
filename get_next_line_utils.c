/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:28 by skunert           #+#    #+#             */
/*   Updated: 2023/03/29 10:22:02 by skunert          ###   ########.fr       */
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

char	*ft_strjoin_free(const char *s1, const char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str_j;

	len = ft_strlen(s1) + ft_strlen(s2);
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
	free((void *) s1);
	free((void *) s2);
	return (str_j);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	if (str == NULL)
		return ((char *)str);
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
