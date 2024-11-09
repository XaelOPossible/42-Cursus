/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:30 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/09 16:33:04 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char target;
	size_t			a;

	target = (unsigned char)c;
	s1 = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		if (s1[a] == target)
		{
			return ((void *)&s1[a]);
		}
		a++;
	}
	return (NULL);
}
