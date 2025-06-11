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

void	draw_3d(t_all *all)
{
	//draw_floor(all);
	draw_ceiling(all);
	//draw_walls(all);
}
