/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:21:59 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/29 11:57:29 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void    ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
        i++;
	}
}

int ft_printstr(char *str)
{
    int i;
    
    i = 0;
    if (str == NULL)
        ft_putstr("(null)");
        return (6);
    while (str[i])
	{
		write(1, &str[i], 1);
        i++;
	}
    return (i);
}

int ft_printnbr(int n)
{
    int     len;
    char    *num;

    len = 0;
    num = ft_itoa(n);
    len = ft_printstr(num);
    free(num);
    return(len);
}

int ft_print_percent(void)
{
    write(1, '%', 1);
    return (1);
}