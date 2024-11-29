/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_uplow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:01:07 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/29 12:17:06 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int ft_hexlen(unsigned int num)
{
    int len;
    
    len = 0;
    while (!num)
    {
        len++;
        num /= 16;
    }
    return(len);
}

void    ft_puthex(unsigned int num, const char type)
{
    if (num >= 16)
    {
        ft_put_hex((num / 16), type);
        ft_put_hex((num % 16), type);
    }
    else
    {
        if (num <= 9)
            ft_putchar_fd((num + '0'), 1);
        else
            if (type == 'x')
                ft_putchar_fd((num - 10 + 'a'), 1);
            if (type == 'X')
                ft_putchar_fd((num - 10 + 'A'), 1);
    }
}

int ft_printhex_uplow(unsigned int num, const char type)
{
    if (num == 0)
        return  (write(1, '0', 1));
    else
        ft_puthex(num, type);
    return (ft_hexlen(num));
}