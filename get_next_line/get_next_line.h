/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:19:11 by axemicha          #+#    #+#             */
/*   Updated: 2024/12/07 10:57:26 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE 42
# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		get_line_len(char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *line);
char	*read_fd(int fd, char *src);
char *ft_line(char *buffer);
char	*next_line(char *buffer);
char *free_line(char *buffer, char *buff);

#endif
#endif