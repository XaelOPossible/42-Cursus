/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 00:59:02 by jaleman           #+#    #+#             */
/*   Updated: 2025/03/14 10:45:48 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		nbr;

	if (argc == 2)
	{
		i = 1;
		nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("1");
		while (nbr >= ++i)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				if (nbr == i)
					break ;
				printf("*");
				nbr /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}
