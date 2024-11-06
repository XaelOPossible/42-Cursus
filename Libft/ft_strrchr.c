/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:18:29 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 13:32:03 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
	const char *dn_occu = NULL;
	
 	while (*s)
	{
		if (*s == c)
		{
			dn_occu = (char *)s;
		}
		s++;
	}
	if (c == '\0')
	{
        return ((char *)s);
	}
	return ((char *)dn_occu);
}

#include <stdio.h>

int main()
{
	const char str[] = "Hello, World";
	char c = 'd';
	printf("%s\n", ft_strrchr(str, c));
	return (0);
}