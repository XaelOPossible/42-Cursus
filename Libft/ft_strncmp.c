/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:32:22 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 13:56:06 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

/*
#include <stdio.h>

int main()
{
	const char p1[] = "La";
	const char p2[] = "a";
	size_t i = 2;
	
	printf("%d", ft_strncmp(p1, p2, i));
	return(0);
}*/