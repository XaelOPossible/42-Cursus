/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:37:07 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 12:16:18 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

#include <stdio.h>

int main()
{
	const char str[] = "Hello, World";
	char c = 'a';
	printf("%s\n", ft_strchr(str, c));
	return (0);
}