/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:07:33 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 10:42:17 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t para1;
	size_t para2;

	i = 0;
	para1 = ft_strlen(dst);
	para2 = ft_strlen(src);
	if (size - 1 <= para1)
		return (para2 + size);
	while (para1 + i < size - 1)
	{
		dst[para1 + i] = src[i];
		i++;
	}
	dst[para1 + i] = '\0';
	return (para1 + para2);
}
int main()
{
	char *dest = "En rose";
	const char *src= "La vie";
      
	printf("%zu", strlcat(dest, src, sizeof(dest)));
	return (0);
}
