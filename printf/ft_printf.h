/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:07:41 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/13 15:31:34 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_puthex(unsigned int num, const char type);
int		ft_printchar(char c);
void	ft_putstr(char *str);
int		ft_print_hexadecimal(void *ptr);
int		ft_print_percent(void);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printuint(unsigned int n);
int		ft_printhex_uplow(unsigned int num, const char type);
void	ft_puthex(unsigned int num, const char type);
int		ft_hexlen(unsigned int num);
int		ft_print_arg(va_list args, const char type);
int		ft_printf(const char *str, ...);

#endif