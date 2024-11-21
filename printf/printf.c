/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:59:05 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/13 15:47:09 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int printf(const char *type, ...)
{
    va_list args;
    va_start (args, type);
    while (*type)
    {
        if (*type == '%')
        {
            type++;
            if (*type == 'c')
            {
                char c;
                c = va_arg (args, char);
                ft_putchar(c);
                break;
            }
            if (*type == 's')
            {
                char s;
                s = va_arg (args, char *);
                ft_putchar(s);
                break;
            }
            if (*type == 'p')
            {
                void *v;
                v = va_arg (args, void *);
                ft_print_hexadecimal(v);
                break;
            }
            if (*type == 'd')
            {
                int d;
                d = va_arg (args, int);
                ft_putnbr(d);
                break;
            }
            if (*type == 'i')
            {
                int i;
                i = va_arg (args, int);
                ft_putnbr(i);
                break;
            }
        }
    }
}
///
