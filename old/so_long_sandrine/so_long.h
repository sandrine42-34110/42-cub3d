/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:42:58 by sapupier          #+#    #+#             */
/*   Updated: 2025/03/06 12:12:15 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define KEY_W_UP		119
# define KEY_S_DOWN		115
# define KEY_A_LEFT		97
# define KEY_D_RIGHT	100
# define KEY_ESCAPE		65307

# define TILE_SIZE 	64

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	t_point	pos;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	int		collectibles;
	int		find_exit;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigh;
}			t_img;

typedef struct s_person
{
	void	*img_ptr;
	int		width;
	int		heigh;
}			t_person;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		game_map;
	t_img		img;
	t_img		backgrd;
	t_img		door;
	t_img		collect;
	t_img		wall;
	t_person	person;
	t_person	perso;
	t_player	player;
	t_person	exit;
	int			window_width;
	int			window_height;
	int			tile_size;
	int			exit_count;
	int			item_count;
	int			start_count;
}				t_vars;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		my_new_img(t_vars *vars);
char	**init_map(const char *file_path);
int		open_file(const char *file_path);
char	**read_map(const char *file_path);
int		check_borders(char **map);
int		check_characters(t_vars vars, char **map);
void	free_map(char **map);
int		read_and_verify_map(int fd, char **map);
int		validate_map(t_vars vars, char **map, int *rows, int *cols);
void	get_map_dimensions(char **map, int *rows, int *cols);
void	free_map_(t_map *map);
int		verify_path(t_map *map);
void	flood_fill(t_map *map, int x, int y);
int		find_start(t_map *map, int *start_x, int *start_y);
int		key_hook(int keycode, t_vars *vars);
int		is_valid_move(t_vars *vars, int new_x, int new_y);
void	collect_item(t_vars *vars, int new_x, int new_y);
void	try_exit(t_vars *vars, int new_x, int new_y);
int		movement(int keycode, int *new_x, int *new_y);
void	move_player(t_vars *vars, int keycode);
int		close_window(t_vars *vars);
void	display_map(t_vars *vars, t_map *game_map);
void	display_door(t_vars *vars);
int		init_mlx(t_vars *vars, t_map *game_map);
int		load_images(t_vars *vars);
int		count_collectibles(t_map *map);

#endif
