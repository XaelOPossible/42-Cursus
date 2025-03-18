/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:11:20 by axemicha          #+#    #+#             */
/*   Updated: 2025/03/14 13:25:47 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strrev(char *str)
{
	int	len;
	int i;
	char a;

	len = 0;
	while (str[len])
		len++;
	i = -1;
	while(++i < --len)
	{
		a = str[i];
		str[i] = str[len];
		str[len] = a;
	}
	return(str);
}

int main()
{
	char test1[] = "lalo"; 
	char test2[] = "olal";
	int i = 0;
	ft_strrev(test1);
	while (test1[i])
	{
		printf("%c", test1[i]);
		i++;		
	}
	printf("\n");
	ft_strrev(test2);
	i = 0;
	while (test2[i])
	{
		printf("%c", test2[i]);
		i++;		
	}
	printf("\n");
}