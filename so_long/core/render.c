/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:37:02 by axemicha          #+#    #+#             */
/*   Updated: 2025/03/28 11:02:03 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_background(t_data *data)
{
	int	i;
	int	y;

	if (!data || !data->map)
		return ;
	y = 0;
	while (data->map[y] != NULL)
	{
		i = 0;
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall && data->img.img_wall)
				print_img(data, data->img.img_wall, i, y);
			else if (data->map[y][i] == data->content.space
				&& data->img.img_floor)
				print_img(data, data->img.img_floor, i, y);
			i++;
		}
		y++;
	}
}

void	render_other(t_data *data)
{
	int	i;
	int	y;

	if (!data || !data->map)
		return ;
	y = 0;
	while (data->map[y] != NULL)
	{
		i = 0;
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.collect && data->img.img_c)
				print_img(data, data->img.img_c, i, y);
			if (data->map[y][i] == data->content.player && data->img.img_p)
			{
				data->pos.x = i * data->img.width;
				data->pos.y = y * data->img.height;
				print_img(data, data->img.img_p, i, y);
			}
			if (data->map[y][i] == data->content.exit && data->img.img_exit)
				print_img(data, data->img.img_exit, i, y);
			i++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	if (!data || !data->mlx_ptr || !data->mlx_win)
		return (0);
	render_background(data);
	render_other(data);
	return (0);
}

void	core_render(t_data *data)
{
	if (!data || !data->mlx_ptr)
	{
		ft_printf("Erreur : données non initialisées\n");
		return ;
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width),
			(data->height * data->img.height), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		ft_printf("Erreur : fenêtre non créée\n");
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	ft_printf("Début de la boucle principale\n");
	mlx_loop(data->mlx_ptr);
	ft_printf("Fin de la boucle principale\n");
	end(data);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	if (!data || !data->mlx_ptr || !data->mlx_win || !img)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
