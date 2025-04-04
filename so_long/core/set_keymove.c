/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keymove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:56:56 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/04 02:52:32 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_collect_pickup(t_data *data, int x, int y)
{
	if (data->map[y][x] == data->content.collect)
	{
		data->map[y][x] = data->content.space;
		data->collected++;
		data->content.count_c--;
	}
}

void	keymove_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.width;
	pos_y = data->pos.y / data->img.height;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		check_collect_pickup(data, pos_x, pos_y - 1);
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count : %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Great job you win : %d !\n", data->count);
				end(data);
			}
		}
	}
}

void	keymove_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.width;
	pos_y = data->pos.y / data->img.height;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		check_collect_pickup(data, pos_x, pos_y + 1);
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count : %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Great job you win : %d !\n", data->count);
				end(data);
			}
		}
	}
}

void	keymove_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.width;
	pos_y = data->pos.y / data->img.height;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		check_collect_pickup(data, pos_x + 1, pos_y);
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count : %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Great job you win : %d !\n", data->count);
				end(data);
			}
		}
	}
}

void	keymove_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.width;
	pos_y = data->pos.y / data->img.height;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		check_collect_pickup(data, pos_x - 1, pos_y);
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count : %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Great job you win : %d !\n", data->count);
				end(data);
			}
		}
	}
}
