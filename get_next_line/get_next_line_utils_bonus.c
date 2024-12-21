/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:30:26 by axemicha          #+#    #+#             */
/*   Updated: 2024/12/21 12:22:30 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *line)
{
	int	i;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
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
