/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:49:55 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/16 15:23:44 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_elements(t_element *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}
void	set_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./rsrc/floor_texture.xpm";
	data->img.wall = "./rsrc/wall_texture.xpm";
	data->img.collect = "./rsrc/collect.xpm";
	data->img.player = "./rsrc/mario_player.xpm";
	data->img.exit = "./rsrc/exit_texture.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}