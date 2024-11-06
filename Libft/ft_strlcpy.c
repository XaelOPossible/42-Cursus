/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:25 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/05 18:03:40 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (src[count])
	{
		count++;
	}
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dst[i] = '\0';
	}
	return (count);
}