/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:53:07 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/07 16:28:45 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	n;

	n = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) > start + len)
		news = malloc((len + 1) * sizeof(char));
	else
		news = malloc(((ft_strlen(s) + 1) - start) * sizeof(char));
	if (news == NULL)
		return (NULL);
	while (n < len)
	{
		news[n] = s[start + n];
		n++;
	}
	news[n] = 0;
	return (news);
}
