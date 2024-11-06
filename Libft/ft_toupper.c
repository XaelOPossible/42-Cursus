/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:07:15 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 11:33:05 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper(int c)
{
	int i;

	i = 0;
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
/*
#include <stdio.h>

int main()
{
	int a = 97;
	int b = 100;
	int c = 58;
	
	printf("%c\n", ft_toupper(a));
	printf("%c\n", ft_toupper(b));
	printf("%c\n", ft_toupper(c));
	return (0);
} */