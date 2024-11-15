/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:03:03 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/13 15:54:25 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void printf_perc_c(char c)
{
	write(1, &c, 1);
}

void printf_perc_string(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str, 1);
	}
}

void printf_perc_p(void *element)
{
	
}
