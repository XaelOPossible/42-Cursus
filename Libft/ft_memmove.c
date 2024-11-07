/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:17:53 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/07 18:05:45 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;
	size_t				a;
	
	dest2 = (unsigned char *) dest;
	src2 = (const unsigned char *) src;
	a = 0;
	if (dest2 > src2)
	{
		while(n)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
		return (dest);
	}
	else
	{
		while (a < n)
		{
			dest2[n] = src2[n];
			a++;
		}
		return (dest);
	}
}
