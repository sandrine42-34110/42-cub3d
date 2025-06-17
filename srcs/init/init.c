#include "cub3d.h"

t_text	*init_text(void)
{
	t_text *text;

	text = malloc(sizeof(t_text));
	if (!text)
		return (NULL);
	text->no = NULL;
	text->so = NULL;
	text->we = NULL;
	text->ea = NULL;
	text->floor_r = 0;
	text->floor_g = 0;
	text->floor_b = 0;
	text->ceiling_r = 0;
	text->ceiling_g = 0;
	text->ceiling_b = 0;
	text->floor = 0;
	text->ceiling = 0;
	return (text);
}

t_all	*init_all(int argc, char **argv)
{
	t_all	*all;

	if (argc != 2)
	{
		ft_putstr_fd("Error : Usage : ./philo [map_name].cub\n", 2);
		return (NULL);
	}
	if(!check_map_name(argv[1]))
		return (NULL);
	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->text = init_text();
	all->map = init_map();
	if (!all->text || !all->map)
	{
		free_text_and_map(all);
		return (NULL);
	}
	all->height_file = 0;
	all->pos_line_read_file = 0;
	return (all);
}

t_map	*init_map(void)
{
	t_map	*map;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->line = NULL;
	map->h_map = 0;
	map->w_map = 0;
	map->x_p = 0;
	map->y_p = 0;
	map->or_p = '\0';
	return (map);
}

/* 
void	load_images(t_all *all)
{
	all->mlx->img_w_n = mlx_xpm_file_to_image(all->mlx->mlx_ptr, \
						all->text->no, &mlx->img_width, &mlx->img_height);
}
 */

t_raycast	*init_raycast(t_all *all)
{
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		error_and_close_all("Error : raycast malloc failed!\n", all);
	raycast->pos_px_x = 0;
	raycast->px = 0;
	raycast->px = 0;
	raycast->ray_dir_x = 0;
	raycast->ray_dir_y = 0;
	raycast->ray_x = 0;
	raycast->ray_y = 0;
	raycast->start_x = 0;
	raycast->start_y = 0;
	raycast->end_x = 0;
	raycast->end_y = 0;
	return (raycast);
}

t_mlx	*init_mlx(t_all *all)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		error_and_close_all("Error : mlx malloc failed!\n", all);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error_and_close_all("Error : MiniLibX initialization failed!", all);
	if (W_WIN == 0 || H_WIN == 0)
		error_and_close_all("Error : bad size of window\n", all);
	mlx->w_win = W_WIN;
	mlx->h_win = H_WIN;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w_win, mlx->h_win, TITLE);
	if (!mlx->win_ptr)
		error_and_close_all("Error : Failed to create window\n", all);
	mlx->tile_size = tile_size(all);
	all->minimap = init_minimap(all);
	all->player = init_player(all);
	all->raycast = init_raycast(all);
	return (mlx);
}


