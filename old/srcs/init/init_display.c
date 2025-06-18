#include "cub3d.h"

t_minimap	*init_minimap(t_all *all)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		error_and_close_all("Error : malloc minimap failed!", all);
	minimap->map_width_px = 0;
	minimap->map_height_px = 0;
	minimap->offset_x = 0;
	minimap->offset_y = 0;
	return (minimap);
}

t_player	*init_player(t_all *all)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_and_close_all("Error : malloc player failed!", all);
	player->dx = 0;
	player->dy = 0;
	player->d_or = 0;
	player->x = all->map->x_p + 0.5;
	player->y = all->map->y_p + 0.5;
	player->or = begin_dir_pl(all->map->or_p);
	return (player);
}

t_img	*init_screen(t_all *all)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		error_and_close_all("Error : malloc image failed!", all);
	img->img = mlx_new_image(all->mlx->mlx_ptr, W_WIN, H_WIN);
	if (!img->img)
		error_and_close_all("Error : create image failed!", all);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
		&img->line_length, &img->endian);
	return (img);
}

