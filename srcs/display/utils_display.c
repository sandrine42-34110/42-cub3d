#include "cub3d.h"

void	draw_square(t_all *all, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(all->mlx->mlx_ptr, all->mlx->win_ptr,
				x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_mlx *mlx, int cx, int cy, int radius, int color)
{
	int x = -radius;
	int y;
	int sqr_radius = radius * radius;

	while (x <= radius)
	{
		y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= sqr_radius)
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,
					cx + x, cy + y, color);
			y++;
		}
		x++;
	}
}

