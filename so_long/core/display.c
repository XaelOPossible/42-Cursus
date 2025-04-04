/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:23:58 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/04 02:48:31 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_collectibles(t_data *data)
{
	char	*got;
	char	*total;
	char	*temp;
	char	*display;

	got = ft_itoa(data->collected);
	total = ft_itoa(data->collected + data->content.count_c);
	temp = ft_strjoin(got, " / ");
	free(got);
	display = ft_strjoin(temp, total);
	free(temp);
	free(total);
	temp = ft_strjoin("Collectibles : ", display);
	free(display);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, 20, 0xFFFFFF, temp);
	free(temp);
}
