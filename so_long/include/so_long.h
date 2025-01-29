/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:51:10 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/29 15:02:41 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libmaster/include/libmaster.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct element_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_element;

typedef struct pos_s
{
	int		x;
	int		y;	
}	t_pos;

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_player_death;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*player_death;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}	t_img;

typedef struct data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	char		**map;
	t_element	content;
	t_img		img;
	t_pos		pos;
	int			count;
}				t_data;

int		one_on_line(const char *line);
int		start_finish_one(const char *line);
int		verif_map();
void	*ft_error(char *str);
int		ft_same_char(char *str);
int		ft_strchr2(char *str, char *cmp);

int		ft_same_char(char *str);
char	*get_map(int fd);
char	**map_core(char **str, t_data *data);
int		chk_map(char **argv);

int		ft_check_col(char *map_line, char col, t_data *data);
int		ft_check_line(char *map_line, char wall);
int		ft_check_other(char *map_line, t_element *content);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);
int		chk_collect(t_data *data);
int 	ft_check_lockce(char **map);

void	set_img(t_data *data);
void	set_elements(t_element *content);

void	core_render(t_data *data);
int		render(t_data *data);
void	render_other(t_data *data);
void	render_background(t_data *data);
void	keymove_down(t_data *data);
void	keymove_left(t_data *data);
void	keymove_right(t_data *data);
void	keymove_top(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

int		key_press(int keysym, t_data *data);
int		chk_collect(t_data *data);
int		end(t_data *data);

#endif