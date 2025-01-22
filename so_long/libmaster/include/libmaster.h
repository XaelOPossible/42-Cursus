/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:58 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/16 15:18:11 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFMASTER_H
# define LIBFMASTER_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int		ft_atoi(const char *nptr);
char	*ft_stradd(char *str, char buff);
int		gnl(int fd, char **str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_gnl(int fd);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_puthex(unsigned int num, const char type);
int		ft_printchar(int c);
void	ft_putstr(char *str);
int		ft_printptr(unsigned long long ptr);
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