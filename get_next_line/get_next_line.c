/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:56:01 by axemicha          #+#    #+#             */
/*   Updated: 2024/12/19 16:25:02 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *free_line(char *buffer, char *buff)
{
    char *tmp;

    if (!buffer)
        buffer = ft_calloc(1, 1);
    tmp = ft_strjoin(buffer, buff);
    free(buffer);
    return (tmp);
}

char *next_line(char *buffer)
{
    int i = 0;
    int j = 0;
    char *result;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    result = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
    i++;
    while (buffer[i])
        result[j++] = buffer[i++];
    free(buffer);
    return (result);
}

char *ft_line(char *buffer)
{
    char *line;
    int i = 0;

    if (!buffer || !buffer[i])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i] = '\n';
    return (line);
}

char *read_fd(int fd, char *src)
{
    char *buffer;
    int buffer_read;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    buffer_read = 1;
    while (buffer_read > 0)
    {
        buffer_read = read(fd, buffer, BUFFER_SIZE);
        if (buffer_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[buffer_read] = '\0';
        src = free_line(src, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (src);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_fd(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = next_line(buffer);
    return (line);
}


