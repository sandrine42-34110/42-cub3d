#include "cub3d.h"

void	draw_ceiling(t_all *all)
{
	int	x;
	int	y;
	int	color;

	color = ((all->text->ceiling_r << 16) | (all->text->ceiling_g << 8) | (all->text->ceiling_b));
	y = 0;
	while (y < H_WIN / 2)
	{
		x = 0;
		while (x < W_WIN)
		{
			// mlx_pixel_put(all->mlx->mlx_ptr, all->mlx->win_ptr,
			// 	x, y, color);
			put_pixel(all->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_all *all)
{
	int	x;
	int	y;
	int	color;

	color = ((all->text->floor_r << 16) | (all->text->floor_g << 8) | (all->text->floor_b));
	y = H_WIN / 2;
	while (y < H_WIN)
	{
		x = 0;
		while (x < W_WIN)
		{
			// mlx_pixel_put(all->mlx->mlx_ptr, all->mlx->win_ptr,
			// 	x, y, color);
			if ((y >= H_WIN - all->minimap->map_height_px + 1) && (x > W_WIN - all->minimap->map_width_px))
				break ;
			else
				put_pixel(all->img, x, y, color);
			x++;
		}
		y++;
	}
}
void	draw_3d(t_all *all)
{
	draw_ceiling(all);
	draw_floor(all);
	//draw_walls(all);
}
