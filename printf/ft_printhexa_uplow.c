/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_uplow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:01:07 by axemicha          #+#    #+#             */
/*   Updated: 2024/12/21 11:09:20 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char type)
{
	if (num >= 16)
	{
		ft_puthex(num / 16
		ft_puthex(num % 16
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0')
		else
		{
		
				ft_putchar_fd((num - 10 + 'a')
	}
}

int	ft_printhex_uplow(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, type);
	return (ft_hexlen(num));
}
