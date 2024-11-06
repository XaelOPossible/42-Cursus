/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:55:43 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/05 17:05:17 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest2;
	const unsigned char *src2;
	size_t a;
	
	dest2 = (unsigned char *) dest;
	src2 = (const unsigned char *) src;
	a = 0;
	
	while (a < n)
	{
		dest2[a] = src2[a];
		a++;
	}
	return(dest);
}

int main ()
{
	char dest[10];
	const char *src = "ABCDEFGHIJ";
	int a = 0;
	
	ft_memcpy(dest, src, sizeof(src));
	while (dest[a])
	{
		printf("%c", dest[a]);
		a++;
	}
}