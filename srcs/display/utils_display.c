/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:28:21 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:28:22 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_all *all, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(all->screen, x + i, y + j, all->minimap->color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_all *all, int cx, int cy, int radius)
{
	int	x;
	int	y;
	int	sqr_radius;
	int	color;

	color = PL_POS;
	x = -radius;
	sqr_radius = radius * radius;
	while (x <= radius)
	{
		y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= sqr_radius)
				put_pixel(all->screen, cx + x, cy + y, color);
			y++;
		}
		x++;
	}
}
