/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:11:33 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/16 14:38:02 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	len_map()
{
	int len;
	int	fd;
	char *line;
	
	len = 0;
	fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

int one_on_line(const char *line)
{
	while(*line)
	{
		if (*line != '1' && *line != '\n')
			return 0;
		line++;
	}
	return 1;
}

int start_finish_one(const char *line)
{
	size_t len = ft_strlen(line);
	
	if (line[len - 1] == '\n')
        len--;
	if (len < 2)
		return 0;
	if (line[0] != '1' || line[len - 1] != '1')
		return 0;
	return 1;
}

int verif_map(int fd)
{
	int		len;
    char    *line;
    int     line_number = 0;
    int     valid = 1;

	len = len_map();
	line = get_next_line(fd);
	while (line)
    {
        line_number++;
		if (line_number == len)
			break;
        if (line_number == 1)
        {
            if (!one_on_line(line))
            {
                ft_printf("Erreur : La première ligne n'est pas composée uniquement de '1'.\n");
                valid = 0;
            }
        }
        else
		{
			if (!start_finish_one(line))
        	{
            	ft_printf("Erreur : La ligne %d ne commence pas et ne finit pas par '1'.\n", line_number);
            	valid = 0;
        	}	
		}
		free(line);
		line = get_next_line(fd);
    }
	if(!one_on_line(line))
	{
        ft_printf("Erreur : La derniere ligne n'est pas composée uniquement de '1'.\n");
        valid = 0;
    }
	free(line);
    if (valid)
        ft_printf("Check Map valide\n");
    else
        ft_printf("Check Map invalide\n");
    return (0);
}

int	ft_strlen_check(char *str)
{
	int i;

	i = 0;
	while(*str)
	{
		if (*str != 1 || *str != 0
				|| *str != 'E' || *str != 'P'
				|| *str != 'C') // peut devenir != 1 != 0 != E != P != C
			break;
		i++;
		str++;
	}
	return (i);
}
int	is_rectangular(int fd)
{
	int len;
	int	len_line;
	char *line;

	line = get_next_line(fd);
	len = ft_strlen_check(line);
	free(line);
	line = get_next_line(fd);
	while(line)
	{
		len_line = ft_strlen_check(line);
		if (len_line != len)
		{
			ft_printf("Check Map forme invalide\n");
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("Check map forme valide\n");
	return (0);
}
