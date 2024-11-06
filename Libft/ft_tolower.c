/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:33:22 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 11:36:52 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c)
{
	int i;

	i = 0;
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}
/*
#include <stdio.h>

int main()
{
	int a = 65;
	int b = 90;
	int c = 58;
	
	printf("%c\n", ft_tolower(a));
	printf("%c\n", ft_tolower(b));
	printf("%c\n", ft_tolower(c));
	return (0);
}*/