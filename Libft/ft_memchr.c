/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:30 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 16:57:31 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s1;
	size_t a;
	
	s1 = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		if (s1[a] == (char)c)
		{
			return (&s1[a]);
		}
		a++;
	}
	if (s1[a] == '\0')
	{
		return (&s1[a]);
	}
	return (NULL);
}


int main ()
{
	const char *src = "ABCDEFGHIJ";
	int a = 0;
	char c = 0;
	
	printf("%s\n", (char *)ft_memchr(src, c, 11));
	return(0);
}