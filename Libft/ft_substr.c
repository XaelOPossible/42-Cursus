/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:53:07 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/09 16:14:21 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static char *handle_empty_substr()
{
	char *news = malloc(1);
	if (news == NULL)
		return (NULL);
	news[0] = '\0';
	return (news);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	n;
	size_t s_len;

	if (!s)
		return (NULL);
	s_len = (ft_strlen(s));
	if (start >= s_len)
		return handle_empty_substr();
	if (len > s_len - start)
		len = s_len - start;
	news = malloc((len + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	n = 0;
	while (n < len)
	{
		news[n] = s[start + n];
		n++;
	}
	news[n] = '\0';
	return (news);
}
