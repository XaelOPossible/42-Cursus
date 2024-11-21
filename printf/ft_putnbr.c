/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:53:54 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/19 13:02:22 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_putnbr(int nb)
{
    int i;

    i = nb;
    if (i == -2147483648)
        ft_putstr("-2147483648");
    if (nb < 0)
    {
        i *= -1;
        ft_putchar('-');
    }
    if (nb >= 10)
    {
        ft_putnbr(i / 10);
        ft_putnbr(i % 10);
    }
    else
        ft_putchar(i + '0');
}
