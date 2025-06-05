#include "cub3d.h"

int	check_map_name(char *str)
{
	int	len_name_file;

	len_name_file = ft_strlen(str);
	if (ft_strcmp(".cub",str + len_name_file - 4) == 0)
		return(1);
	ft_putstr_fd("Error : Name map isn't in .cub\n", 2);
	return (0);
}

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
	map->or_p = 0;
	return (map);
}

int	tile_size(t_all *all)
{
	int	size_w;
	int	size_h;

	size_w = W_WIN / (5 * all->map->w_map);
	size_h = H_WIN / (5 * all->map->h_map);
	return (fmin(size_w, size_h));
}

void	load_images(t_all *all)
{
	all->mlx->img_w_n = mlx_xpm_file_to_image(all->mlx->mlx_ptr, \
						all->text->no, &mlx->img_width, &mlx->img_height);
}

t_mlx	*init_mlx(t_all *all)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
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
	// mlx->player_x = 0;
	// mlx->player_y = 0;
	if (!load_images(all))
		error_and_close_all("Error : Texture isn't exist\n", all);
	return (mlx);
}
