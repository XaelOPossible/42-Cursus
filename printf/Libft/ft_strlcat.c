/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:07:33 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/09 16:23:23 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	para1;
	size_t	para2;

	i = 0;
	para1 = ft_strlen(dst);
	para2 = ft_strlen(src);
	if (size <= para1)
		return (para2 + size);
	while (src[i] != '\0' && para1 + i < size - 1)
	{
		dst[para1 + i] = src[i];
		i++;
	}
	dst[para1 + i] = '\0';
	return (para1 + para2);
}
