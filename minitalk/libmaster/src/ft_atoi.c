/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:21:45 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/08 15:34:35 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmaster.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	num;

	neg = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			neg *= -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * neg);
}
