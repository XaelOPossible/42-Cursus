/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:26:37 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/19 13:27:36 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin_safe(s1, s2);
	free(s1);
	return (res);
}

char	*ft_strjoin_safe(char *s1, char *s2)
{
	char	*res;
	size_t	len1 = s1 ? ft_strlen(s1) : 0;
	size_t	len2 = s2 ? ft_strlen(s2) : 0;
	size_t	i = 0;

	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	if (s1)
		while (*s1)
			res[i++] = *s1++;
	if (s2)
		while (*s2)
			res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
