/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:19:11 by axemicha          #+#    #+#             */
/*   Updated: 2024/12/27 10:38:54 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#define DEBUG 1
#if DEBUG
# define LOG(msg, ...) printf("[DEBUG] " msg "\n", ##__VA_ARGS__)
#else
# define LOG(msg, ...)
#endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *line);
char	*get_next_line(int fd);
char	*ft_line(char *buffer);
char	*read_fd(int fd, char *src);
char	*next_line(char *buffer);
char	*free_line(char *buffer, char *buff);

#endif