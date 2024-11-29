/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:47:09 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/09 14:07:40 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	v;

	v = n;
	if (v == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (v < 0)
	{
		v *= -1;
		ft_putchar_fd('-', fd);
	}
	if (v >= 10)
	{
		ft_putnbr_fd(v / 10, fd);
		ft_putnbr_fd(v % 10, fd);
	}
	else
		ft_putchar_fd(v + '0', fd);
}
