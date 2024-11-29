/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:49:15 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/29 13:30:26 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	cal_len(unsigned int n)
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

static void	fill_string(char *str, unsigned int n, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		len--;
	}
	else
		len--;
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		len --;
		n /= 10;
	}
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = cal_len(n);
	str = malloc(len + 1);
	if (!str)
	{
		return (NULL);
	}
	fill_string(str, n, len);
	return (str);
}

int	ft_printuint(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (len == 0)
	{
		ft_putchar_fd('0', 1);
		len = 1;
	}
	else
	{
		num = ft_uitoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
