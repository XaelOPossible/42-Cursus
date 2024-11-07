/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:27:05 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/07 16:06:07 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	const char *string = "Hello World";
	const char *find = "ld";
	
	printf("%s\n", ft_strnstr(string, find, ft_strlen(string)));
	printf("\nFin de test de la fonction ft_strnstr\n\n");

////////////////////////////////////////////////////////////////////////////////////////

	const char *t1 = "----1234";
	const char *t2 = "    b+1234";
	const char *t3 = "123aa45";
	
	printf("Debut test fonction ft_atoi :\n");
	printf("%d\n", ft_atoi(t1));
	printf("%d\n", ft_atoi(t2));
	printf("%d\n", ft_atoi(t3));

////////////////////////////////////////////////////////////////////////////////////////

	char const *str = "Hello World";
	size_t lent = 0;
	printf("%s\n", ft_substr(str, 6, 0));
}