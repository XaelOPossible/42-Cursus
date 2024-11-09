/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:10:05 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/09 14:15:49 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *str, int n, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		len--;
	}
	else
	{
		len--;
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		len --;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	len = cal_len(n);
	str = malloc(len + 1);
	if (!str)
	{
		return (NULL);
	}
	fill_string(str, n, len);
	return (str);
}
