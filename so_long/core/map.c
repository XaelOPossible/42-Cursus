/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:15:45 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/03 09:30:47 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = gnl(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = gnl(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	free(buff);
	ft_error("Error\nWrong lecture map\n");
	return (NULL);
}

void	parse_map_content(t_data *data)
{
	int	x;
	int	y;

	data->content.count_p = 0;
	data->content.count_c = 0;
	data->content.count_e = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == data->content.player)
			{
				data->pos.x = x;
				data->pos.y = y;
				data->content.count_p++;
			}
			if (data->map[y][x] == data->content.collect)
				data->content.count_c++;
			if (data->map[y][x] == data->content.exit)
				data->content.count_e++;
		}
	}
}

char	**parse_mapt(t_data *data)
{
	int	i;

	i = 1;
	ft_check_content(data);
	if (!ft_check_format(data->map))
		return (ft_free_map(data));
	if (!ft_check_line(data->map[0], data->content.wall))
		return (ft_free_map(data));
	while (data->map[i] != NULL)
	{
		if (!ft_check_col(data->map[i], data->content.wall, data))
			return (ft_free_map(data));
		else if (!ft_check_other(data->map[i], &(data->content)))
			return (ft_free_map(data));
		i++;
	}
	data->height = i;
	if (!ft_check_line(data->map[i - 1], data->content.wall))
		return (ft_free_map(data));
	parse_map_content(data);
	if (!ft_check_collect_access(data->map, data))
		return (ft_free_map(data));
	return (data->map);
}

char	**parse_map(int fd, t_data *data)
{
	char	*raw_map;

	raw_map = get_map(fd);
	if (!raw_map)
		return (NULL);
	data->map = ft_split(raw_map, '\n');
	free(raw_map);
	if (!data->map)
		return (NULL);
	return (parse_mapt(data));
}

char	**map_core(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr2(str[1], ".ber") == 0)
		return (ft_error("Error\nNo correct format map founded\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (ft_error("Error\nFailed to open file\n"));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			ft_free_map(data);
			return (ft_error("Error\nNeed 1 Player/Exit, mini 1 object\n"));
		}
	}
	return (data->map);
}
