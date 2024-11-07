/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:34 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/07 17:12:14 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*ptr;
	unsigned char	value;

	value = ((unsigned char) c);
	ptr = s;
	a = 0;
	while (a < n)
	{
		ptr[a] = value;
		a++;
	}
	return (ptr);
}