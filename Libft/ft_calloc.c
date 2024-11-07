/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:42 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/07 16:34:41 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	char			*tab;

	i = nmemb * size;
	if ((tab = malloc(i)) == NULL)
		return (NULL);
	ft_memset(tab, 0, i);
	return (tab);
}
