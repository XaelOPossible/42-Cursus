/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:30:57 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/08 15:32:05 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*compact;

	len = (ft_strlen(s1) + ft_strlen(s2));
	compact = malloc(sizeof(char) * (len + 1));
	if (compact == 0)
	{
		return (NULL);
	}
	compact[0] = '\0';
	ft_strlcat(compact, s1, len + 1);
	ft_strlcat(compact, s2, len + 1);
	return (compact);
}
