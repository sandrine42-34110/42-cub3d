#include "cub3d.h"

void	draw_vision_line(t_all *all)
{
	all->raycast->px = all->player->x;
	all->raycast->py = all->player->y;
	dda_cast(all);
	draw_walls(all);
	all->mlx->x0 = all->minimap->offset_x
		+ all->raycast->px * all->mlx->tile_size;
	all->mlx->y0 = all->minimap->offset_y
		+ all->raycast->py * all->mlx->tile_size;
	all->mlx->x1 = all->minimap->offset_x
		+ all->raycast->ray_x * all->mlx->tile_size;
	all->mlx->y1 = all->minimap->offset_y
		+ all->raycast->ray_y * all->mlx->tile_size;
	all->mlx->color = 0x0000FF;
	draw_line(all, all->mlx);
}

void	draw_vision_cone(t_all *all)
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = cos(all->player->or);
	dir_y = sin(all->player->or);
	plane_x = -dir_y * tan(90.0 * M_PI / 360.0);
	plane_y = dir_x * tan(90.0 * M_PI / 360.0);

	all->raycast->pos_px_x = 0;
	while (all->raycast->pos_px_x < W_WIN)
	{
		camera_x = 2.0 * all->raycast->pos_px_x / W_WIN - 1.0;
		all->raycast->ray_dir_x = dir_x + plane_x * camera_x;
		all->raycast->ray_dir_y = dir_y + plane_y * camera_x;
		draw_vision_line(all);
		all->raycast->pos_px_x++;
	}
}
