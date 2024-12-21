/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:18:29 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/12 11:13:35 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	src = (char *) s;
	while (*src)
		src++;
	if ((unsigned char)c == '\0')
		return (src);
	while (src >= s)
	{
		if (*src == (unsigned char)c)
			return (src);
		src--;
	}
	return (NULL);
}
