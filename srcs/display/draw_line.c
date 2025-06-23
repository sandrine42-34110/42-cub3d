/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:28:03 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:28:04 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (mlx->x0 == mlx->x1 && mlx->y0 == mlx->y1)
			break ;
		put_pixel(all->screen, mlx->x0, mlx->y0, mlx->color);
		draw_line_step(mlx, &b);
	}
}
