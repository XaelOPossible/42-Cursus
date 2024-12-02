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

#include "libft.h"
#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_arg(va_list args, const char type)
{
	int	print_type;

	print_type = 0;
	if (type == 'c')
		print_type += ft_printchar(va_arg (args, int));
	else if (type == 's')
		print_type += ft_printstr(va_arg (args, char *));
	else if (type == 'p')
		print_type += ft_printptr(va_arg (args, unsigned long long));
	else if (type == 'd' || type == 'i')
		print_type += ft_printnbr(va_arg (args, int));
	else if (type == 'u')
		print_type += ft_printuint(va_arg (args, unsigned int));
	else if (type == 'x' || type == 'X')
		print_type += ft_printhex_uplow(va_arg (args, unsigned int), type);
	else if (type == '%')
		print_type += ft_print_percent();
	return (print_type);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_print_arg(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
