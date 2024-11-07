/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:30 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/07 17:56:09 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			a;

	s1 = (unsigned char *)s;
	a = 0;
	while (a < n - 1)
	{
		if (s1[a] == (unsigned char)c)
		{
			return (&s1[a]);
		}
		a++;
	}
	if (s1[a] == '\0')
	{
		return ((void *)&s1[a]);
	}
	return (NULL);
}
