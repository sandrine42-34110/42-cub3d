#include "cub3d.h"

void	init_draw_vars(t_mlx *mlx, t_bresenham *b)
{
	b->dx = abs(mlx->x1 - mlx->x0);
	b->dy = abs(mlx->y1 - mlx->y0);
	if (mlx->x0 < mlx->x1)
		b->sx = 1;
	else
		b->sx = -1;
	if (mlx->y0 < mlx->y1)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
}

void	draw_line_step(t_mlx *mlx, t_bresenham *b)
{
	int	e2;

	e2 = 2 * (b->err);
	if (e2 > -b->dy)
	{
		b->err -= b->dy;
		mlx->x0 += b->sx;
	}
	if (e2 < b->dx)
	{
		b->err += b->dx;
		mlx->y0 += b->sy;
	}
}

void	draw_line(t_all *all, t_mlx *mlx)
{
	t_bresenham	b;

	init_draw_vars(mlx, &b);
	while (1)
	{
		put_pixel(all->screen, mlx->x0, mlx->y0, mlx->color);
		if (mlx->x0 == mlx->x1 && mlx->y0 == mlx->y1)
			break ;
		draw_line_step(mlx, &b);
	}
}

/* void draw_line(t_all *all, t_mlx *mlx)
{
	int dx = abs(mlx->x1 - mlx->x0);
	int dy = -abs(mlx->y1 - mlx->y0);
	int	sx;
	int sy;
	int err = dx + dy;
	int e2;

	if (mlx->x0 < mlx->x1)
		sx = 1;
	else
		sx = -1;
	if (mlx->y0 < mlx->y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		put_pixel(all->screen, mlx->x0, mlx->y0, all->mlx->color);
		if (mlx->x0 == mlx->x1 && mlx->y0 == mlx->y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			mlx->x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			mlx->y0 += sy;
		}
	}
} */