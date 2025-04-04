/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:36:37 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/03 11:58:23 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **map, int height, int width)
{
	char	**map_copy;
	int		i;

	(void)width;
	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
			{
				i--;
				free(map_copy[i]);
			}
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if (map[y][x] == data->content.wall || map[y][x] == 'V')
		return ;
	if (map[y][x] == data->content.collect)
		data->found_collect++;
	else if (map[y][x] == data->content.exit)
	{
		data->found_exit = 1;
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

int	ft_check_collect_access(char **map, t_data *data)
{
	char	**map_copy;

	data->found_collect = 0;
	data->found_exit = 0;
	map_copy = copy_map(map, data->height, data->width);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, data->pos.x, data->pos.y, data);
	free_map(map_copy, data->height);
	if (data->found_collect == data->content.count_c && data->found_exit)
		return (1);
	ft_error("Error\nAll collect not accessables\n");
	return (0);
}
