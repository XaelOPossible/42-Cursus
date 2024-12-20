/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:30:26 by axemicha          #+#    #+#             */
/*   Updated: 2024/12/19 16:20:18 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			a;

	a = 0;
	ptr = (unsigned char *) s;
	while (a < n)
	{
		ptr[a] = '\0';
		a++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*bzero;
	
	bzero = (void *)malloc(count * size);
	if (!bzero)
		return (NULL);
	ft_bzero(bzero, count * size);
	return (bzero);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	para1;
	size_t	para2;

	i = 0;
	para1 = ft_strlen(dst);
	para2 = ft_strlen(src);
	if (size <= para1)
		return (para2 + size);
	while (src[i] != '\0' && para1 + i < size - 1)
	{
		dst[para1 + i] = src[i];
		i++;
	}
	dst[para1 + i] = '\0';
	return (para1 + para2);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*compact;

	len = (ft_strlen(s1) + ft_strlen(s2));
	compact = malloc(sizeof(char) * (len + 1));
	if (compact == 0)
	{
		return (NULL);
	}
	compact[0] = '\0';
	ft_strlcat(compact, s1, len + 1);
	ft_strlcat(compact, s2, len + 1);
	return (compact);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
